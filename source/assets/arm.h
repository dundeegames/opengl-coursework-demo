// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                   Arm class - WinAPI and OpenGL laboratory                  \n
*                             by Jiri Klic, Apr 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef ARM_H
#define ARM_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/input.h>
#include <assets/model.h>
#include <assets/planets.h>
#include <system/modelgenerator.h>

enum State{ARM, ELBOW, WRIST};



// CLASS ///////////////////////////////////////////////////////////////////////

class Arm
{

public:
  void Init(Input* in, ModelGenerator* mg);  //initialse function
  void update(float dt);
  void render();

private:
  float armXrotation, armYrotation;
  float elbowXrotation, elbowYrotation;
  float wristYrotation;
  float wristOpen;
  Planets orbits;

  Input* input;
  ModelGenerator* modelGen;
  State state;
  float speed;

  void handleInput(float dt);
  void drawCube();
  void drawFinger();

};


#endif // ARM_H




// 80 //////////////////////////////////////////////////////////////////////////