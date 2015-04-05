#include <assets/sprite.h>
#include <system/macros.h>

Sprite::Sprite()
{
  red = 0xff;
  green = 0xff;
  blue = 0xff;
  alpha = 0xff;
  myTexture = NULL;
}


Sprite::~Sprite()
{

}

// -----------------------------------------------------------------------------

void Sprite::setColor3f(GLfloat red_, GLfloat green_, GLfloat blue_)
{
  red = red_;
  green = green_;
  blue = blue_;

}

// -----------------------------------------------------------------------------

void Sprite::setColor4f(GLfloat red_, GLfloat green_, GLfloat blue_, GLfloat alpha_)
{
  red = red_;
  green = green_;
  blue = blue_;
  alpha = alpha_;

}

// -----------------------------------------------------------------------------

void Sprite::setPosition(float x_, float y_)
{
  positionX = x_;
  positionY = y_;
}

// -----------------------------------------------------------------------------

void Sprite::move(float x_, float y_)
{
  positionX = x_;
  positionY = y_;
}

// -----------------------------------------------------------------------------

void Sprite::set_uv_position(float x_, float y_)
{
  uv_posX = x_;
  uv_posY = y_;
}


// -----------------------------------------------------------------------------

void Sprite::setValues(GLuint tex_, float x_, float y_, float w_, float h_,
                              float uvx_, float uvy_, float uvw_, float uvh_)
{

  myTexture = tex_;
  positionX = x_;
  positionY = y_;

  width = w_;
  height = h_;
  
  uv_posX = uvx_;
  uv_posY = uvy_;
  uv_width = uvw_;
  uv_height = uvh_;

}

// -----------------------------------------------------------------------------

void Sprite::setDList()
{

  glNewList(DisplayList, GL_COMPILE);    // Like glBegin and End

    glBegin(GL_TRIANGLES);
      glTexCoord2f(uv_posX, uv_posY);
      glVertex2f(positionX, positionY);
 
      glTexCoord2f(uv_posX, (uv_posY + uv_height));
      glVertex2f(positionX, (positionY + height));

      glTexCoord2f( (uv_posX + uv_width), (uv_posY + uv_height));
      glVertex2f( (positionX + width), (positionY + height));

      glTexCoord2f( (uv_posX + uv_width), (uv_posY + uv_height));
      glVertex2f( (positionX + width), (positionY + height));
 
      glTexCoord2f( (uv_posX + uv_width), uv_posY);
      glVertex2f( (positionX + width), positionY);

      glTexCoord2f(uv_posX, uv_posY);
      glVertex2f(positionX, positionY);
    glEnd();

  glEndList();

}

// -----------------------------------------------------------------------------

void Sprite::setVArrays()
{



}

// -----------------------------------------------------------------------------

void Sprite::draw()
{
  glColor4f(red, green, blue, alpha);
  glBindTexture(GL_TEXTURE_2D, myTexture);  //tells opengl which texture to use

  glBegin(GL_TRIANGLES);
   glTexCoord2f(uv_posX, uv_posY);
   glVertex2f(positionX, positionY);
 
   glTexCoord2f(uv_posX, (uv_posY + uv_height));
   glVertex2f(positionX, (positionY + height));

   glTexCoord2f( (uv_posX + uv_width), (uv_posY + uv_height));
   glVertex2f( (positionX + width), (positionY + height));

   glTexCoord2f( (uv_posX + uv_width), (uv_posY + uv_height));
   glVertex2f( (positionX + width), (positionY + height));
 
   glTexCoord2f( (uv_posX + uv_width), uv_posY);
   glVertex2f( (positionX + width), positionY);

   glTexCoord2f(uv_posX, uv_posY);
   glVertex2f(positionX, positionY);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL
  glColor4f(COLOUR_WHITE, 1.0f);        // reset colour

}

// 80 //////////////////////////////////////////////////////////////////////////