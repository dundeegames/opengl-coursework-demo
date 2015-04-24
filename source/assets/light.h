////////////////////////////////////////////////////////////////////////////////
/**
* \file       light.h
* \brief      Light class - AG0800A Graphics Programming
*
* \details    Encapsulates the position and type of 3D light 
*
* \author     Jiri Klic
* \version    1.0
* \date       January 2015
* \pre        needs to activeted by
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


#ifndef LIGHT_H
#define LIGHT_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>


enum Light_Type {L_AMBIENT,
                 L_POINT,
                 L_DIRECTIONAL,
                 L_SPOT
                };


// CLASS ///////////////////////////////////////////////////////////////////////

class Light
{

public:
  Light(int id_);
  ~Light();
  void init(Light_Type tp, GLfloat R, GLfloat G, GLfloat B, GLfloat A,
            GLfloat posX = 0.0f, GLfloat posY = 0.0f, GLfloat posZ = 0.0f,
            GLfloat dirX = 0.0f, GLfloat dirY = 0.0f, GLfloat dirZ = 0.0f,
            float cut = 0.0f, float exp = 45.0f
            );

  void setSpecularity(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setAttenuation(GLfloat con = 1.0f, GLfloat lin = 0.0f, GLfloat quad = 0.0f);
  void showHandle(bool visible) {handleIsVisible = visible;}
  void setActive(bool actv) {active = actv;}

  void render();


private:
  GLfloat Colour[4];
  GLfloat Specular[4];
  GLfloat Position[4];
  GLfloat Direction[3];

  // attenuation
  GLfloat constant;
  GLfloat linear;
  GLfloat quadratic;


  float CutOff;
  float Exponent;

  int id;
  Light_Type type;

  bool active;
  bool handleIsVisible;

};


#endif // LIGHT_H




// 80 //////////////////////////////////////////////////////////////////////////