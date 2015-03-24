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
#include <system/macros.h>
#include <system/resourcemanager.h>



// CLASS ///////////////////////////////////////////////////////////////////////

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

  Sprite sidebarTop;
  Sprite sidebarMid;
  Sprite sidebarBtm;


  void resizeMenu();
  
  Font* font;
  GLuint menuTexture;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////