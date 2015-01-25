#include "scene3D.h"


// ------------------------------------------------------------------------------

bool Scene3D::CreatePixelFormat(HDC hdc) 
{ 
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    int pixelformat; 
 
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);  // Set the size of the structure
    pfd.nVersion = 1;              // Always set this to 1
  // Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;      // standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;        // RGB and Alpha pixel type
    pfd.cColorBits = COLOUR_DEPTH;        // Here we use our #define for the color bits
    pfd.cDepthBits = COLOUR_DEPTH;        // Ignored for RBA
    pfd.cAccumBits = 0;              // nothing for accumulation
    pfd.cStencilBits = 0;            // nothing for stencil
 
  //Gets a best match on the pixel format as passed in from device
    if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == false ) 
    { 
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
  //sets the pixel format if its ok. 
    if (SetPixelFormat(hdc, pixelformat, &pfd) == false) 
    { 
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
    return true;
}

// ------------------------------------------------------------------------------

void Scene3D::ResizeGLWindow(int width, int height)// Initialize The GL Window
{
  if (height==0)// Prevent A Divide By Zero error
  {
    height=1;// Make the Height Equal One
  }

  glViewport(0,0,width,height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //calculate aspect ratio
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 1 ,150.0f);

  glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
  glLoadIdentity();// Reset The Modelview Matrix
}

// ------------------------------------------------------------------------------

void Scene3D::InitializeOpenGL(int width, int height) 
{ 
  hdc = GetDC(*hwnd);//  sets  global HDC

    if (!CreatePixelFormat(hdc))//  sets  pixel format
        PostQuitMessage (0);


    hrc = wglCreateContext(hdc);  //  creates  rendering context from  hdc
    wglMakeCurrent(hdc, hrc);    //  Use this HRC.

  ResizeGLWindow(width, height);  // Setup the Screen
}

// ------------------------------------------------------------------------------

void Scene3D::Init(HWND* wnd, Input* in)
{
  // init camera values
  camera.init(FIXED_POINT, in);

  //camera.theta = 0.0;
  //camera.phi = 0.0;
  //camera.distance = 10.0;
  //camera.x = 0.0;
  //camera.y = 0.0;
  //camera.z = 10.0;


  hwnd = wnd;
  input = in;

  GetClientRect(*hwnd, &screenRect);  //get rect into our handy global rect
  InitializeOpenGL(screenRect.right, screenRect.bottom); // initialise openGL

  //OpenGL settings
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);


  /*!
  * Specify texture calculation
  */
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


  glShadeModel(GL_FLAT);                  // Enable Smooth Shading
  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);   // Black Background
  glClearDepth(1.0f);                     // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);                // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);                 // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations

  //Also, do any other setting variables here for your app if you wish
  // Initialise other variables
  

  light1 = new Light(GL_LIGHT0);

  //init(ambientRGBA  difuseRGBA  postionXYZT)
  //T is type of light: 0.0 = ..., 1.0 = ...
  light1->init(0.3f, 0.3f, 0.3f, 1.0f,     1.0f, 0.0f, 1.0f, 1.0f,     -1.0f, 0.0f, 0.0f, 0.0f);

  robotArm.Init(in);
  solarSystem.init();
  box1.init();


} // end of Init

// ------------------------------------------------------------------------------

void Scene3D::DrawScene(float dt) 
{
  HandleInput(dt);

  int i=0;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear The Screen And The Depth Buffer
  glLoadIdentity();// load Identity Matrix

  /*!
  * set camera looking down the -z axis,  6 units away from the center
  * Where we are, What we look at, and which way is up
  */
  //gluLookAt(camera.x, camera.y, camera.z,     0, 0, 0,     0, 1, 0);

  //gluLookAt(camera.posX(),  camera.posY(),  camera.posZ(),
  //          camera.lookX(), camera.lookY(), camera.lookZ(),
  //          camera.upX(),   camera.upY(),   camera.upZ() );
  
  camera.view();

  light1->render();

  glPushMatrix();   // Remember where we are.

    solarSystem.render();

  glPopMatrix();    // go back to origin
  glPushMatrix();   // Remember where we are.

    //based on shoulder
    glTranslatef(3.0f, 0.0f, 0.0f);
    box1.render();  
    //robotArm.render();
  
  glPopMatrix();    // go back to origin

  // ----------------------------------------

  SwapBuffers(hdc); // Swap the frame buffers

}    

// -----------------------------------------------------------------------------

void Scene3D::Resize()
{
  if(hwnd == NULL)
    return;

  GetClientRect(*hwnd, &screenRect);  
  ResizeGLWindow(screenRect.right, screenRect.bottom);

}

// ------------------------------------------------------------------------------

void Scene3D::HandleInput(float dt)
{

  if(input->leftMouseBtn())
  {
    captureMouse();
  }
  else if(input->isKeyDown(VK_CONTROL))
  {
    releaseMouse();
  }

  if(mouseCaptured)
  {
    rotateCamera();
  }



  solarSystem.update(dt);

  //robotArm.update(dt);

  camera.update(dt);


  if(input->isKeyDown('4'))                  // if W is pressed
  {
    // makes the front face wireframe, not the back face
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    
    input->SetKeyUp('4');                  //force un-pressing of W
  }

  if(input->isKeyDown('5'))                  // if E is pressed
  {
    //turns on normal filled rendering
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    input->SetKeyUp('5');                  //force un-pressing of E
  }

  if(input->isKeyDown(VK_MENU))                // if ALT is pressed
  {
    // for some reason it pause the rendering (but the variables still updates)
    input->SetKeyUp(VK_MENU);                //force un-pressing of ALT
  }


}// end of HandleInput

// -----------------------------------------------------------------------------

void Scene3D::captureMouse()
{
  mouseCaptured = true;
  ShowCursor(FALSE);

  center.X = screenRect.right / 2;
  center.Y = screenRect.bottom / 2;

}

// -----------------------------------------------------------------------------

void Scene3D::releaseMouse()
{
  mouseCaptured = false;
  ShowCursor(TRUE);
}

// -----------------------------------------------------------------------------

void Scene3D::rotateCamera()
{
  int deltaX = input->getMouseX() - center.X;
  int deltaY = input->getMouseY() - center.Y;



}
