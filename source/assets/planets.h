////////////////////////////////////////////////////////////////////////////////
/**
* \file       planets.h
* \brief      Planets class - AG0800A Graphics Programming
*
* \details    Hierarchicaly animated spheres with animated point lights
*
* \author     Jiri Klic
* \version    1.0
* \date       January 2015
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


#ifndef PLANETS_H
#define PLANETS_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <assets/light.h>
#include <ui/input.h>


// CLASS ///////////////////////////////////////////////////////////////////////

class Planets
{

public:
  void init(Input* in);
  void update(float dt);
  void render();

private:
  float rotation;
  float rotation2;
  float rotation3;
  float speed;

  Light* fire;
  Light* ice;
  Input* input;

};


#endif // PLANETS_H




// 80 //////////////////////////////////////////////////////////////////////////
