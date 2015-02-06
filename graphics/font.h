// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                   Font class - WinAPI and OpenGL laboratory                 \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
* Inspired by Font class from Abertay Framework for PS Vita                   \n
* Mr. Grant Clark.[2015].Abertay Framework.Console Game Development           \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef FONT_H
#define FONT_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <iostream>   // std::ios, std::istream, std::cout
#include <fstream>    // std::filebuf
#include <string>
#include <sstream>

#include "sprite.h"


enum TextJustification
{
	TJ_LEFT = 0,
	TJ_CENTRE,
	TJ_RIGHT,
};



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


struct Charset
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

  // TODO add support for colour 
  void RenderText(float x_, float y_, float scale, const TextJustification justification, const char * text, ...);



private:
	Charset character_set;
	GLuint myTexture;

	bool ParseFont( std::istream& Stream, Charset& CharsetDesc );

};


#endif // FONT_H




// 80 //////////////////////////////////////////////////////////////////////////