// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                    Cube class - - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef CUBE_H
#define CUBE_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
#include <assets/geometry.h>



class Cube : public Geometry
{

public:
  Cube();
  ~Cube();
  void draw();

private:



};


#endif // CUBE_H




// 80 //////////////////////////////////////////////////////////////////////////