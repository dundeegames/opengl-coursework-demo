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
#include <ui/font.h>

#include <system/resourcemanager.h>

enum ViewportType {VIEW_MAIN, VIEW_PERSP, VIEW_TOP, VIEW_SIDE, VIEW_FRONT, VIEW_GAME};



// CLASS ///////////////////////////////////////////////////////////////////////

class Viewport
{

public:
  Viewport();
  ~Viewport();

  void init(int viewID, ViewportType view, Input* in, ResourceManager* resMngr);
  void setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_);


  void update(float dt);
  void begin(bool perspective = true, bool grad_bgr = true);
  void end();

  void activate() {activated = true;}
  void deactivate() {activated = false;}
  bool isActivated() {return activated;}

private:
  int viewportID;
  ViewportType type;
  bool activated;

  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
  GLdouble left;
  GLdouble right;
  GLdouble top;
  GLdouble bottom;

  Camera camera;
  Font* font;
  Input* input;

  void orthographicView();
  void perspectiveView();
  void drawBackground(bool gradient);

  void drawLabel();
  void drawSelectionRect();

};


#endif // VIEWPORT_H




// 80 //////////////////////////////////////////////////////////////////////////