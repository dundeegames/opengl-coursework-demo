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

  Sprite logo3D;
  Sprite logoTri;


  Sprite topBtn1;
  Sprite topBtn2;
  Sprite topBtn3;
  Sprite topBtn4;
  Sprite topBtn5;
  Sprite topBtn6;
  Sprite topBtn7;
  Sprite topBtn8;
  Sprite topBtn9;

  Sprite sideBtn1;
  Sprite sideBtn2;
  Sprite sideBtn3;
  Sprite sideBtn4;
  Sprite sideBtn5;
  Sprite sideBtn6;




  void resizeMenu();
  void setButtons();
  
  Font* font;
  GLuint menuTexture;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////