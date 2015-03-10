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
#include "input.h"
#include "cube.h"
#include "arm.h"
#include "planets.h"
#include "light.h"
#include "camera.h"
#include "sprite.h"
#include "triangle.h"
#include "gui.h"
#include "font.h"

#include "Model.h"


#define COLOUR_DEPTH 16             //Colour depth



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
  Light* ambient;
  Light* light1;
  Camera camera;
  Geometry* box;
  Geometry* quad;
  Geometry* triangle;
  Arm robotArm;
  Planets solarSystem;
  COORD center;
  Gui gui;
  Font font;
  Model model;

  bool mouseCaptured;

  void captureMouse();
  void releaseMouse();
  void rotateCamera();

  void loadFile();

};


#endif // SCENE3D_H



// 80 //////////////////////////////////////////////////////////////////////////
