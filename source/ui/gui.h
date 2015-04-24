////////////////////////////////////////////////////////////////////////////////
/**
* \file       gui.h
* \brief      Gui class - AG0800A Graphics Programming
*
* \details    Creates and manages buttons 
*
* \author     Jiri Klic
* \version    1.0
* \date       February 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////


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
#include <ui/transpbutton.h>
#include <ui/bgrbutton.h>
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

  Sprite sidebarSep;    // separator line

  Sprite logo3D;
  Sprite logoTri;

  std::vector<TranspButton> transpButtons;
  std::vector<BgrButton> bgrButtons;

  void resizeMenu();
  void setButtons();
  void initTranspButton(int btnID, float x_, float y_, float uvx_, float uvy_);
  void initBgrButton(int btnID, float x_, float y_, float uvx_, float uvy_);

  Font* font;
  GLuint menuTexture;

};


#endif // GUI_H




// 80 //////////////////////////////////////////////////////////////////////////