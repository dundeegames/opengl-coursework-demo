#ifndef _SPRITE_H
#define _SPRITE_H

#include <Windows.h>
#include <MMSystem.h>
#include <stdio.h>



enum sprite_type {NORMAL, TRANSP, STRETCH, PLG};



class Sprite
{

  sprite_type type;
  HDC* bitmapBuf;
  HDC* backBuf;

public:
  // function handles loading image and setting default x, y position
  void Initialise(sprite_type, LPSTR, int, int, HDC* _bitmapBuf, HDC* _backBuf);

  int x, y, width, height;    // variables for storing position and size
  HBITMAP bitmap;          // variable for storing handle to image

  void drawSprite();

private:
  void LoadABitmap(LPSTR);    // function for loading bitmap

};
#endif