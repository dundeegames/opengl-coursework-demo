#include "scene3D.h"

bool Scene3D::CreatePixelFormat(HDC hdc) 
{ 
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    int pixelformat; 
 
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);	// Set the size of the structure
    pfd.nVersion = 1;							// Always set this to 1
	// Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;			// standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;				// RGB and Alpha pixel type
    pfd.cColorBits = COLOUR_DEPTH;				// Here we use our #define for the color bits
    pfd.cDepthBits = COLOUR_DEPTH;				// Ignored for RBA
    pfd.cAccumBits = 0;							// nothing for accumulation
    pfd.cStencilBits = 0;						// nothing for stencil
 
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

void Scene3D::InitializeOpenGL(int width, int height) 
{ 
	hdc = GetDC(*hwnd);//  sets  global HDC

    if (!CreatePixelFormat(hdc))//  sets  pixel format
        PostQuitMessage (0);


    hrc = wglCreateContext(hdc);	//  creates  rendering context from  hdc
    wglMakeCurrent(hdc, hrc);		//	Use this HRC.

	ResizeGLWindow(width, height);	// Setup the Screen
}



void Scene3D::Init(HWND* wnd, Input* in)
{
	hwnd = wnd;
	input = in;

	Xrotation = 0;
	Yrotation = 0;

	GetClientRect(*hwnd, &screenRect);	//get rect into our handy global rect
	InitializeOpenGL(screenRect.right, screenRect.bottom); // initialise openGL

	//OpenGL settings
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	//Also, do any other setting variables here for your app if you wish
	// Initialise other variables
	rotation = 0;
	rotation2 = 0;
	rotation3 = 0;
	speed = 15.0;
}

void Scene3D::DrawScene(float dt) 
{
	HandleInput(dt);

	int i=0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear The Screen And The Depth Buffer
	glLoadIdentity();// load Identity Matrix

	//set camera looking down the -z axis,  6 units away from the center
	//Where we are, What we look at, and which way is up
	gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0);


	// rotate matrix
		glTranslatef(-1.0f, 0.0f, 0.0f);
		//tilt our solar system slightly so it isn’t on the eye plane
		glRotatef(20, 1, 0, 0);
		glPushMatrix();	// Remember where we are.  THE SUN

			// render the sun
			glColor3f(1.0f, 0.9f, 0.0f);
			gluSphere(gluNewQuadric(), 0.40, 40,40);

			glPushMatrix();
				//render planet 1
				
				glRotatef(rotation,0,0.5,0.5);
				glTranslatef(1,0,0);
				glScalef(0.1, 0.1, 0.1);
				glColor3f(0.8f, 0.1f, 0.1f);
				gluSphere(gluNewQuadric(), 0.40, 40,40);
			glPopMatrix();//GO BACK TO SUN

			// Notice the indentation, this helps keep track of all the pushes and pops

			glPushMatrix(); // REMEMBER WHERE WE ARE
				// render planet 2
				glRotatef(rotation2,0,0,1);
				glTranslatef(1.5,0,0);
				glScalef(0.3, 0.3, 0.3);
				glColor3f(0.1f, 0.3f, 1.0f);
				gluSphere(gluNewQuadric(), 0.40, 40,40);
				glPushMatrix(); // REMEMBER WHERE WE ARE
					// Render a moon around planet 2
					glRotatef((rotation2*2.0),0,1,0);
					glTranslatef(1.5,0,0);
					glScalef(0.3, 0.3, 0.3);
					glColor3f(0.8f, 0.8f, 0.8f);
					gluSphere(gluNewQuadric(), 0.40, 40,40);
				glPopMatrix();
			glPopMatrix();//GO BACK TO SUN

			// going for a new planet and moons
			glPushMatrix(); // REMEMBER WHERE WE ARE
				// render planet 3
				glRotatef(rotation3,0,1,0);
				glTranslatef(3.5,0,0);
				glScalef(0.5, 0.5, 0.5);
				glColor3f(0.3f, 0.3f, 1.0f);
				gluSphere(gluNewQuadric(), 0.40, 40,40);
				glPushMatrix(); // REMEMBER WHERE WE ARE
					// Render a moon1 around planet 3
					glRotatef((rotation3*3.0),0,1,0);
					glTranslatef(1.5,0,0);
					glScalef(0.3, 0.3, 0.3);
					glColor3f(0.8f, 0.8f, 0.8f);
					gluSphere(gluNewQuadric(), 0.40, 40,40);
				glPopMatrix();	// GO BACK TO PLANET 3
				glPushMatrix(); // REMEMBER WHERE WE ARE
					// Render a moon2 around planet 3
					glRotatef((rotation3*(-5.0)),0,1,0);
					glTranslatef(2.5,0,0);
					glScalef(0.4, 0.4, 0.4);
					glColor3f(0.3f, 0.3f, 0.3f);
					gluSphere(gluNewQuadric(), 0.40, 40,40);
					glPushMatrix(); // REMEMBER WHERE WE ARE
						// Render a moon3 around moon2
						glRotatef((rotation3*12.0),0,1,0);
						glTranslatef(1.5,0,0);
						glScalef(0.4, 0.4, 0.4);
						glColor3f(0.5f, 1.0f, 0.5f);
						gluSphere(gluNewQuadric(), 0.40, 40,40);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();//GO BACK TO SUN

		glPopMatrix();

	// reset colour
	glColor3f(1.0f, 1.0f, 1.0f);


	// OLD CUBE and TRIANGELS ===================================================================
	/*
	//glScalef(2, 2, 1);
	//glTranslatef(-1, 0, 0);
	
	glRotatef(Yrotation, 0, 1, 0);
	//
	
	glBegin (GL_TRIANGLES);//Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-2.0, 2.0, 0.0);	
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-2.0, 1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 0, 2.0, 0.0);
				
	glEnd();//end drawing


	// Always load this code after translate, scale, rotate, etc----------------------------------------
	glLoadIdentity();// load Identity Matrix

	//set camera looking down the -z axis,  6 units away from the center
	gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up
	// -------------------------------------------------------------------------------------------------



	glScalef(0.5, 0.5, 1);


	glBegin (GL_TRIANGLES);//Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0, 2.0, 0.0);	
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0, 1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 3.0, 2.0, 0.0);
				
	glEnd();//end drawing


	// Always load this code after translate, scale, rotate, etc----------------------------------------
	glLoadIdentity();// load Identity Matrix

	//set camera looking down the -z axis,  6 units away from the center
	gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up
	// -------------------------------------------------------------------------------------------------

	glRotatef(Yrotation, 0, 1, 0);
	glRotatef(Xrotation, 1, 0, 0);
	

	glBegin(GL_QUADS);

		// front face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);

		// right face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glVertex3f(0.5f, -0.5f, 0.5f);

		// bottom face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);

	glEnd();

	
	// Always load this code after translate, scale, rotate, etc----------------------------------------
	glLoadIdentity();// load Identity Matrix

	//set camera looking down the -z axis,  6 units away from the center
	gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up
	// -------------------------------------------------------------------------------------------------
	*/


	/*
	glBegin (GL_TRIANGLE_STRIP);//Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0, 1.0, 0.0);	
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0, 0.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 1.0, 1.0, 0.0);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f( 1.0, 0.0, 0.0);

	glEnd();//end drawing
	*/
	/*
	glBegin (GL_TRIANGLE_FAN);//Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(3.0, 3.0, 0.0);	
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(3.0, 2.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 4.0, 1.5, 0.0);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f( 4.5, 2.5, 0.0);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f( 4.0, 3.5, 0.0);

	glEnd();//end drawing


	glBegin (GL_QUADS);//Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-3.0, -1.0, 0.0);	
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-3.0, -2.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( -1.5, -2.0, 0.0);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f( -1.5, -1.5, 0.0);

		//--------------------------

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f( 0.0, -2.5, 0.0);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f( 0.0, -3.5, 0.0);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f( 0.5, -3.5, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 0.5, -2.5, 0.0);


	glEnd();//end drawing


	glBegin (GL_POLYGON);//Begin drawing state

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(3.0, 0.0, 0.0);	
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(3.0, -1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 4.0, -2.5, 0.0);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f( 4.5, -1.5, 0.0);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f( 4.0, 0.5, 0.0);

	glEnd();//end drawing
	*/


	// ==========================================================================================

	SwapBuffers(hdc);// Swap the frame buffers.
}		

void Scene3D::Resize()
{
	if(hwnd == NULL)
		return;

	GetClientRect(*hwnd, &screenRect);	
	ResizeGLWindow(screenRect.right, screenRect.bottom);	
}


void Scene3D::HandleInput(float dt)
{
	rotation += (speed*3) * dt;
	rotation2 += (speed*2) * dt;
	rotation3 += speed * dt;


	if(input->isKeyDown('W'))									// if W is pressed
	{
		// makes the front face wireframe, not the back face
		glPolygonMode(GL_FRONT, GL_LINE);		
		input->SetKeyUp('W');									//force un-pressing of W
	}

	if(input->isKeyDown('E'))									// if E is pressed
	{
		//turns on normal filled rendering
		glPolygonMode(GL_FRONT, GL_FILL);
		input->SetKeyUp('E');									//force un-pressing of E
	}

	if(input->isKeyDown(VK_LEFT))									// if Left arrow key is pressed
	{
		// makes the front face wireframe, not the back face
		Yrotation -= 2;	
		input->SetKeyUp(VK_LEFT);									//force un-pressing of Left arrow key
	}

	if(input->isKeyDown(VK_RIGHT))									// if Right arrow key is pressed
	{
		// makes the front face wireframe, not the back face
		Yrotation += 2;			
		input->SetKeyUp(VK_RIGHT);									//force un-pressing of Right arrow key
	}

	if(input->isKeyDown(VK_UP))									// if Left arrow key is pressed
	{
		// makes the front face wireframe, not the back face
		Xrotation -= 2;	
		input->SetKeyUp(VK_UP);									//force un-pressing of Left arrow key
	}

	if(input->isKeyDown(VK_DOWN))									// if Right arrow key is pressed
	{
		// makes the front face wireframe, not the back face
		Xrotation += 2;			
		input->SetKeyUp(VK_DOWN);									//force un-pressing of Right arrow key
	}
}
