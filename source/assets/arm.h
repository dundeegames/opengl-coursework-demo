////////////////////////////////////////////////////////////////////////////////
/**
* \file       arm.h
* \brief      Arm class - AG0800A Graphics Programming
*
* \details    Hierarchically modeled robotic arm, animated by user input
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


#ifndef ARM_H
#define ARM_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/input.h>
#include <assets/model.h>
#include <assets/material.h>
#include <assets/planets.h>
#include <system/modelgenerator.h>

enum State{ARM,
           ELBOW,
           WRIST
          };


// CLASS ///////////////////////////////////////////////////////////////////////

class Arm
{

public:
  void Init(Input* in, ModelGenerator* mg, Planets* plts);  //initialse function
  void update(float dt);
  void render();

private:
  float armXrotation, armYrotation;
  float elbowXrotation, elbowYrotation;
  float wristYrotation;
  float wristOpen;
  Planets* orbits;
  Model sphere;
  Model cylinder;

  Input* input;
  State state;
  float speed;

  void handleInput(float dt);
  void drawFinger();

};


#endif // ARM_H




// 80 //////////////////////////////////////////////////////////////////////////