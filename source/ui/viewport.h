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


// DEFINES /////////////////////////////////////////////////////////////////////
#define Z_POSITION        0.0f


// Colours
#define GRADIENT_TOP      0.533f, 0.615f, 0.698f
#define GRADIENT_BOTTOM   0.07f, 0.07f, 0.07f

#define COLOUR_WHITE      1.0f, 1.0f, 1.0f
#define COLOUR_BLACK      0.0f, 0.0f, 0.0f
#define COLOUR_BROWN      0.27f, 0.27f, 0.27f
#define COLOUR_DRKGRAY    0.2f, 0.2f, 0.2f
#define COLOUR_GREEN      0.0f, 0.27f, 0.1f
#define COLOUR_YELLOW     1.0f, 0.8f, 0.0f
#define COLOUR_DRKYELLOW  0.49f, 0.41f, 0.17f

// Label offsets
#define PERSP_OFFSET      ( (float)(width >> 1) - 15.0f)
#define TOP_OFFSET        ( (float)(width >> 1) - 11.0f)
#define SIDE_OFFSET       ( (float)(width >> 1) - 12.0f)
#define FRONT_OFFSET      ( (float)(width >> 1) - 14.0f)

enum ViewportType {VIEW_MAIN, VIEW_PERSP, VIEW_TOP, VIEW_SIDE, VIEW_FRONT, VIEW_GAME};



// CLASS ///////////////////////////////////////////////////////////////////////

class Viewport
{

public:
  Viewport();
  ~Viewport();

  void init(ViewportType view, CameraType cmr, Input* in, Font* fnt);
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