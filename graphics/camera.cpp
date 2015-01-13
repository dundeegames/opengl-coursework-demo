#include "camera.h"


Camera::Camera()
{

}

// -----------------------------------------------------------------------------

Camera::~Camera()
{

}

// -----------------------------------------------------------------------------

void Camera::init(Type type_, Input* in)
{
  type = type_;
  input = in;
  sensitivity = 2.5f;
  position = Vec3(0.0f, 0.0f, 10.0f);
  rotation = Vec3(0.0f, 0.0f, 0.0f);
  forward = Vec3(0.0f, 0.0f, -1.0f);
  up = Vec3(0.0f, 1.0f, 0.0f);

  right = forward.cross(up);

}

// -----------------------------------------------------------------------------

void Camera::update(float dt)
{

  handleInput(dt);

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

}

// -----------------------------------------------------------------------------

void Camera::handleInput(float dt)
{
  if(input->isKeyDown('W'))                  // if W key is pressed
  {
    position = position.add( forward, dt * sensitivity );
    //position += forward;
    //position.add( forward );
  }
  else if(input->isKeyDown('S'))             // if S key is pressed
  {
    position = position.subtract( forward, dt * sensitivity );
    //position -= forward;
  }


  if(input->isKeyDown('D'))                  // if D key is pressed
  {
    position = position.add( right, dt * sensitivity );
    //position += right;
  }
  else if(input->isKeyDown('A'))             // if A key is pressed
  {
    position = position.subtract( right, dt * sensitivity );
    //position -= right;
  }


  if(input->isKeyDown('E'))                  // if E key is pressed
  {
    position = position.add( up, dt * sensitivity );
    //position += right;
  }
  else if(input->isKeyDown('F'))             // if F key is pressed
  {
    position = position.subtract( up, dt * sensitivity );
    //position -= right;
  }

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

void Camera::view()
{
  //! LookAt = position + forward
  Vec3 lookAt = position + forward;


  gluLookAt(position.getX(),  position.getY(),  position.getZ(),
            lookAt.getX(),    lookAt.getY(),    lookAt.getZ(),
            up.getX(),        up.getY(),        up.getZ() );

}





// 80 //////////////////////////////////////////////////////////////////////////