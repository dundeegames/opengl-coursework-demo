////////////////////////////////////////////////////////////////////////////////
/**
* \file       planets.cpp
* \brief      Planets class - AG0800A Graphics Programming
*
* \details    Hierarchicaly animated spheres with animated point lights
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





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <assets/planets.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


void Planets::init(Input* in)
{
  input = in;

  rotation = 0;
  rotation2 = 0;
  rotation3 = 0;
  speed = 15.0;

  fire = new Light(GL_LIGHT4);
  fire->init(L_POINT, COLOUR_RED, 1.0f, 1.5f, 0.0f, 0.0f);
  fire->setAttenuation(1.0f, 0.2f);
  //fire->setAttenuation(2.0f, 1.0f, 0.5f);
  fire->setActive(true);

  ice = new Light(GL_LIGHT5);
  ice->init(L_POINT, COLOUR_LTBLUE, 1.0f, -1.5f, 0.0f, 0.0f);
  ice->setAttenuation(1.0f, 0.2f);
  //ice->setAttenuation(2.0f, 1.0f, 0.5f);
  ice->setActive(true);

}

// -----------------------------------------------------------------------------

void Planets::update(float dt)
{
  rotation += (speed*3) * dt;
  rotation2 += (speed*2) * dt;
  rotation3 += speed * dt;

  if(input->isBottonSelected(LBTN3_L_HANDLE))
  {
    fire->showHandle(true);
    ice->showHandle(true);
  }
  else
  {
    fire->showHandle(false);
    ice->showHandle(false);
  }




}

// -----------------------------------------------------------------------------

void Planets::render()
{
  glEnable(GL_BLEND);

  glPushMatrix();  // Remember - ORIGIN

    glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    fire->render();
    ice->render();

  glPopMatrix();  // Back to - ORIGIN
  glPushMatrix();  // Remember - ORIGIN

    // render the sun
    glColor4f(COLOUR_LTYELLOW, 1.0f);
    gluSphere(gluNewQuadric(), 0.40f, 40, 40);

    //render Elemental fire
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glTranslatef(1.5f, 0.0f, 0.0f);
    glColor4f(COLOUR_ORANGE, 0.5);
    gluSphere(gluNewQuadric(), 0.2, 20,20);

  glPopMatrix();  // Back to - ORIGIN
  glPushMatrix();  // Remember - ORIGIN

    // render Elemental ice
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f, 0.0f);
    glColor4f(COLOUR_LTBLUE, 0.5);
    gluSphere(gluNewQuadric(), 0.2f, 20, 20);

    glPushMatrix();  // Remember - ICE

      // Render a moon around planet 2
      glRotatef((rotation2*2.0f),0.0f, 1.0f, 0.0f);
      glTranslatef(1.5f, 0.0f, 0.0f);
      glColor4f(0.8f, 0.8f, 0.8f, 1.0f);
      gluSphere(gluNewQuadric(), 0.1f, 10, 10);

    glPopMatrix();  // Back to - ICE

  glPopMatrix();  // Back to - ORIGIN

  // going for a new planet and moons
  glPushMatrix();  // Remember - ORIGIN

    // render planet 3
    glRotatef(rotation3, 0.0f, 1.0f, 0.0f);
    glTranslatef(3.5f, 0.0f, 0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
    glColor3f(0.3f, 0.3f, 1.0f);
    gluSphere(gluNewQuadric(), 0.40f, 40, 40);

    glPushMatrix();  // Remember - PLANET3

      // Render a moon1 around planet 3
      glRotatef((rotation3*3.0f), 0.0f, 1.0f, 0.0f);
      glTranslatef(1.5f, 0.0f, 0.0f);
      glScalef(0.3f, 0.3f, 0.3f);
      glColor3f(0.8f, 0.8f, 0.8f);
      gluSphere(gluNewQuadric(), 0.40f, 40, 40);

    glPopMatrix();  // Back to - PLANET3
    glPushMatrix();  // Remember - PLANET3

      // Render a moon2 around planet 3
      glRotatef((rotation3*(-5.0f)), 0.0f, 1.0f, 0.0f);
      glTranslatef(2.5f, 0.0f, 0.0f);
      glScalef(0.4f, 0.4f, 0.4f);
      glColor3f(0.3f, 0.3f, 0.3f);
      gluSphere(gluNewQuadric(), 0.40f, 40, 40);

      // Render a moon3 around moon2
      glRotatef((rotation3*12.0f), 0.0f, 1.0f, 0.0f);
      glTranslatef(1.5f, 0.0f, 0.0f);
      glScalef(0.4f, 0.4f, 0.4f);
      glColor3f(0.5f, 1.0f, 0.5f);
      gluSphere(gluNewQuadric(), 0.40f, 40, 40);
      
    glPopMatrix();  // Back to - PLANET3
  glPopMatrix();  // Back to - ORIGIN


  glDisable(GL_BLEND);

  // reset colour
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////