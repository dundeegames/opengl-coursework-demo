#include <system/scene3D.h>
#include <system/macros.h>


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
void Scene3D::resizeGLWindow(int width, int height)
{ 
  viewManager.setWindowSize( (float)width, (float)height);
  gui.setWindowSize( (float)width, (float)height);
}

// ------------------------------------------------------------------------------


// -----------------------------------------------------------------------------

void Scene3D::InitializeOpenGL(int width, int height) 
{ 
  hdc = GetDC(*hwnd);             //  sets  global HDC

    if (!CreatePixelFormat(hdc))  //  sets  pixel format
        PostQuitMessage (0);


    hrc = wglCreateContext(hdc);  //  creates  rendering context from  hdc
    wglMakeCurrent(hdc, hrc);     //  Use this HRC.

  resizeGLWindow(width, height);  // Setup the Screen
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
  glClearDepth(1.0f);                       // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);                  // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);                   // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // BMFont
  glAlphaFunc( GL_GREATER, 0 );             // set the alpha transparency
  glEnable( GL_ALPHA_TEST );                // and turn it on


  // Initialise other variables
  input->selectButton(SBTN1_SELECT);
  input->selectButton(VBTN2_4VIEW);
 
  gui.init(&resManager, input);
  viewManager.init(&resManager, input);


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
  box->setTexture(resManager.getTexture("crate.png") );
  
  Model triangle = modelGen.getTriangle();
  triangle.setPosition(Vec3(-0.5f, 0.0f, -1.0f));
  triangle.setRotation(Vec3(0.0f, -45.0f, 0.0f));
  triangle.setColour(1.0f, 0.0f, 0.0f, 1.0f);
  models.push_back(triangle);

  Model quad = modelGen.getQuad(1.5f, 0.75f);
  quad.setPosition(Vec3(-1.5f, 0.0f, -1.0f));
  quad.setRotation(Vec3(0.0f, -45.0f, 0.0f));
  models.push_back(quad);


  //Model plane = modelGen.getPlane(3.f, 1.5f, 10, 10);
  //plane.setPosition(Vec3(1.5f, 0.0f, 0.0f));
  //plane.setRotation(Vec3(0.0f, -90.0f, 0.0f));
  //models.push_back(plane);



} // end of Init

// ------------------------------------------------------------------------------

void Scene3D::DrawScene(float dt) 
{
  HandleInput(dt);
  gui.update();
  

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear The Screen And The Depth Buffer
  glLoadIdentity();       // load Identity Matrix


  viewManager.beginView(VIEWPORT_MAIN, true, false);

  //! Updating viewports
  for(int i = 1; i < MAX_VIEWPORTS; i++)
  {
    if(input->isViewportActive(i))
    {
      viewManager.beginView(i);
        render();                         // render all lighting, geometry, etc.
      viewManager.endView(i);

    }
  }

  viewManager.endView(VIEWPORT_MAIN);
    gui.renderMenu();

  SwapBuffers(hdc);       // Swap the frame buffers

}    

// -----------------------------------------------------------------------------

void Scene3D::Resize()
{
  if(hwnd == NULL)
    return;

  GetClientRect(*hwnd, &screenRect);  
  resizeGLWindow(screenRect.right, screenRect.bottom);

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

  //if(mouseCaptured)
  //{
  //  rotateCamera();
  //}


  solarSystem.update(dt);

  //robotArm.update(dt);

  viewManager.update(dt);


  if(input->isKeyDown(VK_MENU))             // if ALT is pressed
  {
    // for some reason it pause the rendering (but the variables still updates)
    input->SetKeyUp(VK_MENU);               //force un-pressing of ALT
  }

  if(input->isKeyDown('I'))                 // if L is pressed
  {
    // Load file
    insertFile();
    input->SetKeyUp('I');                   //force un-pressing of L
  }

  if(input->isKeyDown('L'))                 // if L is pressed
  {
    // Load file
    loadFile();
    input->SetKeyUp('L');                   //force un-pressing of L
  }



  if(input->isBottonSelected(TBTN1_SPHERE))
  {
    // generate model
    Model cSphere = modelGen.getCubeSPhere(1.0f, 5);
    models.push_back(cSphere);
    input->unselectButton(TBTN1_SPHERE);
  }

  if(input->isBottonSelected(TBTN2_CUBE))
  {
    // generate model
    Model cube = modelGen.getCube(2.0f, 2.0f, 2.0f, 7, 5, 3);
    models.push_back(cube);
    input->unselectButton(TBTN2_CUBE);
  }

  if(input->isBottonSelected(TBTN3_CYLINDER))
  {
    // generate model
    input->unselectButton(TBTN3_CYLINDER);
  }

  if(input->isBottonSelected(TBTN4_CONE))
  {
    // generate model
    input->unselectButton(TBTN4_CONE);
  }

  if(input->isBottonSelected(TBTN5_PLANE))
  {
    // generate model
    Model plane = modelGen.getPlane(3.f, 1.5f, 10, 10);
    plane.setPosition(Vec3(1.5f, 0.0f, 0.0f));
    plane.setRotation(Vec3(0.0f, -90.0f, 0.0f));
    models.push_back(plane);
    
    input->unselectButton(TBTN5_PLANE);
  }

  if(input->isBottonSelected(TBTN6_TORUS))
  {
    // generate model
    input->unselectButton(TBTN6_TORUS);
  }

  if(input->isBottonSelected(TBTN7_PYRAMID))
  {
    // generate model
    input->unselectButton(TBTN7_PYRAMID);
  }

  if(input->isBottonSelected(TBTN8_PIPE))
  {
    // generate model
    input->unselectButton(TBTN8_PIPE);
  }




}// end of HandleInput

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
    Model* tempModel = resManager.getModel(ofn.lpstrFile, false);

    if(tempModel != NULL)
    {
      models.push_back(*tempModel);
    }
    else
    {
      // report an error
      MessageBox(*hwnd, "File did not open!", "Error", MB_OK | MB_ICONERROR);      
    }    
  }

}

// -----------------------------------------------------------------------------

void Scene3D::insertFile()
{
  // Do something usefull with the filename stored in szFileName
  Model* tempModel = resManager.getModel("Prince.obj");

  if(tempModel != NULL)
  {
    //tempModel->setColour(1.0f, 0.0f, 0.0f, 1.0f);
    models.push_back(*tempModel);
  }
  else
  {
    // report an error
    MessageBox(*hwnd, "File did not open!", "Error", MB_OK | MB_ICONERROR);      
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
    box->draw();
    //robotArm.render();
  
  glPopMatrix();    // go back to origin

  glPushMatrix();   // Remember where we are.

    for(std::vector<Model>::iterator it = models.begin(); it != models.end(); it++)
    {
      //glTranslatef(0.2f, 0.0f, 2.0f);
      it->Render();
    }

  glPopMatrix();    // go back to origin

}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////