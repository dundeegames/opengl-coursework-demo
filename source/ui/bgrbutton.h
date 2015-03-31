// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                 BgrButton class - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*  Button with background effect                                              \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef BGRBUTTON_H
#define BGRBUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>



class BgrButton : public Button
{

public:
  BgrButton();
  ~BgrButton();

  void init(int btnID, Input* in, GLuint tex_, float x_, float y_, float uvx_, float uvy_);
  void update();
  void draw();

private:
  Sprite background;


};


#endif // BGRBUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////