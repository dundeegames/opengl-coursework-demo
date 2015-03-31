// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*              TranspButton class - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*  Button with semitrasparent effect                                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef TRANSPBUTTON_H
#define TRANSPBUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>



class TranspButton : public Button
{

public:
  TranspButton();
  ~TranspButton();

  void init(int btnID, Input* in, GLuint tex_, float x_, float y_, float uvx_, float uvy_);
  void update();
  void draw();

private:

};


#endif // TRANSPBUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////