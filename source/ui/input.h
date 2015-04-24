////////////////////////////////////////////////////////////////////////////////
/**
* \file       input.h
* \brief      Input class - AG0800A Graphics Programming
*
* \details    Detailed description 
*
* \author     Jiri Klic
* \author     Paul Robertson
* \version    2.0
* \date       January 2015    [2.0]
* \date       September 2014  [1.0]
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo
*
* \copyright  Based on:  Input class.[2014].Paul Robertson
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////



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

// -----------------------------------------------------------------------------

struct ViewportSetting
{
  bool selected;
  bool active;
  ViewportSetting()
  {
    selected = false;
    active = true;
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

  bool isViewportActive(int viewID);
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
  bool lightButtons[MAX_LIGHT_BUTTONS];

  ViewportSetting viewports[MAX_VIEWPORTS];
  Mouse mouse;
  float sensitivity;

};


#endif // INPUT_H




// 80 //////////////////////////////////////////////////////////////////////////