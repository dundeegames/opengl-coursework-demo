#include <system/scene3D.h>
#include <system/macros.h>

GLfloat def_mat_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat def_mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat def_mat_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat def_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat no_mat[] = {0.0f, 0.0f, 0.0f, 0.0f};
GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat mat_ambient_colour[] = {0.8f, 0.8f, 0.2f, 1.0f};

GLfloat mat_diffuse[] = {0.1f, 0.5f, 0.8f, 1.0f};
GLfloat mat_dif_red[] = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat mat_dif_blueAlpha[] = {0.0f, 0.0f, 0.8f, 0.5f};


GLfloat mat_hight_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};



GLfloat no_shininess[] = {0.0f};
GLfloat low_shininess[] = {50};
GLfloat high_shininess[] = {100};
GLfloat mat_emission[] = {0.3f, 0.2f, 0.2f, 0.0f};

GLfloat Light_Ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};
GLfloat Light_Diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat Light_Specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat Light_Position[]= {-100.0f, 100.0f, 100.0f, 1.0f};

GLfloat Light_Ambient2[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat Light_Diffuse2[] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat Light_Specular2[] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat Light_Position2[]= {-100.0f, 100.0f, 100.0f, 1.0f};



GLfloat gold_mat_ambient[] = {MAT_GOLD_AMBIENT};
GLfloat gold_mat_diffuse[] = {MAT_GOLD_DIFFUSE};
GLfloat gold_mat_specular[] = {MAT_GOLD_SPECULAR};
GLfloat gold_mat_shininess[] = {MAT_GOLD_SHININESS};




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
  glEnable(GL_NORMALIZE);

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
  

  // Do something usefull with the filename stored in szFileName
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

  terrain.update(-0.1f*dt);
  robotArm.update(dt);

  viewManager.update(dt);


  if(input->isKeyDown(VK_MENU))             // if ALT is pressed
  {
    // for some reason it pause the rendering (but the variables still updates)
    input->SetKeyUp(VK_MENU);               //force un-pressing of ALT
  }

  if(input->isKeyDown('T'))                 // if L is pressed
  {
    // Load file
    insertFile();
    input->SetKeyUp('T');                   //force un-pressing of L
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
  //glDisable(GL_LIGHTING);

  ambient->render();
  direct->render();
  spot1->render();
  spot2->render();


  glPushAttrib(GL_CURRENT_BIT | GL_LIGHTING_BIT);
  //glPushAttrib(GL_LIGHTING_BIT);
    glPushMatrix();
	    glTranslatef(-4.0f, 0.0f, 0.0f);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	    gluSphere(gluNewQuadric(), 0.75, 40,40);
    glPopMatrix();
  glPopAttrib();

  glPushAttrib(GL_CURRENT_BIT | GL_LIGHTING_BIT);
  //glPushAttrib(GL_LIGHTING_BIT);
    glPushMatrix();
	    glTranslatef(-2.0f, 0.0f, 0.0f);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_hight_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
      glColor3f(0.8f, 0.0f, 0.0f);
	    gluSphere(gluNewQuadric(), 0.75, 40,40);
      //glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();
  glPopAttrib();

  glPushAttrib(GL_CURRENT_BIT | GL_LIGHTING_BIT | GL_ENABLE_BIT);
  //glPushAttrib(GL_LIGHTING_BIT);
  glEnable(GL_BLEND);
    glPushMatrix();
	    glTranslatef(-2.0f, 0.0f, 2.0f);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_hight_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
      glColor4f(0.0f, 0.5f, 0.0f, 0.5f);
	    gluSphere(gluNewQuadric(), 0.75, 40,40);
      //glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();
  glPopAttrib();

  glPushAttrib(GL_CURRENT_BIT | GL_LIGHTING_BIT | GL_ENABLE_BIT);
  //glPushAttrib(GL_LIGHTING_BIT);
  glEnable(GL_BLEND);
    glPushMatrix();
	    glTranslatef(0.0f, 0.0f, 0.0f);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_dif_red);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_red);
	    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
      //glColor3f(0.8f, 0.0f, 0.0f);
	    gluSphere(gluNewQuadric(), 0.75, 40,40);
      //glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();
  glPopAttrib();
 
  glPushAttrib(GL_CURRENT_BIT | GL_LIGHTING_BIT | GL_ENABLE_BIT);
  //glPushAttrib(GL_LIGHTING_BIT);
  glEnable(GL_BLEND);

  //glBindTexture(GL_TEXTURE_2D, resManager.getTexture("PortalTexture.png"));  //texture to use

    glPushMatrix();
	    glTranslatef(-2.0f, 0.0f, -2.0f);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, def_mat_ambient);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, def_mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_SPECULAR, def_mat_specular);
	    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	    glMaterialfv(GL_FRONT, GL_EMISSION, def_mat_emission);
      //glColor3f(0.8f, 0.0f, 0.0f);
	    gluSphere(gluNewQuadric(), 0.75, 40,40);
      //glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();
  //glBindTexture(GL_TEXTURE_2D, NULL);

  glPopAttrib();

  gui.drawGrid();
 


  glPushMatrix();   // Remember where we are.

    robotArm.render();

  glPopMatrix();    // go back to origin


  glPushMatrix();
	  //glTranslatef(2.0f, 0.0f, 0.0f);
    for(std::vector<Model>::iterator it = models.begin(); it != models.end(); it++)
    {
      it->Render();
    }

  glPopMatrix();    // go back to origin

  glPushMatrix();   // Remember where we are.

    terrain.render();

  glPopMatrix();    // go back to origin



}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////