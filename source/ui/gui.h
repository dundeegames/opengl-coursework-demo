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
#include <SOIL.h>


// DEFINES /////////////////////////////////////////////////////////////////////

// Colours
#define COLOUR_WHITE      1.0f, 1.0f, 1.0f
#define COLOUR_BLACK      0.0f, 0.0f, 0.0f
#define COLOUR_BROWN      0.27f, 0.27f, 0.27f
#define COLOUR_DRKBROWN   0.17f, 0.17f, 0.17f
#define COLOUR_GREEN      0.0f, 0.27f, 0.1f


class Gui
{

public:
  Gui();
  ~Gui();

  //void init(Font* font_);
  void init(Font* fnt);
  void drawGrid();
  void renderText();


private:
  Font* font;

  GLuint myTexture;
  void loadTexture(const char* file);

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////