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

#include <ui/camera.h>
#include <ui/gui.h>


class Viewport
{

public:
  Viewport();
  ~Viewport();

  void init(CameraType type, Input* in);
  void setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_);


  void update(float dt);
  void begin(bool perspective = true);
  void end();

private:
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
  GLdouble left;
  GLdouble right;
  GLdouble top;
  GLdouble bottom;

  Camera camera;

  void orthographicView();
  void perspectiveView();
  void drawBackground();

};


#endif // VIEWPORT_H




// 80 //////////////////////////////////////////////////////////////////////////