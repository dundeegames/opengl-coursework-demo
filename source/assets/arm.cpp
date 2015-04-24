////////////////////////////////////////////////////////////////////////////////
/**
* \file       arm.cpp
* \brief      Arm class - AG0800A Graphics Programming
*
* \details    Hierarchically modeled robotic arm, animated by user input
*
* \author     Jiri Klic
* \version    1.0
* \date       April 2015
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





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <assets/arm.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


void Arm::Init(Input* in, ModelGenerator* mg, Planets* plts)
{
  input = in;
  Material* gold = new Material(0.8f, 0.8f, 0.0f, 1.0f);
  gold->setAmbient(MAT_GOLD_AMBIENT);
  gold->setDiffuse(MAT_GOLD_DIFFUSE);
  gold->setSpecular(MAT_GOLD_SPECULAR);
  gold->setShininess(MAT_GOLD_SHININESS);
  Material* white = new Material(0.8f, 0.8f, 0.8f, 1.0f);

  sphere = mg->getCubeSPhere(0.125f, 20);
  sphere.setMaterial(white);

  cylinder = mg->getCylinder(0.1f, 3.0f, 32, 16);
  //cylinder.setMaterial(red);
  cylinder.setMaterial(gold);

  armXrotation = 0.0f;
  armYrotation = 0.0f;
  elbowXrotation = 0.0f;
  elbowYrotation = 0.0f;
  wristYrotation = 0.0f;
  wristOpen = -60.0f;
  speed = 25.0;

  state = ARM;
  orbits = plts;
}

// ------------------------------------------------------------------------------

void Arm::update(float dt)
{
  handleInput(dt);
  orbits->update(dt);
}

// ------------------------------------------------------------------------------

void Arm::handleInput(float dt)
{

  if(input->isKeyDown('7'))                  // if A key is pressed
  {
    // change state
    if(state != ARM)
    {
      state = ARM;
    }
  }


  if(input->isKeyDown('8'))                  // if E key is pressed
  {
    // change state
    if(state != ELBOW)
    {
      state = ELBOW;
    }
  }


  if(input->isKeyDown('9'))                  // if W key is pressed
  {
    // change state
    if(state != WRIST)
    {
      state = WRIST;
    }
  }



  if(input->isKeyDown('J'))                  // if Left arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armYrotation -= speed*dt;
      break;

    case ELBOW:
      elbowYrotation -= speed*dt;
      break;

    case WRIST:
      wristYrotation -= 2*speed*dt;
      break;

    default:
      break;
    }
  }

  if(input->isKeyDown('L'))                  // if Right arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armYrotation += speed*dt;
      break;

    case ELBOW:
      elbowYrotation += speed*dt;
      break;

    case WRIST:
      wristYrotation += 2*speed*dt;
      break;

    default:
      break;
    }    
  }

  if(input->isKeyDown('I'))                  // if Left arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armXrotation -= speed*dt;
      break;

    case ELBOW:
      if(elbowXrotation > ELBOW_MINROTATION)
      {
        elbowXrotation -= speed*dt;
      }
      break;

    case WRIST:
      if(wristOpen > WRIST_MAXOPEN)
      {
        wristOpen -= 2*speed*dt;
      }
      break;

    default:
      break;
    }    
  }

  if(input->isKeyDown('K'))                  // if Right arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armXrotation += speed*dt;
      break;

    case ELBOW:
      if(elbowXrotation < ELBOW_MAXROTATION)
      {
        elbowXrotation += speed*dt;
      }      
      break;

    case WRIST:
      if(wristOpen < WRIST_MAXCLOSE)
      {
        wristOpen += 2*speed*dt;
      }
      break;

    default:
      break;
    }    
  }

}

// ------------------------------------------------------------------------------

void Arm::render()
{
  glPushMatrix();  // Remember - INITIAL STATE

    glTranslatef(0.5f, 0.25f, -1.5f); // world position

    glRotatef(armYrotation, 0, 1, 0);
    glRotatef(armXrotation, 1, 0, 0);
    glRotatef(elbowYrotation, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 2.0f, 0.0f);
      
    glRotatef(elbowXrotation, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 1.0f, 0.0f);

    glRotatef(wristYrotation, 0.0f, 1.0f, 0.0);
    glTranslatef(0.0f, 2.5f, 0.0f);

    // render orbits first, because they contain lights too
    orbits->render();

  glPopMatrix();  // Back to - INITIAL STATE
  glPushMatrix();  // Remember - INITIAL STATE

    glTranslatef(0.5f, 0.25f, -1.5f); // world position
    glRotatef(armYrotation, 0, 1, 0);
    glRotatef(armXrotation, 1, 0, 0);

    // render the SHOULDER
    glPushMatrix();  // Remember - SHOULDER
      glScalef(0.25f, 0.25f, 0.25f);
      sphere.Render();
    glPopMatrix();  // Back to - SHOULDER

    glPushMatrix();  // Remember - SHOULDER
      
      glRotatef(elbowYrotation, 0.0f, 1.0f, 0.0f);
      glTranslatef(0.0f, 0.2f, 0.0f);

      //render arm
      glPushMatrix();  // Remember - ARM
        glScalef(0.25f, 1.6f, 0.25f);
        cylinder.Render();
      glPopMatrix();  // Back to - ARM

      glTranslatef(0.0f, 1.75f, 0.0f);

      // render elbow
      glPushMatrix();  // Remember - ELBOW
        glScalef(0.25f, 0.25f, 0.25f);
        sphere.Render();
      glPopMatrix();  // Back to - ELBOW
      
      glRotatef(elbowXrotation, 1.0f, 0.0f, 0.0f);
      glTranslatef(0.0f, 0.2f, 0.0f);

      // render forearm
      glPushMatrix();  // Remember - FOREARM
        glScalef(0.25f, 1.6f, 0.25f);
        cylinder.Render();
      glPopMatrix();  // Back to - FOREARM

      glRotatef(wristYrotation, 0.0f, 1.0f, 0.0);
      glTranslatef(0.0f, 1.75f, 0.0f);

      // render wrist
      glPushMatrix();  // Remember - WRIST
        glScalef(0.25f, 0.25f, 0.25f);
        sphere.Render();
      glPopMatrix();  // Back to - WRIST
      //gluSphere(gluNewQuadric(), 0.25f, 20, 20);

      glPushMatrix();  // Remember - WRIST

        //Render Finger1
        glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
        drawFinger();

      glPopMatrix();  // Back to - WRIST
      glPushMatrix();  // Remember - WRIST

        //Render Finger2
        glRotatef(120,0,1,0);
        glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
        drawFinger();

      glPopMatrix();  // Back to - WRIST
      glPushMatrix();  // Remember - WRIST

        glRotatef(240.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
        drawFinger();

      glPopMatrix();  // Back to - WRIST

    glPopMatrix();  // Back to - SHOULDER

  glPopMatrix();  // Back to - INITIAL STATE

}

// ------------------------------------------------------------------------------

void Arm::drawFinger()
{
  glTranslatef(0.0f, 0.25f, 0.0f);

  // render proximal
  glPushMatrix();  // Remember - PROXIMAL
    glScalef(0.05f, 0.32f, 0.05f);
    cylinder.Render();
  glPopMatrix();  // Back to - PROXIMAL

  glTranslatef(0.0f, 0.35f, 0.0f);

  // render joint
  glPushMatrix();  // Remember - JOINT
    glScalef(0.05f, 0.05f, 0.05f);
    sphere.Render();
  glPopMatrix();  // Back to - JOINT
      
  glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
  glTranslatef(0.0f, 0.05f, 0.0f);

  // render distal
  glPushMatrix();  // Remember - DISTAL
    glScalef(0.05f, 0.32f, 0.05f);
    cylinder.Render();
  glPopMatrix();  // Back to - DISTAL

}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////















