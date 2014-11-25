#ifndef CAMERA_H
#define CAMERA_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "input.h"
#include "vec3.h"



enum Type {FIXED_POINT, ROTATING, SCROLLING, MOVEABLE, FLOATING, TRACKING, THIRD_PERSON, FIRST_PERSON};

#define PI 3.1415

class Camera
{

public:
	Camera();
	~Camera();

	void init();
	void update(float dt);
	void handleInput(Input* in);
	Vec3 getPosition();
	Vec3 getRotation();



private:
	Vec3 position;
	Vec3 rotation;			// Pitch (Rotation around x- axis), Yaw (Rotation around y-axis), Roll (Rotation around z-axis)

	Vec3 forward;			// LookAt = position + forward
	Vec3 up;
	Vec3 right;

	Type type;

};


#endif