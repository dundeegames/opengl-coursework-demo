////////////////////////////////////////////////////////////////////////////////
/**
* \file       scene3D.h
* \brief      Scene3D class - AG0800A Graphics Programming
*
* \details    Handles the size of the scene and all main assets
*
* \author     Jiri Klic
* \version    1.0
* \date       January 2015
* \pre        Init(HWND*, Input*) needs to be called prior to use
* \post       
* \bug        No known bugs
* \warning    <windows.h> needs to be included BEFORE <gl/gl.h> & <gl/glu.h>
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////



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
  /**
  * \brief      Set up the window, openGL properties and all objects in the scene  
  * \param      wnd - pointer to window handle
  * \param      in  - poiter to input object
  * \return     void
  */
  void Init(HWND* wnd, Input* in);         ///< initialse function


  /**
  * \brief      renders content of scene
  * \param      dt - delta time
  * \return     void
  */
  void DrawScene(float dt);            // render scene


  /**
  * \brief      Call 
  *
  * \details    Detailed description 
  * \param      void
  * \return     void
  */
  void Resize();


  /**
  * \brief      navigate to and opens the file
  * \param      void
  * \return     void
  */
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
