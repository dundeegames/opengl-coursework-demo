#include "geometry.h"


Geometry::Geometry()
{
  red = 0xff;
  green = 0xff;
  blue = 0xff;
  alpha = 0xff;
  myTexture = NULL;
}


Geometry::~Geometry()
{

}

// -----------------------------------------------------------------------------

void Geometry::loadTexture(const char* file)
{
   /*!
  * Load a PNG using the SOIL (Simple OpenGL Image  Library)
  */
  myTexture = SOIL_load_OGL_texture(file,
                SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );

}

// -----------------------------------------------------------------------------

void Geometry::setColor3f(GLfloat red_, GLfloat green_, GLfloat blue_)
{
  red = red_;
  green = green_;
  blue = blue_;

}

// -----------------------------------------------------------------------------

void Geometry::setColor4f(GLfloat red_, GLfloat green_, GLfloat blue_, GLfloat alpha_)
{
  red = red_;
  green = green_;
  blue = blue_;
  alpha = alpha_;

}

// -----------------------------------------------------------------------------

void Geometry::setPosition(float x_, float y_)
{
  positionX = x_;
  positionY = y_;
}

// -----------------------------------------------------------------------------

void Geometry::move(float x_, float y_)
{
  positionX = x_;
  positionY = y_;
}


// 80 //////////////////////////////////////////////////////////////////////////