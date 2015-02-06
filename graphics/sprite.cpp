#include "sprite.h"


Sprite::Sprite()
{

}


Sprite::~Sprite()
{

}

// -----------------------------------------------------------------------------

void Sprite::draw()
{

  glBindTexture(GL_TEXTURE_2D, myTexture);	//tells opengl which texture to use

  glBegin(GL_TRIANGLES);

    // front face
    glColor4f(red, green, blue, alpha);

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

    glColor3f(1.0f, 1.0f, 1.0f); // reset colour

  glEnd();


  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL

}

// 80 //////////////////////////////////////////////////////////////////////////