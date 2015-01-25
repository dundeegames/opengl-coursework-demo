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
#include "include/SOIL.h"



class Cube
{

public:
  Cube();
  ~Cube();
  void render();
  void init();

private:
  GLuint myTexture;


};


#endif // CUBE_H




// 80 //////////////////////////////////////////////////////////////////////////