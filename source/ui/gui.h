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

#include <ui/button.h>
#include <ui/topbutton.h>
#include <ui/sidebutton.h>
#include <ui/input.h>


// CLASS ///////////////////////////////////////////////////////////////////////

class Gui
{

public:
  Gui();
  ~Gui();

  void init(ResourceManager* resMngr, Input* in);
  void setWindowSize(float width, float height);
  void update();

  void drawGrid();
  void renderText();
  void renderMenu();


private:
  Input* input;

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

  std::vector<TopButton> topButtons;
  std::vector<SideButton> sideButtons;

  //Sprite topBtn1;
  //Sprite topBtn2;
  //Sprite topBtn3;
  //Sprite topBtn4;
  //Sprite topBtn5;
  //Sprite topBtn6;
  //Sprite topBtn7;
  //Sprite topBtn8;
  //Sprite topBtn9;

  Sprite sideBtn1;
  Sprite sideBtn2;
  Sprite sideBtn3;
  Sprite sideBtn4;
  Sprite sideBtn5;
  Sprite sideBtn6;




  void resizeMenu();
  void setButtons();
  void initTopButton(Input* in, GLuint tex_, float x_, float y_,
                                             float uvx_, float uvy_);

  void initSideButton(Input* in, GLuint tex_, float x_, float y_,
                                              float uvx_, float uvy_);

  Font* font;
  GLuint menuTexture;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////