#include <assets/light.h>
#include <system/macros.h>

Light::Light(int id_)
{
  id = id_;
  active = false;
  handleIsVisible = false;
  setAttenuation();
}


Light::~Light()
{


}

// -----------------------------------------------------------------------------

void Light::init(Light_Type tp, GLfloat R, GLfloat G, GLfloat B, GLfloat A,
                  GLfloat posX, GLfloat posY, GLfloat posZ,
                  GLfloat dirX, GLfloat dirY, GLfloat dirZ,
                  float cut, float exp)
{
  type = tp;

  Colour[0] = R;
  Colour[1] = G;
  Colour[2] = B;
  Colour[3] = A;

  Position[0] = posX;
  Position[1] = posY;
  Position[2] = posZ;

  if(tp == L_DIRECTIONAL)
  {
    Position[3] = 0.0f;
  }
  else
  {
    Position[3] = 1.0f;
  }

  Direction[0] = dirX;
  Direction[1] = dirY;
  Direction[2] = dirZ;

  CutOff = cut;
  Exponent = exp;
}

// -----------------------------------------------------------------------------

void Light::render()
{
  switch(type)
  {
  case L_AMBIENT:
    //glColor3f(COLOUR_DRKGRAY);
    glLightfv(id, GL_AMBIENT,  Colour);
    break;

  case L_POINT:
    //glColor3f(COLOUR_LTBLUE);
    glLightfv(id, GL_DIFFUSE,  Colour);
    break;

  case L_DIRECTIONAL:
    //glColor3f(COLOUR_YELLOW);
    glLightfv(id, GL_DIFFUSE,  Colour);
    break;

  case L_SPOT:
    //glColor3f(COLOUR_GREEN);
    glLightfv(id, GL_DIFFUSE,  Colour);
    glLightfv(id, GL_SPOT_DIRECTION, Direction);
    glLightf(id, GL_SPOT_CUTOFF, CutOff);
    glLightf(id, GL_SPOT_EXPONENT, Exponent);
    break;


  default:
    break;

  }  
  
  glLightfv(id, GL_POSITION, Position);

  glLightf(id, GL_CONSTANT_ATTENUATION, constant);
  glLightf(id, GL_LINEAR_ATTENUATION, linear);
  glLightf(id, GL_QUADRATIC_ATTENUATION, quadratic);

  if(active)
  {
    glEnable(id);
  }
  else
  {
    glDisable(id);
  }



  if(handleIsVisible)
  {
    glPushMatrix(); // REMEMBER WHERE WE ARE
      glTranslatef(Position[0], Position[1], Position[2]);     
      gluSphere(gluNewQuadric(), 0.05f, 16, 16);
    glPopMatrix();

  }

  glColor3f(COLOUR_WHITE);      // reset colour

}

// -----------------------------------------------------------------------------

void Light::setAttenuation(GLfloat con, GLfloat lin, GLfloat quad)
{
  constant = con;
  linear = lin;
  quadratic = quad;
}

// -----------------------------------------------------------------------------









// 80 //////////////////////////////////////////////////////////////////////////

