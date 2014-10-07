#ifndef _INPUT_H
#define _INPUT_H

// Input class

#include <Windows.h>

class Input
{

	typedef struct Mouse
	{
		int x,y;
		bool left, middle, right;
	};



public:
	void SetKeyDown(WPARAM);
	void SetKeyUp(WPARAM);

	bool isKeyDown(int);
	void setMouseX(int);
	void setMouseY(int);
	int getMouseX();
	int getMouseY();



	// add missing functions for handling mouse buttons etc

private:
	bool keys[256];
	Mouse mouse;

};

#endif