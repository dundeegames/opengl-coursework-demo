////////////////////////////////////////////////////////////////////////////////
/**
* \file       font.h
* \brief      Font class - AG0800A Graphics Programming
*
* \details    Based on Font class from Abertay Framework for PS Vita
*             provided during exercise for AG0801A Console Game Development
*
* \author     Jiri Klic
* \author     Grant Clark
* \version    2.0
* \date       January 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo
*
* \copyright  Grant Clark.[2015].Abertay Framework.AG0801A Console Game Development
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////


#ifndef FONT_H
#define FONT_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <iostream>         // std::ios, std::istream, std::cout
#include <fstream>          // std::filebuf
#include <string>
#include <sstream>
#include <cassert>          // assert

#include <windows.h>        // Header File For Windows
#include <gl\gl.h>          // Header File For The OpenGL32 Library
#include <gl\glu.h>         // Header File For The GLu32 Library
#include <soil/SOIL.h>

#define  FONT_MAX_ASCII  256
#define  FONT_MAX_LINE  1024
#define  FONT_MAX_PATH  256

// -----------------------------------------------------------------------------

struct Colour
{
  float R;
  float G;
  float B;
  float A;
  Colour(float r_, float g_, float b_, float a_)
  {
    R = r_;
    G = g_;
    B = b_;
    A = a_;
  }

};


// CLASS ///////////////////////////////////////////////////////////////////////

class Font
{

struct CharDescriptor
{

  int x, y;
  int Width, Height;
  int XOffset, YOffset;
  int XAdvance;
  int Page;

  CharDescriptor() : x( 0 ), y( 0 ), Width( 0 ), Height( 0 ), XOffset( 0 ), YOffset( 0 ),
    XAdvance( 0 ), Page( 0 )
  { }
};


struct CharacterSet
{
  int LineHeight;
  int Base;
  int Width, Height;
  int Pages;
  CharDescriptor Chars[256];
};


public:
  Font();
  ~Font();

  bool Load(const char* font_name);

  void RenderText(Colour colour, float x_, float y_,
                  float scale, const char * text, ...);


private:
  CharacterSet charSet;
  GLuint myTexture;
  GLuint base_list;

  bool ParseFont( std::istream& Stream, CharacterSet& CharsetDesc );
  float Font::GetStringLength(const char * text);
  void compileText();

};


#endif // FONT_H




// 80 //////////////////////////////////////////////////////////////////////////