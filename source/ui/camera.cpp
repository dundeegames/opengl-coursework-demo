#include <ui/camera.h>
#include <system/macros.h>

Camera::Camera()
{

}

// -----------------------------------------------------------------------------

Camera::~Camera()
{

}

// -----------------------------------------------------------------------------

void Camera::init(CameraType type_, Input* in)
{
  type = type_;
  input = in;
  //sensitivity = 2.5f;
  switch(type)
  {
  case FXP_MAIN:
    position = Vec3(DEF_MAIN_POS);
    rotation = Vec3(DEF_MAIN_ROT);
    forward = Vec3(DEF_MAIN_FWD);
    up = Vec3(DEF_MAIN_UP);
    right = forward.cross(up);
    break;

  case MOV_TOP:
    position = Vec3(DEF_TOP_POS);
    rotation = Vec3(DEF_TOP_ROT);
    forward = Vec3(DEF_TOP_FWD);
    up = Vec3(DEF_TOP_UP);
    right = forward.cross(up);
    break;

  case MOV_SIDE:
    position = Vec3(DEF_SIDE_POS);
    rotation = Vec3(DEF_SIDE_ROT);
    forward = Vec3(DEF_SIDE_FWD);
    up = Vec3(DEF_SIDE_UP);
    right = forward.cross(up);
    break;

  case MOV_FRONT:
    position = Vec3(DEF_FRNT_POS);
    rotation = Vec3(DEF_FRNT_ROT);
    forward = Vec3(DEF_FRNT_FWD);
    up = Vec3(DEF_FRNT_UP);
    right = forward.cross(up);
    break;

  case FLT_PERSP:
    position = Vec3(DEF_PERS_POS);
    rotation = Vec3(DEF_PERS_ROT);
    forward = Vec3(DEF_PERS_FWD);
    up = Vec3(DEF_PERS_UP);
    right = forward.cross(up);
    break;

  case FST_PERSON:
    // TODO: create attachment by ptr* to a 3D object
    // camera.values based on object.values
    position = Vec3(DEF_PERS_POS);
    rotation = Vec3(DEF_PERS_ROT);
    forward = Vec3(DEF_PERS_FWD);
    up = Vec3(DEF_PERS_UP);
    right = forward.cross(up);
    break;

  default:
    break;

  }



}

// -----------------------------------------------------------------------------

void Camera::update()
{

  //handleInput(dt);

  float cosR, cosP, cosY;  //temp values for sin/cos from 
  float sinR, sinP, sinY; 

  /*!
  * Roll, Pitch and Yall are variables stored by the camera
  * handle rotation
  * Only Want to calculate these values once. 
  * For speeds sake. 
  */
  cosY = cosf( rotation[YAW]*RADS);
  cosP = cosf( rotation[PITCH]*RADS);
  cosR = cosf( rotation[ROLL]*RADS);

  sinY = sinf( rotation[YAW]*RADS);
  sinP = sinf( rotation[PITCH]*RADS);
  sinR = sinf( rotation[ROLL]*RADS);


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
  switch(type)
  {
  case FXP_MAIN:
    // Do not use!!! input set to NULL
    break;

  case MOV_TOP:               // same for all orthographic cameras
  case MOV_SIDE:
  case MOV_FRONT:

    // TODO: check if not causing an error 
    //checkKeyborard('A', 'Z', VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, dt);
    break;

  case FLT_PERSP:

    checkKeyborard('A', 'Z', VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, dt);

    //checkKeyborard('W', 'S', 'D', 'A', 'E', 'F', dt);

    //if(input->isKeyDown('A'))                  // if W key is pressed
    //{
    //  position = position.add( forward, dt * input->getSensitivity() );
    //}
    //else if(input->isKeyDown('Z'))             // if S key is pressed
    //{
    //  position = position.subtract( forward, dt * input->getSensitivity() );
    //}


    //if(input->isKeyDown(VK_RIGHT))                  // if D key is pressed
    //{
    //  position = position.add( right, dt * input->getSensitivity() );
    //}
    //else if(input->isKeyDown(VK_LEFT))             // if A key is pressed
    //{
    //  position = position.subtract( right, dt * input->getSensitivity() );
    //}


    //if(input->isKeyDown(VK_UP))                  // if E key is pressed
    //{
    //  position = position.add( up, dt * input->getSensitivity() );
    //}
    //else if(input->isKeyDown(VK_DOWN))             // if F key is pressed
    //{
    //  position = position.subtract( up, dt * input->getSensitivity() );
    //}
    
    break;



  case FST_PERSON:
    checkKeyborard('W', 'S', 'D', 'A', 'E', 'F', dt);

    //if(input->isKeyDown('W'))                  // forward
    //{
    //  position = position.add( forward, dt * input->getSensitivity() );
    //}
    //else if(input->isKeyDown('S'))             // backward
    //{
    //  position = position.subtract( forward, dt * input->getSensitivity() );
    //}


    //if(input->isKeyDown('D'))                  // right
    //{
    //  position = position.add( right, dt * input->getSensitivity() );
    //}
    //else if(input->isKeyDown('A'))             // left
    //{
    //  position = position.subtract( right, dt * input->getSensitivity() );
    //}


    //if(input->isKeyDown('E'))                  // up
    //{
    //  position = position.add( up, dt * input->getSensitivity() );
    //}
    //else if(input->isKeyDown('F'))             // down
    //{
    //  position = position.subtract( up, dt * input->getSensitivity() );
    //}

    break;

  default:
    break;





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

// -----------------------------------------------------------------------------

void Camera::checkKeyborard(int frwd, int back, int rgt, int lft,
                            int up_, int dwn, float dt)
{
  if(input->isKeyDown(frwd))                  // if W key is pressed
  {
    position = position.add( forward, dt * input->getSensitivity() );
  }
  else if(input->isKeyDown(back))             // if S key is pressed
  {
    position = position.subtract( forward, dt * input->getSensitivity() );
  }


  if(input->isKeyDown(rgt))                  // if D key is pressed
  {
    position = position.add( right, dt * input->getSensitivity() );
  }
  else if(input->isKeyDown(lft))             // if A key is pressed
  {
    position = position.subtract( right, dt * input->getSensitivity() );
  }


  if(input->isKeyDown(up_))                  // if E key is pressed
  {
    position = position.add( up, dt * input->getSensitivity() );
  }
  else if(input->isKeyDown(dwn))             // if F key is pressed
  {
    position = position.subtract( up, dt * input->getSensitivity() );
  }

}

// -----------------------------------------------------------------------------





// 80 //////////////////////////////////////////////////////////////////////////