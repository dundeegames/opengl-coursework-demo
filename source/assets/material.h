////////////////////////////////////////////////////////////////////////////////
/**
* \file       material.h
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


#ifndef MATERIAL_H
#define MATERIAL_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>



// CLASS ///////////////////////////////////////////////////////////////////////

class Material
{

public:
  Material();
  Material(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  Material(GLuint tex);

  ~Material();
  Material& operator=(const Material& m2);

  void render();
  void cleanup();

  void setAmbient(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setDiffuse(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setSpecular(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setEmission(GLfloat R, GLfloat G, GLfloat B, GLfloat A);

  void setShininess(GLfloat shin) {shininess = shin;}
  void setTexture(GLuint tex) {texture = tex;}
  void setFace(GLenum face_) {face = face_;}

private:
  GLenum face;
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat emission[4];

  // actual colour the diffuse is not working
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat alpha;

  GLfloat shininess;
  GLuint texture;




  void init();

};


#endif // TEMP_H




// 80 //////////////////////////////////////////////////////////////////////////