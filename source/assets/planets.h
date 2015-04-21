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
#include <assets/light.h>
#include <ui/input.h>


class Planets
{

public:
  void init(Input* in);
  void update(float dt);
  void render();

private:
  float rotation;
  float rotation2;
  float rotation3;
  float speed;

  Light* fire;
  Light* ice;
  Input* input;

};


#endif // PLANETS_H



// 80 //////////////////////////////////////////////////////////////////////////
