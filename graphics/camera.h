// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                  Camera class - WinAPI and OpenGL laboratory                \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef CAMERA_H
#define CAMERA_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "input.h"
#include "math/vec3.h"


enum CameraType {FIXED_POINT, ROTATING, SCROLLING, MOVEABLE, FLOATING, TRACKING, THIRD_PERSON, FIRST_PERSON};
#define PI 3.1415f


// TODO does camera need dt in update?

class Camera
{

public:
  Camera();
  ~Camera();

  void init(CameraType type_, Input* in);
  void update(float dt);
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
  //float sensitivity;
};


#endif // CAMERA_H

// 80 //////////////////////////////////////////////////////////////////////////