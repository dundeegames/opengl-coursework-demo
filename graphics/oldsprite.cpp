#include "oldsprite.h"

void OldSprite::Initialise(old_old_sprite_type type_, LPSTR filename, int xpos, int ypos, HDC* _bitmapBuf, HDC* _backBuf)
{
  type = type_;
  bitmapBuf = _bitmapBuf;
  backBuf = _backBuf;
  x = xpos;  // starting position
  y = ypos;  // starting position
  LoadABitmap(filename);  // load image
  if(!bitmap)
  {
    //failed to load image
    MessageBox(NULL, "Image fail to load", "Error", MB_OK);
  }

}


void OldSprite::LoadABitmap(LPSTR szFileName)
{
  bitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

  BITMAP temp;
  GetObject (bitmap, sizeof(temp), &temp);
  width = temp.bmWidth;
  height = temp.bmHeight;
}


void OldSprite::drawSprite()
{
  HBITMAP originalBitMap;

  //remember to add the bitmapHDC to scene.h
  originalBitMap = (HBITMAP)SelectObject(*bitmapBuf, bitmap);

  switch(type)
  {
  case NORMAL:
    // blt the image to the back buffer
    BitBlt(*backBuf, x, y, width, height, *bitmapBuf, 0, 0, SRCCOPY);
    break;

  case TRANSP:
    // TransparentBlt the image to the back buffer
    TransparentBlt (*backBuf, x, y, width, height, *bitmapBuf, 0, 0, width, height, RGB (255, 0, 255));
    break;

  case STRETCH:
    // StretchBlt the image to the back buffer
    StretchBlt(*backBuf, x,  y, width*2, height*2, *bitmapBuf, 0, 0,  width, height, SRCCOPY);
    break;

  case PLG:
    POINT pt[3];

    // it is stretching the image while rotating by 45deg.
    // better way would be to create rotate funtion and set pt parameters by sin and cos funtions
    // so the points are moved by hypotenuse and not by w/2 or h/2

    // also, if you create temBuffer in scene, you can combine the blts as follows
    // TransparentBlt bitmapBuf -> tempBuf
    // PlgBlt tempBuf -> backBuf

    //rotates image
    // move 0,0 to 
    pt[0].x = x;
    pt[0].y = y+height/2;
    // move width,0 to 
    pt[1].x = x+width/2;
    pt[1].y = y;
    // move 0,height to
    pt[2].x = x+width/2;
    pt[2].y = y+height;
    
    PlgBlt(*backBuf, pt, *bitmapBuf, 0, 0, width, height, NULL, 0, 0);
    break;

  default:
    break;

  }


  SelectObject(*bitmapBuf, originalBitMap); 
}