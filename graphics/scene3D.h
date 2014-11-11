#ifndef SCENE3D_H
#define SCENE3D_H

#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "input.h"
#include "arm.h"
#include "planets.h"

#define COLOUR_DEPTH 16	//Colour depth

class Scene3D
{
	typedef struct Camera
	{
		GLdouble x, y, z;
		GLdouble theta, phi;
		GLdouble distance;
	};

	float rotation, rotation2, rotation3, speed;
	//GLfloat Light_Ambient[4];
	//GLfloat Light_Diffuse[4];
	//GLfloat Light_Position[4];





public:
	void Init(HWND*, Input*);	//initialse function
	void DrawScene(float);	// render scene
	void Resize();

protected:
	bool CreatePixelFormat(HDC);
	void ResizeGLWindow(int, int);	//width and height
	void InitializeOpenGL(int, int); // width and height
	void HandleInput(float dt);

	//vars
	HWND* hwnd;
	Input* input;
	RECT screenRect;
	HDC	hdc;
	HGLRC hrc;			//hardware RENDERING CONTEXT
	int s_wdith, s_height;

private:
	Camera camera;
	Arm robotArm;
	//Planets solarSystem;
	void drawCube();
	void drawFinger();
};

#endif
