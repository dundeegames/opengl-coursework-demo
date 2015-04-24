////////////////////////////////////////////////////////////////////////////////
/**
* \file       camera.h
* \brief      Camera class - AG0800A Graphics Programming
*
* \details    Provides different types of camera for 3D scene, with various
*             options for user input
*
* \author     Jiri Klic
* \version    1.0
* \date       January 2015
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


#ifndef CAMERA_H
#define CAMERA_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include <ui/input.h>
#include <math/vec3.h>

// -----------------------------------------------------------------------------

enum CameraType { FXP_MAIN,         // Fixed Point
                  MOV_TOP,          // Movable 2D / Ortho
                  MOV_SIDE,
                  MOV_FRONT,
                  FLT_PERSP,        // floating perspective
                  FST_PERSON,       // 1st person game

                  // unused options
                  ROTATING,         // rotate only
                  SCROLLING,        // similar to Movable, but autoscrolling 
                  TRACKING,
                  TRD_PERSON        // 3rd person game

                };



// CLASS ///////////////////////////////////////////////////////////////////////

class Camera
{

public:
  Camera();
  ~Camera();

  void init(CameraType type_, Input* in);
  void update();
  void handleInput(float dt);
  Vec3 getPosition();
  Vec3 getRotation();
  Vec3 getForward();


  void view();



private:
  Vec3 position;
  Vec3 forward;      
  Vec3 up;
  Vec3 right;

  /*!
  * Pitch (Rotation around x- axis)
  * Yaw   (Rotation around y-axis)
  * Roll  (Rotation around z-axis)
  */
  Vec3 rotation;

  CameraType type;
  Input* input;

  bool returning;
  float timer;
  Vec3 posOrigin;
  Vec3 rotOrigin;
  Vec3 posOffset;
  Vec3 rotOffset;

  void backToOrigin(float dt);
  void setOffsets();

  void checkKeyborard(int frwd, int back, int rgt, int lft,
                      int up_, int dwn, float dt);


};


#endif // CAMERA_H




// 80 //////////////////////////////////////////////////////////////////////////