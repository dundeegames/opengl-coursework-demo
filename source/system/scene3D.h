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

#include <assets/cube.h>
#include <assets/arm.h>
#include <assets/planets.h>
#include <assets/light.h>
#include <assets/sprite.h>
#include <assets/triangle.h>
#include <assets/model.h>

#include <system/resourcemanager.h>



// DEFINES /////////////////////////////////////////////////////////////////////
#define COLOUR_DEPTH 16             //Colour depth





// CLASS ///////////////////////////////////////////////////////////////////////

class Scene3D
{


public:
  void Init(HWND*, Input*);         //initialse function
  void DrawScene(float);            // render scene
  void Resize();

protected:
  bool CreatePixelFormat(HDC);
  void ResizeGLWindow(int, int);    //width and height
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

  Light* ambient;
  Light* light1;
  Geometry* box;
  Geometry* triangle;
  Arm robotArm;
  Planets solarSystem;
  COORD center;

  Gui gui;
  Viewport viewport0;   // Main
  Viewport viewport1;   // Bottom-Left
  Viewport viewport2;   // Bottom-Right
  Viewport viewport3;   // Top-Left
  Viewport viewport4;   // Top-Right

  std::vector<Model> models;

  bool mouseCaptured;

  void captureMouse();
  void releaseMouse();
  void rotateCamera();

  void insertFile();
  void loadFile();

  void render();

};


#endif // SCENE3D_H



// 80 //////////////////////////////////////////////////////////////////////////
