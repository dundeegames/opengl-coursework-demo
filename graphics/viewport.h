// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                  Viewport class - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Mar 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef VIEWPORT_H
#define VIEWPORT_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>

#include "camera.h"
#include "gui.h"


class Viewport
{

public:
  Viewport();
  ~Viewport();

  void init(CameraType type, Input* in, Gui* gui_);
  void setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_);

  void update(float dt);
  void begin();
  void end();

private:
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
  float left;
  float right;
  float top;
  float bottom;

  Camera camera;
  Gui* gui;

};


#endif // VIEWPORT_H




// 80 //////////////////////////////////////////////////////////////////////////