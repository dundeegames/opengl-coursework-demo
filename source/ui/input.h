// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                  Input class - WinAPI and OpenGL laboratory                 \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*    Based on:  Input class.[2014].Paul Robertson                             \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef INPUT_H
#define INPUT_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <system/macros.h>


struct Mouse
{
  int x,y;
  bool left, middle, right;
  Mouse()
  {
    x = 0;
    y = 0;
    left = false;
    middle = false;
    right = false;
  }

};


// CLASS ///////////////////////////////////////////////////////////////////////

class Input
{

public:
  Input();
  ~Input();

  void SetKeyDown(WPARAM);
  void SetKeyUp(WPARAM);

  bool isKeyDown(int);

  void setMouseX(int);
  void setMouseY(int);
  int getMouseX();
  int getMouseY();
  float getSensitivity();

  void setLeftMouseBtn(bool l);
  void setMiddleMouseBtn(bool m);
  void setRightMouseBtn(bool r);

  bool leftMouseBtn();
  bool middleMouseBtn();
  bool rightMouseBtn();

  bool isBottonSelected(int btnID);
  void selectButton(int btnID);
  void unselectButton(int btnID);

  // set mouse botton down (left, right, middle)
  // set mouse botton up

  // add missing functions for handling mouse buttons etc
private:
  bool keys[256];
  bool topButtons[MAX_TOP_BUTTONS];
  bool sideButtons[MAX_SIDE_BUTTONS];
  bool viewButtons[MAX_VIEW_BUTTONS];
  Mouse mouse;
  float sensitivity;

};


#endif // INPUT_H




// 80 //////////////////////////////////////////////////////////////////////////