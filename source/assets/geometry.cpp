#include <assets/geometry.h>


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

// -----------------------------------------------------------------------------

void Geometry::set_uv_position(float x_, float y_)
{
  uv_posX = x_;
  uv_posY = y_;
}



// 80 //////////////////////////////////////////////////////////////////////////