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

  //left = (GLdouble)x;
  //right = (GLdouble)(x + width);
  //top = (GLdouble)(y + height);
  //bottom = (GLdouble)y;

  //left = (GLdouble)x;
  //right = (GLdouble)(x + width);
  //top = (GLdouble)y;
  //bottom = (GLdouble)(y + height);

  left = 0.0;
  right = (GLdouble)width;
  top = 0.0;
  bottom = (GLdouble)height;



  //left = -(GLdouble)width / 2.0;
  //right = (GLdouble)width / 2.0;
  //top = (GLdouble)height / 2.0;
  //bottom = -(GLdouble)height / 2.0;

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
      glVertex3f( (GLfloat)right, (GLfloat)top, z);
      glVertex3f( (GLfloat)left, (GLfloat)top, z);

    glColor3f(0.07f, 0.07f, 0.07f);     // Bottom colour of gradient
      glVertex3f( (GLfloat)left, (GLfloat)bottom, z);
      glVertex3f( (GLfloat)left, (GLfloat)bottom, z);
      glVertex3f( (GLfloat)right, (GLfloat)bottom, z);

    glColor3f(0.533f, 0.615f, 0.698f);  // Top colour of gradient
      glVertex3f( (GLfloat)right, (GLfloat)top, z);

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
  
  glOrtho(left, right, bottom, top, 1.0 ,150.0);
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