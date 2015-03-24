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
#include <vector>

#include <ui/font.h>
#include <assets/sprite.h>
#include <system/resourcemanager.h>


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

  void init(ResourceManager* resMngr);
  void setWindowSize(float width, float height);
  void drawGrid();
  void renderText();
  void renderMenu();


private:
  float windowWidth;
  float windowHeight;

  Sprite ribbonLeft;
  Sprite ribbonMiddle;
  Sprite ribbonRight;
//  Sprite sidebar;


  void initMenu();
  
  Font* font;
  GLuint menuTexture;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////