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
#include "vec3.h"


enum Type {FIXED_POINT, ROTATING, SCROLLING, MOVEABLE, FLOATING, TRACKING, THIRD_PERSON, FIRST_PERSON};
#define PI 3.1415



class Camera
{

public:
  Camera();
  ~Camera();

  void init(Type type_);
  void update(float dt);
  void handleInput(Input* in);
  Vec3 getPosition();
  Vec3 getRotation();
  Vec3 getForward();


  inline float posX() { return position.getX(); };
  inline float posY() { return position.getY(); };
  inline float posZ() { return position.getZ(); };

  inline float lookX() { return lookAt.getX(); };
  inline float lookY() { return lookAt.getY(); };
  inline float lookZ() { return lookAt.getZ(); };

  inline float upX() { return up.getX(); };
  inline float upY() { return up.getY(); };
  inline float upZ() { return up.getZ(); };


private:
  Vec3 position;

  /*!
  * Pitch (Rotation around x- axis)
  * Yaw   (Rotation around y-axis)
  * Roll  (Rotation around z-axis)
  */
  Vec3 rotation;

  //! LookAt = position + forward
  Vec3 lookAt;

  Vec3 forward;      
  Vec3 up;
  Vec3 right;

  Type type;

};


#endif // CAMERA_H

// 80 //////////////////////////////////////////////////////////////////////////