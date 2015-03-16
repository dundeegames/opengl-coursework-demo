#include <ui/viewport.h>

Viewport::Viewport()
{

}


Viewport::~Viewport()
{

}

// -----------------------------------------------------------------------------

void Viewport::init(CameraType type, Input* in)
{
  camera.init(type, in);

}

// -----------------------------------------------------------------------------

void Viewport::setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_)
{
  x = x_;
  y = y_;
  width = w_;
  height = h_;

  left = (float)x;
  right = (float)(x + width);
  top = (float)y;
  bottom = (float)(y + height);

}

// -----------------------------------------------------------------------------

void Viewport::update(float dt)
{
  camera.update(dt);

}

// -----------------------------------------------------------------------------

void Viewport::begin()
{
  //set viewport
  if (height==0)  // Prevent A Divide By Zero error
  {
    height=1;     // Make the Height Equal One
  }

  glViewport(x, y, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //calculate aspect ratio
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 1 ,150.0f);

  glMatrixMode(GL_MODELVIEW);       // Select The Modelview Matrix
  glLoadIdentity();                 // Reset The Modelview Matrix



  drawBackground();

  camera.view();

}

// -----------------------------------------------------------------------------

void Viewport::end()
{
  //glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT  | GL_ENABLE_BIT | GL_TRANSFORM_BIT);  
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  glOrtho(left, right, bottom, top, 1.0f ,150.0f);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();             // Reset The Modelview Matrix

  //set camera looking down the -z axis,  6 units away from the center
  gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up

  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);


  //glPopAttrib();

}

// -----------------------------------------------------------------------------

void Viewport::drawBackground()
{
  float z = 0.0f; // for debugging purposes
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //gluOrtho2D(left, right, bottom, top);
  glOrtho(left, right, bottom, top, 1 ,150.0f);

  glMatrixMode(GL_MODELVIEW);   // Select The Modelview Matrix
  glLoadIdentity();             // Reset The Modelview Matrix

  

  //set camera looking down the -z axis,  6 units away from the center
  gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up

  glBegin(GL_TRIANGLES);

    glColor3f(0.533f, 0.615f, 0.698f);  // Top colour of gradient
      glVertex3f(right, top, z);
      glVertex3f(left, top, z);

    glColor3f(0.07f, 0.07f, 0.07f);     // Bottom colour of gradient
      glVertex3f(left, bottom, z);
      glVertex3f(left, bottom, z);
      glVertex3f(right, bottom, z);

    glColor3f(0.533f, 0.615f, 0.698f);  // Top colour of gradient
      glVertex3f(right, top, z);

    glColor3f(1.0f, 1.0f, 1.0f);        // reset colour

  glEnd();


 // glPopAttrib();


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //calculate aspect ratio
  gluPerspective(45.0f,(GLfloat)(right/bottom), 1 ,150.0f);

  glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
  glLoadIdentity();// Reset The Modelview Matrix

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);


}


// 80 //////////////////////////////////////////////////////////////////////////