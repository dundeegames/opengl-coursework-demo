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


// DEFINES /////////////////////////////////////////////////////////////////////

// Colours
#define GRADIENT_TOP      0.533f, 0.615f, 0.698f
#define GRADIENT_BOTTOM   0.07f, 0.07f, 0.07f

#define COLOUR_WHITE      1.0f, 1.0f, 1.0f
#define COLOUR_BROWN      0.27f, 0.27f, 0.27f
#define COLOUR_DRKBROWN   0.17f, 0.17f, 0.17f




// CLASS ///////////////////////////////////////////////////////////////////////

class Viewport
{

public:
  Viewport();
  ~Viewport();

  void init(CameraType type, Input* in);
  void setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_);


  void update(float dt);
  void begin(bool perspective = true, bool grad_bgr = true);
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
  void drawBackground(bool gradient);

};


#endif // VIEWPORT_H




// 80 //////////////////////////////////////////////////////////////////////////