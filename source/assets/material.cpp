////////////////////////////////////////////////////////////////////////////////
/**
* \file       material.cpp
* \brief      Material class - AG0800A Graphics Programming
*
* \details    Handles Ambient, Diffuse, Specularity, Shininess and Emission
*             of 3D object
*
* \author     Jiri Klic
* \version    1.0
* \date       April 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <assets/material.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


Material::Material()
{
  init();
}


Material::Material(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
  init();
  
  red = R;
  green = G;
  blue = B;
  alpha = A;
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
  glBindTexture(GL_TEXTURE_2D, texture);  //tells opengl which texture to use
  
  glPushAttrib(GL_LIGHTING_BIT | GL_ENABLE_BIT);

  glEnable(GL_BLEND);

  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_EMISSION, emission);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);

  glColor4f(red, green, blue, alpha);

  
}

// -----------------------------------------------------------------------------

void Material::cleanup()
{
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);      // reset colour
  glBindTexture(GL_TEXTURE_2D, NULL);     // reset texture
  glPopAttrib();                          // reset material parameters
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
  //face = GL_FRONT;

  GLfloat def_mat_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat def_mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
  GLfloat def_mat_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};
  GLfloat def_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};

  for(int i = 0; i < 3; i++)
  {
    ambient[i] = def_mat_ambient[i];
    diffuse[i] = def_mat_diffuse[i];
    specular[i] = def_mat_specular[i];
    emission[i] = def_mat_emission[i];
  }

  red = 1.0f;
  green = 1.0f;
  blue = 1.0f;
  alpha = 1.0f;

  shininess = 0.0f;
  texture = NULL;

}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////