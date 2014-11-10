#ifndef ARM_H
#define ARM_H

// Arm class

#include "input.h"


enum State{ARM, ELBOW, WRIST};


class Arm
{
	float armXrotation, armYrotation;
	float elbowXrotation, elbowYrotation;
	float wristYrotation;
	float wristOpen;

public:
	void Init(Input*);	//initialse function
	void update();
	void render();

private:
	Input* input;
	State state;

	void handleInput();
	void drawCube();
	void drawFinger();

};


#endif