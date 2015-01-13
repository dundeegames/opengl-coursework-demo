#include "camera.h"


Camera::Camera()
{

}

// -----------------------------------------------------------------------------

Camera::~Camera()
{

}

// -----------------------------------------------------------------------------

void Camera::init()
{

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
  //cosY = cosf(Yaw*PI/180);
  //cosP = cosf(Pitch*PI/180);
  //cosR = cosf(Roll*PI/180);
  //sinY = sinf(Yaw*PI/180);
  //sinP = sinf(Pitch*PI/180);
  //sinR = sinf(Roll*PI/180);


  /*!
  * This using the parametric equation of a sphere
  *
  * Calculate the three vectors to put into  glu Lookat
  * Look direction,  position and the up vector
  * This function could also calculate the right vector
  */
  //forward.x = sinY * cosP;
  //forward.y = sinP;
  //forward.z = cosP * -cosY;


  /*!
  * Look At Point
  * To calculate add Forward Vector to Camera position.
  */

  //! Up Vector
  //up.x = -cosY * sinR - sinY * sinP * cosR;
  //up.y = cosP * cosR;
  //up.z = -sinY * sinR - sinP * cosR * -cosY;

  /*!
  * Side Vector (right)
  * this is a cross product between the forward and up vector.
  * If you don’t need to calculate this,  don’t do it. 
  */

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