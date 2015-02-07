// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                   Font class - WinAPI and OpenGL laboratory                 \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
* Based on Font class from Abertay Framework for PS Vita                      \n
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
#include <cassert>    // assert

#include <windows.h>     // Header File For Windows
#include <math.h>        // Header File For Windows Math Library
#include <stdio.h>       // Header File For Standard Input/Output
#include <stdarg.h>      // Header File For Variable Argument Routines
#include <gl\gl.h>       // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library
#include "include/SOIL.h"

#define	FONT_MAX_ASCII	256
#define	FONT_MAX_LINE	1024
#define	FONT_MAX_PATH	256


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

  // TODO add support for colour 
  void RenderText(float x_, float y_, float scale, const TextJustification justification, const char * text, ...);
  //void BuildText(HDC* hdc_);
  //void KillFont();
  //void print(const char* fmt);

private:
	CharacterSet charSet;
	GLuint myTexture;
  GLuint base_list;

	bool ParseFont( std::istream& Stream, CharacterSet& CharsetDesc );
  float Font::GetStringLength(const char * text);
  void compileText();


  //HDC*      hDC;       // Private GDI Device Context

  //GLuint  base;            // Base Display List For The Font Set
  //GLfloat  cnt1;           // 1st Counter Used To Move Text & For Coloring
  //GLfloat  cnt2;           // 2nd Counter Used To Move Text & For Coloring

  //bool  keys[256];         // Array Used For The Keyboard Routine
  //bool  active;            // Window Active Flag Set To TRUE By Default
  //bool  fullscreen;        // Fullscreen Flag Set To Fullscreen Mode By Default



};


#endif // FONT_H




// 80 //////////////////////////////////////////////////////////////////////////