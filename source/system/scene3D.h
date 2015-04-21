// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                Scene3D class - - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef SCENE3D_H
#define SCENE3D_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include <ui/input.h>
#include <ui/gui.h>
#include <ui/viewport.h>
#include <ui/viewmanager.h>

#include <assets/arm.h>
#include <assets/planets.h>
#include <assets/light.h>
#include <assets/sprite.h>
#include <assets/model.h>
#include <assets/material.h>
#include <assets/terrain.h>

#include <system/resourcemanager.h>
#include <system/modelgenerator.h>



// DEFINES /////////////////////////////////////////////////////////////////////
#define COLOUR_DEPTH 16             //Colour depth





// CLASS ///////////////////////////////////////////////////////////////////////

class Scene3D
{


public:
  void Init(HWND*, Input*);         //initialse function
  void DrawScene(float);            // render scene
  void Resize();
  void loadFile();


protected:
  bool CreatePixelFormat(HDC);
  void resizeGLWindow(int width, int height);
  void resizeViewport();


  void InitializeOpenGL(int, int);  // width and height
  void HandleInput(float dt);

  //vars
  HWND* hwnd;
  Input* input;
  RECT screenRect;
  HDC  hdc;
  HGLRC hrc;                        //hardware RENDERING CONTEXT
  int s_wdith, s_height;

private:
  ResourceManager resManager;
  ModelGenerator modelGen;

  Light* ambient;
  Light* direct;
  Light* spot1;
  Light* spot2;

  Terrain terrain;
  Arm robotArm;
  COORD center;

  Gui gui;
  ViewManager viewManager;


  std::vector<Model> models;

  void insertFile();


  void render();

};


#endif // SCENE3D_H



// 80 //////////////////////////////////////////////////////////////////////////
