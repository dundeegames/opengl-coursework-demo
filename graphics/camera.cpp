#include "camera.h"


Camera::Camera()
{

}

// -----------------------------------------------------------------------------

Camera::~Camera()
{

}

// -----------------------------------------------------------------------------

void Camera::init(Type type_)
{
  type = type_;
  position = Vec3(0,0,10);
  rotation = Vec3();
  forward = Vec3();
  up = Vec3(0,1,0);

  right = forward.cross(up);
  lookAt = Vec3();
  //lookAt = position + forward;

}

// -----------------------------------------------------------------------------

void Camera::update(float dt)
{

  float cosR, cosP, cosY;  //temp values for sin/cos from 
  float sinR, sinP, sinY; 

  /*!
  * Roll, Pitch and Yall are variables stored by the camera
  * handle rotation
  * Only Want to calculate these values once. 
  * For speeds sake. 
  */
  cosY = cosf( rotation[0]*PI/180);        // Yall
  cosP = cosf( rotation[1]*PI/180);        // Pitch
  cosR = cosf( rotation[2]*PI/180);        // Roll

  sinY = sinf( rotation[0]*PI/180);        // Yall
  sinP = sinf( rotation[1]*PI/180);        // Pitch
  sinR = sinf( rotation[2]*PI/180);        // Roll


  /*!
  * This using the parametric equation of a sphere
  *
  * Calculate the three vectors to put into  glu Lookat
  * Look direction,  position and the up vector
  * This function could also calculate the right vector
  */
  forward.setX(sinY * cosP);
  forward.setY(sinP);
  forward.setZ(cosP * -cosY);


  /*!
  * Look At Point
  * To calculate add Forward Vector to Camera position.
  */

  //! Up Vector
  up.setX(-cosY * sinR - sinY * sinP * cosR);
  up.setY(cosP * cosR);
  up.setZ(-sinY * sinR - sinP * cosR * -cosY);

  /*!
  * Side Vector (right)
  * this is a cross product between the forward and up vector.
  * If you don’t need to calculate this,  don’t do it. 
  */
  right = forward.cross(up);

  //! LookAt = position + forward
  //lookAt = position + forward;

}

// -----------------------------------------------------------------------------

void Camera::handleInput(Input* in)
{

}

// -----------------------------------------------------------------------------

Vec3 Camera::getPosition()
{
  return position;
}

// -----------------------------------------------------------------------------

Vec3 Camera::getRotation()
{
  return rotation;
}

// -----------------------------------------------------------------------------

Vec3 Camera::getForward()
{
  return forward;
}

// -----------------------------------------------------------------------------







// 80 //////////////////////////////////////////////////////////////////////////