// Input class
// Paul Robertson 2014

#include "input.h"



Input::Input()
{
  mouse.x = 0;
  mouse.y = 0;
  mouse.left = false;
  mouse.middle = false;
  mouse.right = false;

  sensitivity = 2.5f;

  // set all keys to UP
  for(int i = 0; i < 256; i++)
  {
    keys[i] = false;
  }
}

void Input::SetKeyDown(WPARAM key)
{
  keys[key] = true;
}

void Input::SetKeyUp(WPARAM key)
{
  keys[key] = false;
}

bool Input::isKeyDown(int key)
{
  return keys[key];
}


void Input::setMouseX(int pos)
{
  mouse.x = pos;
}

void Input::setMouseY(int pos)
{
  mouse.y = pos;
}

int Input::getMouseX()
{
  return mouse.x;
}

int Input::getMouseY()
{
  return mouse.y;
}



void Input::setLeftMouseBtn(bool l)
{
  mouse.left = l;
}

void Input::setMiddleMouseBtn(bool m)
{
  mouse.middle = m;
}

void Input::setRightMouseBtn(bool r)
{
  mouse.right = r;
}

bool Input::leftMouseBtn()
{
  return mouse.left;
}

bool Input::middleMouseBtn()
{
  return mouse.middle;
}

bool Input::rightMouseBtn()
{
  return mouse.right;
}


float Input::getSensitivity()
{
  return sensitivity;
}

