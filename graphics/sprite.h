// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                 Sprite class - - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef SPRITE_H
#define SPRITE_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
#include "geometry.h"



class Sprite : public Geometry
{

public:
  Sprite();
  ~Sprite();
  
  void draw();


  //void setUV(float )


private:
  GLuint DisplayList;

  void setDList();

};


#endif // SPRITE_H




// 80 //////////////////////////////////////////////////////////////////////////