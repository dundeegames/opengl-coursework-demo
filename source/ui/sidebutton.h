// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                SideButton class - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef SIDEBUTTON_H
#define SIDEBUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>



class SideButton : public Button
{

public:
  SideButton();
  ~SideButton();

  void init(int btnID, Input* in, GLuint tex_, float x_, float y_, float uvx_, float uvy_);
  void update();
  void draw();

private:
  Sprite background;


};


#endif // SIDEBUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////