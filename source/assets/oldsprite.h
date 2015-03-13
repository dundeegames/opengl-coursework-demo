// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                 OldSprite class - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*   Used in 2D scene                                                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef OLD_SPRITE_H
#define OLD_SPRITE_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <MMSystem.h>
#include <stdio.h>



enum old_old_sprite_type {NORMAL, TRANSP, STRETCH, PLG};



class OldSprite
{

  old_old_sprite_type type;
  HDC* bitmapBuf;
  HDC* backBuf;

public:
  // function handles loading image and setting default x, y position
  void Initialise(old_old_sprite_type, LPSTR, int, int, HDC* _bitmapBuf, HDC* _backBuf);

  int x, y, width, height;    // variables for storing position and size
  HBITMAP bitmap;          // variable for storing handle to image

  void drawSprite();

private:
  void LoadABitmap(LPSTR);    // function for loading bitmap

};


#endif // OLD_SPRITE_H



// 80 //////////////////////////////////////////////////////////////////////////