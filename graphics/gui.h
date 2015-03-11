// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                   Gui class - WinAPI and OpenGL laboratory                  \n
*                             by Jiri Klic, Feb 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef GUI_H
#define GUI_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "font.h"



class Gui
{

public:
  Gui();
  ~Gui();

  //void init(Font* font_);
  void init();
  void drawBackground(float left, float right, float bottom, float top);
  void drawGrid();
  void renderText();


private:
  Font font;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////