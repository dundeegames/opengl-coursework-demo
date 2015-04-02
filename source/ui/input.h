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
  int x,y, leftDragX, leftDragY, rightDragX, rightDragY;
  bool left, middle, right, leftDClick;
  Mouse()
  {
    x = 0;
    y = 0;
    leftDragX = 0;
    leftDragY = 0;
    rightDragX = 0;
    rightDragY = 0;
    left = false;
    middle = false;
    right = false;
    leftDClick = false;
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
  void setLeftMouseDClick(bool d);

  bool leftMouseBtn();
  bool middleMouseBtn();
  bool rightMouseBtn();
  bool leftMouseDClick();

  bool isBottonSelected(int btnID);
  void selectButton(int btnID);
  void unselectButton(int btnID);


  bool isViewportSelected(int viewID);
  void selectViewport(int viewID);
  //void unselectViewport(int viewID);


  void setWheelDelta(int wdt) {wheelDelta = wdt;}
  int getWheelDelta() const {return wheelDelta;}


  void resetLDragCoords();
  void setLDragX(int x_) {mouse.leftDragX = x_;}
  void setLDragY(int y_) {mouse.leftDragY = y_;}

  /*!
  * returns delta from original coords
  */
  int getLDragXdt();
  int getLDragYdt();


  void resetRDragCoords();
  void setRDragX(int x_) {mouse.rightDragX = x_;}
  void setRDragY(int y_) {mouse.rightDragY = y_;}

  /*!
  * returns delta from original coords
  */
  int getRDragXdt();
  int getRDragYdt();



  // set mouse botton down (left, right, middle)
  // set mouse botton up

  // add missing functions for handling mouse buttons etc
private:
  int windowHeight;
  int wheelDelta;
  bool keys[256];
  bool topButtons[MAX_TOP_BUTTONS];
  bool sideButtons[MAX_SIDE_BUTTONS];
  bool viewButtons[MAX_VIEW_BUTTONS];
  bool viewports[MAX_VIEWPORTS];
  Mouse mouse;
  float sensitivity;

};


#endif // INPUT_H




// 80 //////////////////////////////////////////////////////////////////////////