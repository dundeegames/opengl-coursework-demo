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



class Gui
{

public:
  Gui();
  ~Gui();
  void drawBackground(float left, float right, float bottom, float top);
  void drawGrid();


private:


};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////