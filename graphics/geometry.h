// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                Geometry class - - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*       Used as Base Class for geometry primitives:                           \n
*                                                                             \n
*       Cube, Quad, Triangle                                                  \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////


#ifndef GEOMETRY_H
#define GEOMETRY_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
#include "include/SOIL.h"

// TODO rotate(), rotateBy(); 


class Geometry
{

public:
  Geometry();
  ~Geometry();

  void loadTexture(const char* file);
  virtual void draw() = 0;
  void setColor3f(GLfloat red_, GLfloat green_, GLfloat blue_);



protected:
  GLuint myTexture;
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat alpha;

};


#endif // GEOMETRY_H




// 80 //////////////////////////////////////////////////////////////////////////