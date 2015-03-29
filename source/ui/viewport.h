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

  void init(ViewportType view, CameraType cmr, Input* in, ResourceManager* resMngr);
  void setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_);


  void update(float dt);
  void begin(bool perspective = true, bool grad_bgr = true);
  void end();

  void select() {selected = true;}
  void deselect() {selected = false;}
  bool isSelected() {return selected;}

  void activate() {activated = true;}
  void deactivate() {activated = false;}
  bool isActivated() {return activated;}

private:
  ViewportType type;
  bool selected;
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

  void orthographicView();
  void perspectiveView();
  void drawBackground(bool gradient);

  void drawLabel();
  void drawSelectionRect();

};


#endif // VIEWPORT_H




// 80 //////////////////////////////////////////////////////////////////////////