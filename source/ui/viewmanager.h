// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*               ViewManager class - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Apr 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/viewport.h>
#include <ui/input.h>
#include <system/macros.h>



struct BoundingBox
{

  int top;
  int bottom;
  int left;
  int right;
  BoundingBox()
  {
    top = 0;
    bottom = 0;
    left = 0;
    right = 0;
  }

};



// CLASS ///////////////////////////////////////////////////////////////////////

class ViewManager
{

public:
  ViewManager();
  ~ViewManager();
  void init(ResourceManager* resMngr, Input* in);
  void setWindowSize(float width, float height);
  void update(float dt);
  void beginView(int viewID, bool perspective = true, bool grad_bgr = true);
  void endView(int viewID);

private:
  /*!
  * Main 0, Bottom-Left 1, Bottom-Right 2,
  * Top-Left 3, Top-Right 4
  */
  Viewport viewports[MAX_VIEWPORTS];

  //! for selection hit test
  BoundingBox viewRects[MAX_VIEWPORTS];

  Input* input;
  void setViewRects(int viewID, int top, int btm, int lft, int rgt);
  void handleInput();

};


#endif // VIEWMANAGER_H




// 80 //////////////////////////////////////////////////////////////////////////