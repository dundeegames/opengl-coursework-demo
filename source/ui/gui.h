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

#include <ui/font.h>



class Gui
{

public:
  Gui();
  ~Gui();

  //void init(Font* font_);
  void init();
  void drawGrid();
  void renderText();

  void test1();


private:
  Font font;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////