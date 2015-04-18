#include <assets/light.h>


Light::Light(int id_)
{
  id = id_;
}


Light::~Light()
{


}

// -----------------------------------------------------------------------------

void Light::init(Light_Type tp, GLfloat R, GLfloat G, GLfloat B, GLfloat A,
                  GLfloat x, GLfloat y, GLfloat z)
{
  type = tp;

  Position[0] = x;
  Position[1] = y;
  Position[2] = z;

  if(tp == DIRECTIONAL)
  {
    Position[3] = 0.0f;
  }
  else
  {
    Position[3] = 1.0f;
  }



  Colour[0] = R;
  Colour[1] = G;
  Colour[2] = B;
  Colour[3] = A;

}

// -----------------------------------------------------------------------------

void Light::render()
{
  switch(type)
  {
  case AMBIENT:
    glLightfv(id, GL_AMBIENT,  Colour);
    break;

  case DIFFUSE:
    glLightfv(id, GL_DIFFUSE,  Colour);
    break;

  case DIRECTIONAL:
    glLightfv(id, GL_DIFFUSE,  Colour);
    break;



  default:
    break;

  }  
  
  glLightfv(id, GL_POSITION, Position);
  glEnable(id);


}



// 80 //////////////////////////////////////////////////////////////////////////

