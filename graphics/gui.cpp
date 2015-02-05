#include "gui.h"


Gui::Gui()
{

}


Gui::~Gui()
{

}


// -----------------------------------------------------------------------------

void Gui::drawBackground(float left, float right, float bottom, float top)
{
  // TODO Ask for the feedback on this func()


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

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //calculate aspect ratio
  gluPerspective(45.0f,(GLfloat)(right/bottom), 1 ,150.0f);

  glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
  glLoadIdentity();// Reset The Modelview Matrix

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);


}

// -----------------------------------------------------------------------------

void Gui::drawGrid()
{

  glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(0.5f);

    for(int i = -11; i < 10; i++)
    {
      glVertex3f( (0.5*i + 0.5f), 0.0f, -5.0f);
      glVertex3f( (0.5*i + 0.5f), 0.0f, 5.0f);

      glVertex3f(-5.0f, 0.0f, (0.5*i + 0.5f));
      glVertex3f(5.0f, 0.0f, (0.5*i + 0.5f));

    }

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(10.0f);
      glVertex3f(0.0f, 0.0f, -5.0f);
      glVertex3f(0.0f, 0.0f, 5.0f);

      glVertex3f(-5.0f, 0.0f, 0.0f);
      glVertex3f(5.0f, 0.0f, 0.0f);


  glEnd();

}


// 80 //////////////////////////////////////////////////////////////////////////