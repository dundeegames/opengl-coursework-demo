////////////////////////////////////////////////////////////////////////////////
/**
* \file       scene3D.cpp
* \brief      Scene3D class - AG0800A Graphics Programming
*
* \details    Handles the size of the scene and all main assets
*
* \author     Jiri Klic
* \version    1.0
* \date       January 2015
* \pre        Init(HWND*, Input*) needs to be called prior to use
* \post       
* \bug        No known bugs
* \warning    <windows.h> needs to be included BEFORE <gl/gl.h> & <gl/glu.h>
* \todo       move Material loading and management to Resource manager
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <system/scene3D.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////

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

// -----------------------------------------------------------------------------

/*!
* Initialize The GL Window
*/
void Scene3D::resizeGLWindow(int width, int height)
{ 
  viewManager.setWindowSize( (float)width, (float)height);
  gui.setWindowSize( (float)width, (float)height);
}

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

/**
* \brief      Short description
*
* \details    anything tricky about how a function does its job,
*             give an overview of the steps you go through,
*             or explain why you chose to implement the function in the way
*             you did rather than using a viable alternative.
*             Do not just repeat the comments given with the function
*             declaration, in the .h file or wherever.
*             It's okay to recapitulate briefly what the function does,
*             but the focus of the comments should be on how it does it.
*
*/
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
  glEnable(GL_NORMALIZE);

  /*!
  * Specify texture calculation
  */
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
  //glShadeModel(GL_FLAT);                  // Enable Flat Shading
  glShadeModel(GL_SMOOTH);                  // Enable Smooth Shading


  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     // Black(Transparent) Background
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
  ambient->init(L_AMBIENT, COLOUR_DRKGRAY, 0.0f, 0.0f, 0.0f, 0.0f);

  direct = new Light(GL_LIGHT1);
  direct->init(L_DIRECTIONAL, COLOUR_LTGRAY, 1.0f, -1.0f, 1.0f, -1.0f);

  spot1 = new Light(GL_LIGHT2);
  spot1->init(L_SPOT, COLOUR_DRKBLUE, 1.0f, 3.9f, 2.2f, 0.1f,
                                            0.0f, -1.0f, 0.0f, 25.0, 15.0f);
  spot1->setActive(true);


  spot2 = new Light(GL_LIGHT3);
  spot2->init(L_SPOT, COLOUR_DRKBLUE, 1.0f, 2.1f, 2.2f, 0.1f,
                                            0.0f, -1.0f, 0.0f, 25.0, 15.0f);
  spot2->setActive(true);


  Planets* orbits = new Planets();
  orbits->init(input);
  robotArm.Init(input, &modelGen, orbits);
  
  //TODO: move loading to Resource manager
  Material* terMat = new Material();
  Material* seaMat = new Material(COLOUR_WHITE, 0.7f);

  terMat->setDiffuse(COLOUR_WHITE, 1.0f);
  terMat->setTexture(resManager.getTexture("Tamriel_Dif.png"));
  seaMat->setDiffuse(COLOUR_WHITE, 0.7f);
  seaMat->setTexture(resManager.getTexture("sea.png"));

  terrain.init("../../media/images/Tamriel.png", &modelGen);
  terrain.setScale(Vec3(40.0f, 1.0f, 40.0f));
  terrain.setMaterial(terMat);
  terrain.setSeaMaterial(seaMat);
  terrain.setSeaTiling(4.0f, 4.0f);



  Model crate = modelGen.getCube(1.0f, 1.0f, 1.0f, 7, 5, 3);
  Material* crateMat = new Material();
  crateMat->setTexture(resManager.getTexture("PortalTexture.png") );  
  crate.setMaterial(crateMat);
  crate.setPosition(Vec3(3.0f, 0.25f, 0.0f));
  models.push_back(crate);
  

  Model* prince = resManager.getModel("Prince.obj");
  
  if(prince != NULL)
  {
    prince->setPosition(Vec3(3.0f, 0.75f, 0.0f));

    Material* princeMat = new Material();
    princeMat->setTexture(resManager.getTexture("graymarble256px.png") );
    prince->setMaterial(princeMat);

    prince->setTiling(2.0f, 2.0f);
    models.push_back(*prince);
  }



} // end of Init

// -----------------------------------------------------------------------------

void Scene3D::DrawScene(float dt) 
{
  HandleInput(dt);
  gui.update();
  

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///< Clear The Screen And The Depth Buffer
  glLoadIdentity();                                   ///< load Identity Matrix


  viewManager.beginView(VIEWPORT_MAIN, true, false);

  ///< Updating viewports
  for(int i = 1; i < MAX_VIEWPORTS; i++)
  {
    if(input->isViewportActive(i))
    {
      viewManager.beginView(i);
        render();                         ///< render all lighting, geometry, etc.
      viewManager.endView(i);

    }
  }

  viewManager.endView(VIEWPORT_MAIN);
    gui.renderMenu();

  SwapBuffers(hdc);                       ///< Swap the frame buffers

}    

// -----------------------------------------------------------------------------

void Scene3D::Resize()
{
  if(hwnd == NULL)
    return;

  GetClientRect(*hwnd, &screenRect);  
  resizeGLWindow(screenRect.right, screenRect.bottom);

}

// -----------------------------------------------------------------------------

void Scene3D::HandleInput(float dt)
{

  terrain.update(-0.1f*dt);
  robotArm.update(dt);

  viewManager.update(dt);


  if(input->isKeyDown('T'))                 // if T is pressed
  {
    // Load file
    insertFile();
    input->SetKeyUp('T');                   //force un-pressing of T
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
    Model cylinder = modelGen.getCylinder(0.5f, 1.5f, 16, 4);
    models.push_back(cylinder);
    input->unselectButton(TBTN3_CYLINDER);
  }

  if(input->isBottonSelected(TBTN4_CONE))
  {
    // generate model
    Model cone = modelGen.getCone(1.0f, 2.0f, 16);
    models.push_back(cone);
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

  ///< Toggle Ambient and Directional Light On/Off
  if(input->isBottonSelected(LBTN1_L_AMBIENT))
  {
    ambient->setActive(true);
  }
  else
  {
    ambient->setActive(false);
  }

  if(input->isBottonSelected(LBTN2_L_DIRECT))
  {
    direct->setActive(true);
  }
  else
  {
    direct->setActive(false);
  }

  ///< Show/Hide Light handles
  if(input->isBottonSelected(LBTN3_L_HANDLE))
  {
    ambient->showHandle(true);
    direct->showHandle(true);
    spot1->showHandle(true);
    spot2->showHandle(true);
  }
  else
  {
    ambient->showHandle(false);
    direct->showHandle(false);
    spot1->showHandle(false);
    spot2->showHandle(false);
  }



}// end of HandleInput

// -----------------------------------------------------------------------------

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
    // use filename stored in szFileName
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
  Model* tempModel = resManager.getModel("Prince.obj");

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

// -----------------------------------------------------------------------------

void Scene3D::render()
{
  ambient->render();
  direct->render();
  spot1->render();
  spot2->render();


  gui.drawGrid();   ///< draw the line grid in viewport


  glPushMatrix();   // Remember where we are
    for(std::vector<Model>::iterator it = models.begin(); it != models.end(); it++)
    {
      it->Render();
    }
  glPopMatrix();    // go back to origin


  glPushMatrix();   // Remember where we are

    robotArm.render();

  glPopMatrix();    // go back to origin


  glPushMatrix();   // Remember where we are

    terrain.render();

  glPopMatrix();    // go back to origin



}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////