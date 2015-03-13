#ifndef ARM_H
#define ARM_H

// Arm class

#include <ui/input.h>


enum State{ARM, ELBOW, WRIST};


class Arm
{
  float armXrotation, armYrotation;
  float elbowXrotation, elbowYrotation;
  float wristYrotation;
  float wristOpen;

public:
  void Init(Input*);  //initialse function
  void update(float dt);
  void render();

private:
  Input* input;
  State state;
  float speed;

  void handleInput(float dt);
  void drawCube();
  void drawFinger();

};


#endif