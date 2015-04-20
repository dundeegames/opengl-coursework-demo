#include <assets/planets.h>
#include <system/macros.h>

void Planets::init()
{
  rotation = 0;
  rotation2 = 0;
  rotation3 = 0;
  speed = 15.0;

  fire = new Light(GL_LIGHT4);
  fire->init(L_POINT, COLOUR_RED, 1.0f, 1.5f, 0.0f, 0.0f);
  fire->setAttenuation(1.0f, 1.0f);

  ice = new Light(GL_LIGHT5);
  ice->init(L_POINT, COLOUR_LTBLUE, 1.0f, -1.5f, 0.0f, 0.0f);
  //ice->setAttenuation(1.0f, 0.2f);
  ice->setAttenuation(1.0f, 1.0f);


}

// -----------------------------------------------------------------------------

void Planets::update(float dt)
{
  rotation += (speed*3) * dt;
  rotation2 += (speed*2) * dt;
  rotation3 += speed * dt;
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
  glColor3f(1.0f, 1.0f, 1.0f);

}


// 80 //////////////////////////////////////////////////////////////////////////