#include "scene3D.h"


// ------------------------------------------------------------------------------

bool Scene3D::CreatePixelFormat(HDC hdc) 
{ 
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    int pixelformat; 
 
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);  // Set the size of the structure
    pfd.nVersion = 1;                           // Always set this to 1
    // Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;   // standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;     // RGB and Alpha pixel type
    pfd.cColorBits = COLOUR_DEPTH;      // Here we use our #define for the color bits
    pfd.cDepthBits = COLOUR_DEPTH;      // Ignored for RBA
    pfd.cAccumBits = 0;                 // nothing for accumulation
    pfd.cStencilBits = 0;               // nothing for stencil
 
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

/*!
* Initialize The GL Window
*/
void Scene3D::ResizeGLWindow(int width, int height)
{
  viewport1.setSize(0, 0, width, height);

}

// ------------------------------------------------------------------------------

void Scene3D::InitializeOpenGL(int width, int height) 
{ 
  hdc = GetDC(*hwnd);             //  sets  global HDC

    if (!CreatePixelFormat(hdc))  //  sets  pixel format
        PostQuitMessage (0);


    hrc = wglCreateContext(hdc);  //  creates  rendering context from  hdc
    wglMakeCurrent(hdc, hrc);     //  Use this HRC.

  ResizeGLWindow(width, height);  // Setup the Screen
}

// -----------------------------------------------------------------------------

void Scene3D::Init(HWND* wnd, Input* in)
{
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
  
  //glShadeModel(GL_FLAT);                  // Enable Flat Shading
  glShadeModel(GL_SMOOTH);                  // Enable Smooth Shading
  //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // Black(Transparent) Background
  //glClearColor(0.5f, 0.5f, 0.5f, 1.0f);   // Gray Background
  glClearDepth(1.0f);                     // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);                // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);                 // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


  // BMFont
  glAlphaFunc( GL_GREATER, 0 );              // set the alpha transparency
  glEnable( GL_ALPHA_TEST );                // and turn it on


  //Also, do any other setting variables here for your app if you wish
  // Initialise other variables
 
  gui.init();
  viewport1.init(FIXED_POINT, in, &gui);


  ambient = new Light(GL_LIGHT0);
  light1 = new Light(GL_LIGHT1);

  //init(LIGHT_TYPE  postionXYZT  colourRGBA)
  //T is type of light: 0.0 = ..., 1.0 = ...
  ambient->init(AMBIENT, 0.0f, 0.0f, 0.0f, 0.0f, 0.3f, 0.3f, 0.3f, 1.0f);
  light1->init(DIFFUSE, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f);

  //robotArm.Init(in);
  solarSystem.init();


  //box1.init();
  box = new Cube();
  box->loadTexture("bin/crate.png");
  quad = new Sprite();
  triangle = new Triangle();
  triangle->setColor3f(255.0, 0.0, 0.0);

} // end of Init

// ------------------------------------------------------------------------------

void Scene3D::DrawScene(float dt) 
{
  HandleInput(dt);
  
  

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear The Screen And The Depth Buffer
  glLoadIdentity();       // load Identity Matrix


  viewport1.begin();

    render(); // render all lighting, geometry, etc.

  viewport1.end();

  SwapBuffers(hdc);       // Swap the frame buffers

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
    //captureMouse();
  }
  else if(input->isKeyDown(VK_CONTROL))
  {
    //releaseMouse();
  }

  if(mouseCaptured)
  {
    rotateCamera();
  }


  solarSystem.update(dt);

  //robotArm.update(dt);

  //camera.update(dt);
  viewport1.update(dt);


  if(input->isKeyDown('4'))                 // if 4 is pressed
  {
    // makes the front face wireframe, not the back face
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    
    input->SetKeyUp('4');                   //force un-pressing of 4
  }

  if(input->isKeyDown('5'))                 // if 5 is pressed
  {
    //turns on normal filled rendering
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    input->SetKeyUp('5');                   //force un-pressing of 5
  }

  if(input->isKeyDown(VK_MENU))             // if ALT is pressed
  {
    // for some reason it pause the rendering (but the variables still updates)
    input->SetKeyUp(VK_MENU);               //force un-pressing of ALT
  }

  if(input->isKeyDown('L'))                 // if L is pressed
  {
    // Load file
    loadFile();
    input->SetKeyUp('L');                   //force un-pressing of L
  }

}// end of HandleInput

// -----------------------------------------------------------------------------

void Scene3D::captureMouse()
{
  mouseCaptured = true;
  ShowCursor(FALSE);

  center.X = (SHORT)(screenRect.right / 2);
  center.Y = (SHORT)(screenRect.bottom / 2);

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

// ------------------------------------------------------------------------------

void Scene3D::loadFile()
{
  OPENFILENAME ofn;

  char szFileName[MAX_PATH] = "";

  ZeroMemory(&ofn, sizeof(ofn));

  ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
  ofn.hwndOwner = *hwnd;
  //ofn.lpstrFilter = "Obj Files (*.obj)\0*.txt\0All Files (*.*)\0*.*\0";
  ofn.lpstrFile = szFileName;
  ofn.nMaxFile = MAX_PATH;
  ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
  ofn.lpstrDefExt = "obj";

  if(GetOpenFileName(&ofn))
  {
    // Do something usefull with the filename stored in szFileName
    Model tempModel;

    if( tempModel.LoadModel(ofn.lpstrFile) == true)
    {
      //MessageBox(*hwnd, "File open!", "Success", MB_OK | MB_ICONINFORMATION);
      models.push_back(tempModel);
    }
    else
    {
      MessageBox(*hwnd, "File did not open!", "Error", MB_OK | MB_ICONERROR);
    }



    
  }

}

// -----------------------------------------------------------------------------

void Scene3D::render()
{
  ambient->render();
  light1->render();

  gui.drawGrid();

  

  glPushMatrix();   // Remember where we are.

    solarSystem.render();

  glPopMatrix();    // go back to origin
  glPushMatrix();   // Remember where we are.

    //based on shoulder
    glTranslatef(3.0f, 0.0f, 0.0f);
    //box1.render();
    box->draw();
    //robotArm.render();
  
  glPopMatrix();    // go back to origin
  glPushMatrix();   // Remember where we are.

    glTranslatef(-3.0f, 0.0f, 0.0f);
    quad->draw();

  glPopMatrix();    // go back to origin
  glPushMatrix();   // Remember where we are.

    triangle->draw();

  glPopMatrix();    // go back to origin
  glPushMatrix();   // Remember where we are.

    glScalef(0.1, 0.1, 0.1);

    for(std::vector<Model>::iterator it = models.begin(); it != models.end(); it++)
    {
      glTranslatef(2.0f, 0.0f, 10.0f);
      it->Render();
    }

  glPopMatrix();    // go back to origin

}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////