#ifndef _SCENE_H
#define _SCENE_H


#include <Windows.h>
#include <MMSystem.h>
#include <math.h>

#include "input.h"
#include "oldsprite.h"

class Scene
{
  //bitmapHDC;

public:
  void Initialise(HWND*, Input*);
  void update();
  void displayFrame();
  void render();
  void resize();
  void shutdown();
  void setBuffers();
  //void drawSprite(Sprite theSprite);

private:

  BOOL WaitFor(unsigned long);


  HWND *hwnd;              // pointer to the window
  Input *myInput;            // pointer to the input class
  HBITMAP theOldFrontBitMap;
  RECT screenRect;    
  HDC backHDC, frontHDC, bitmapHDC;  // Buffers

  OldSprite mySprite, wallPaper;



  int ticker;

};







#endif