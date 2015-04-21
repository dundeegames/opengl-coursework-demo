#include <assets/material.h>
#include <system/macros.h>


Material::Material()
{
  init();
}


Material::Material(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
  init();
  setDiffuse(R, G, B, A);
}


Material::Material(GLuint tex)
{
  init();
  setTexture(tex);
}


Material::~Material()
{

}

// -----------------------------------------------------------------------------

Material& Material::operator=(const Material& m2)
{
  for(int i = 0; i < 4; i++)
  {
    this->ambient[i] = m2.ambient[i];
    this->diffuse[i] = m2.diffuse[i];
    this->specular[i] = m2.specular[i];
    this->emission[i] = m2.emission[i];
  }

  this->shininess = m2.shininess;
  this->texture = m2.texture;

  return *this;
}

// -----------------------------------------------------------------------------

void Material::render()
{
  glMaterialfv(face, GL_AMBIENT, ambient);
  glMaterialfv(face, GL_DIFFUSE, diffuse);
  glMaterialfv(face, GL_SPECULAR, specular);
  glMaterialfv(face, GL_SHININESS, emission);
  glMaterialfv(face, GL_EMISSION, &shininess);

  glBindTexture(GL_TEXTURE_2D, texture);  //tells opengl which texture to use

}

// -----------------------------------------------------------------------------

void Material::setAmbient(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
  ambient[0] = R;
  ambient[1] = G;
  ambient[2] = B;
  ambient[3] = A;
}

// -----------------------------------------------------------------------------

void Material::setDiffuse(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
  diffuse[0] = R;
  diffuse[1] = G;
  diffuse[2] = B;
  diffuse[3] = A;
}

// -----------------------------------------------------------------------------

void Material::setSpecular(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
  specular[0] = R;
  specular[1] = G;
  specular[2] = B;
  specular[3] = A;
}

// -----------------------------------------------------------------------------

void Material::setEmission(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
  emission[0] = R;
  emission[1] = G;
  emission[2] = B;
  emission[3] = A;
}

// -----------------------------------------------------------------------------

void Material::init()
{
  face = GL_FRONT;

  for(int i = 0; i < 3; i++)
  {
    ambient[i] = 0.2f;
    diffuse[i] = 0.8f;
    specular[i] = 0.0f;
    emission[i] = 0.0f;
  }
  ambient[3] = 1.0f;
  diffuse[3] = 1.0f;
  specular[3] = 1.0f;
  emission[3] = 1.0f;

  shininess = 0.0f;
  texture = NULL;

}

// -----------------------------------------------------------------------------













// 80 //////////////////////////////////////////////////////////////////////////