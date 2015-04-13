#include <assets/sprite.h>
#include <system/macros.h>

Sprite::Sprite()
{
  red = 0xff;
  green = 0xff;
  blue = 0xff;
  alpha = 0xff;
  myTexture = NULL;

  setValues();
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

  calculateVerts();
}

// -----------------------------------------------------------------------------

void Sprite::move(float x_, float y_)
{
  positionX = x_;
  positionY = y_;

  calculateVerts();
}

// -----------------------------------------------------------------------------

void Sprite::set_uv_position(float x_, float y_)
{
  uv_posX = x_;
  uv_posY = y_;

  calculateUVs();
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

  calculateVerts();
  calculateUVs();
}

// -----------------------------------------------------------------------------

/**
* Calculate the vertex array values
*/
void Sprite::calculateVerts()
{
  vertices[0] = positionX;
  vertices[1] = positionY;
  vertices[2] = positionX;
  vertices[3] = (positionY + height);
  vertices[4] = (positionX + width);
  vertices[5] = (positionY + height);
  vertices[6] = (positionX + width);
  vertices[7] = (positionY + height);
  vertices[8] = (positionX + width);
  vertices[9] = positionY;
  vertices[10] = positionX;
  vertices[11] = positionY;

}

// -----------------------------------------------------------------------------

/**
* Calculate the uvs array values
*/
void Sprite::calculateUVs()
{
  uvs[0] = uv_posX;
  uvs[1] = uv_posY;
  uvs[2] = uv_posX;
  uvs[3] = (uv_posY + uv_height);
  uvs[4] = (uv_posX + uv_width);
  uvs[5] = (uv_posY + uv_height);
  uvs[6] = (uv_posX + uv_width);
  uvs[7] = (uv_posY + uv_height);
  uvs[8] = (uv_posX + uv_width);
  uvs[9] = uv_posY;
  uvs[10] = uv_posX;
  uvs[11] = uv_posY;

}

// -----------------------------------------------------------------------------

void Sprite::draw()
{
  glColor4f(red, green, blue, alpha);
  glBindTexture(GL_TEXTURE_2D, myTexture);    //tells opengl which texture to use


  // enble and specify pointers to vertex arrays
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);

  glVertexPointer (2, GL_FLOAT, 0, vertices);
  glTexCoordPointer(2, GL_FLOAT, 0, uvs);
  glDrawArrays(GL_TRIANGLES, 0, VERTEX_COUNT);

  // disable vertex arrays
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);


  glBindTexture(GL_TEXTURE_2D, NULL);         //set texture to NULL
  glColor4f(COLOUR_WHITE, 1.0f);              // reset colour

}

// 80 //////////////////////////////////////////////////////////////////////////