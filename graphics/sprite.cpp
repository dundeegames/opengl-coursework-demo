#include "sprite.h"


Sprite::Sprite()
{
  setDList();
}


Sprite::~Sprite()
{

}

// -----------------------------------------------------------------------------

void Sprite::setDList()
{

  glNewList(DisplayList, GL_COMPILE);    // Like glBegin and End

    glBegin(GL_TRIANGLES);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);

    glEnd();

  glEndList();

}

// -----------------------------------------------------------------------------

void Sprite::draw()
{
  glBindTexture(GL_TEXTURE_2D, myTexture);  //tells opengl which texture to use
  // front face
  glColor4f(red, green, blue, alpha);

    glCallList(DisplayList);

  glColor3f(1.0f, 1.0f, 1.0f); // reset colour
  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL

}

// 80 //////////////////////////////////////////////////////////////////////////