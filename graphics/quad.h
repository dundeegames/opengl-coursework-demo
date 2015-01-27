// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                  Quad class - - WinAPI and OpenGL laboratory                \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef QUAD_H
#define QUAD_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
//#include "include/SOIL.h"
#include "geometry.h"



class Quad : public Geometry
{

public:
  Quad();
  ~Quad();
  void draw();

private:


};


#endif // QUAD_H




// 80 //////////////////////////////////////////////////////////////////////////