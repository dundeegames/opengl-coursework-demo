#ifndef INPUT_H
#define INPUT_H

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

	Input();

	void SetKeyDown(WPARAM);
	void SetKeyUp(WPARAM);

	bool isKeyDown(int);

	void setMouseX(int);
	void setMouseY(int);
	int getMouseX();
	int getMouseY();

	void setLeftMouseBtn(bool l);
	void setMiddleMouseBtn(bool m);
	void setRightMouseBtn(bool r);

	bool leftMouseBtn();
	bool middleMouseBtn();
	bool rightMouseBtn();

	// set mouse botton down (left, right, middle)
	// set mouse botton up

	// add missing functions for handling mouse buttons etc

private:
	bool keys[256];
	Mouse mouse;

};

#endif