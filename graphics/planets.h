// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                 Planets class - - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef PLANETS_H
#define PLANETS_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>



class Planets
{
  float rotation, rotation2, rotation3, speed;

public:
  void init();
  void update(float dt);
  void render();

private:


};


#endif // PLANETS_H



// 80 //////////////////////////////////////////////////////////////////////////
