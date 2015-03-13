#include <ui/viewport.h>

Viewport::Viewport()
{

}


Viewport::~Viewport()
{

}

// -----------------------------------------------------------------------------

void Viewport::init(CameraType type, Input* in, Gui* gui_)
{
  camera.init(type, in);

  gui = gui_;

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



  gui->drawBackground(left, right, bottom, top);

  camera.view();

}

// -----------------------------------------------------------------------------

void Viewport::end()
{
  glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT  | GL_ENABLE_BIT | GL_TRANSFORM_BIT);  
  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();


  glOrtho(left, right, bottom, top, 1.0f ,150.0f);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();             // Reset The Modelview Matrix


  //set camera looking down the -z axis,  6 units away from the center
  gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up


  gui->renderText();



  glPopAttrib();

}

// -----------------------------------------------------------------------------




// 80 //////////////////////////////////////////////////////////////////////////