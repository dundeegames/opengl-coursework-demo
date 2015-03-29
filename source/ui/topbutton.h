// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                TopButton class - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef TOPBUTTON_H
#define TOPBUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>



class TopButton : public Button
{

public:
  TopButton();
  ~TopButton();

  void init(Input* in, GLuint tex_, float x_, float y_, float uvx_, float uvy_);
  void update();
  void draw();

private:

};


#endif // TOPBUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////