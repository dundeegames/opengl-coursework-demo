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

void Viewport::begin(bool perspective)
{
  //set viewport
  if (height==0)  // Prevent A Divide By Zero error
  {
    height=1;     // Make the Height Equal One
  }

  glViewport(x, y, width, height);

  orthographicView();
  drawBackground();


  if(perspective)
  {
    perspectiveView();
  }

  camera.view();

}

// -----------------------------------------------------------------------------

void Viewport::end()
{
  //set viewport
  if (height==0)  // Prevent A Divide By Zero error
  {
    height=1;     // Make the Height Equal One
  }

  // COMMENT THIS LINE TO SHOW BUG!
  glViewport(x, y, width, height);
  
  
  orthographicView();
  
}

// -----------------------------------------------------------------------------

void Viewport::drawBackground()
{
  float z = 0.0f; // for debugging purposes
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);

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

  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

}

// -----------------------------------------------------------------------------

void Viewport::orthographicView()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //gluOrtho2D(left, right, bottom, top);
  
  glOrtho((GLdouble)left, (GLdouble)right, (GLdouble)bottom, (GLdouble)top, 1.0 ,150.0);
  //glOrtho(0.0, (GLdouble)right, (GLdouble)bottom, 0.0, 1.0 ,150.0);
  //glOrtho((GLdouble)left, (GLdouble)right, (GLdouble)top, (GLdouble)bottom, 1.0 ,150.0);
  //glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);

  glMatrixMode(GL_MODELVIEW);   // Select The Modelview Matrix
  glLoadIdentity();             // Reset The Modelview Matrix
  

  //set camera looking down the -z axis,  6 units away from the center
  gluLookAt(0.0, 0.0, 10.0,     0.0, 0.0, 0.0,     0.0, 1.0, 0.0); //Where we are, What we look at, and which way is up


}

// -----------------------------------------------------------------------------

void Viewport::perspectiveView()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //calculate aspect ratio
  //glFrustum((GLdouble)left, (GLdouble)right, (GLdouble)bottom, (GLdouble)top, 1.0 ,150.0);
  gluPerspective(45.0, (GLdouble)width/(GLdouble)height, 1.0 ,150.0);

  glMatrixMode(GL_MODELVIEW);       // Select The Modelview Matrix
  glLoadIdentity();                 // Reset The Modelview Matrix

}

// -----------------------------------------------------------------------------









// 80 //////////////////////////////////////////////////////////////////////////