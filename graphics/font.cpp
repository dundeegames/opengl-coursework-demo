#include "font.h"


Font::Font()
{
  myTexture = NULL;

  //hDC=NULL;
  //active = TRUE;    
  //fullscreen = TRUE;
}


Font::~Font()
{
  glDeleteLists(base_list, FONT_MAX_ASCII);
	glDeleteTextures(1, &myTexture);
}


// -----------------------------------------------------------------------------

bool Font::Load(const char* font_name)
{
  std::string fileName = font_name;
  fileName += ".fnt";

  std::filebuf buffer;

  if (buffer.open (fileName.c_str(), std::ios::in) )
  {
    std::istream font_stream(&buffer);
    bool success = ParseFont(font_stream, charSet);
 
    assert(success == true);
    if(success == false)
    {

      buffer.close();
      return false;
    }
    else
    {
      buffer.close();
    }

  }
  else
  {
    return false;
  }
  

  std::string textureName(font_name);
  textureName += "_0.png";

  /*!
  * Load a PNG using the SOIL (Simple OpenGL Image  Library)
  */
  myTexture = SOIL_load_OGL_texture(textureName.c_str(),
                SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );

  if(myTexture == NULL)
  {
    return false;
  }  

  compileText();
  return true;

}

// -----------------------------------------------------------------------------

bool Font::ParseFont( std::istream& Stream, CharacterSet& CharsetDesc )
{
  std::string Line;
  std::string Read, Key, Value;
  std::size_t i;
  while( !Stream.eof() )
  {
    std::stringstream LineStream;
    std::getline( Stream, Line );
    LineStream << Line;

    //read the line's type
    LineStream >> Read;
    if( Read == "common" )
    {
      //this holds common data
      while( !LineStream.eof() )
      {
        std::stringstream Converter;
        LineStream >> Read;
        i = Read.find( '=' );
        Key = Read.substr( 0, i );
        Value = Read.substr( i + 1 );

        //assign the correct value
        Converter << Value;
        if( Key == "lineHeight" )
          Converter >> CharsetDesc.LineHeight;
        else if( Key == "base" )
          Converter >> CharsetDesc.Base;
        else if( Key == "scaleW" )
          Converter >> CharsetDesc.Width;
        else if( Key == "scaleH" )
          Converter >> CharsetDesc.Height;
        else if( Key == "pages" )
          Converter >> CharsetDesc.Pages;
      }
    }
    else if( Read == "char" )
    {
      //this is data for a specific char
      unsigned short CharID = 0;

      while( !LineStream.eof() )
      {
        std::stringstream Converter;
        LineStream >> Read;
        i = Read.find( '=' );
        Key = Read.substr( 0, i );
        Value = Read.substr( i + 1 );

        //assign the correct value
        Converter << Value;
        if( Key == "id" )
          Converter >> CharID;
        else if( Key == "x" )
          Converter >> CharsetDesc.Chars[CharID].x;
        else if( Key == "y" )
          Converter >> CharsetDesc.Chars[CharID].y;
        else if( Key == "width" )
          Converter >> CharsetDesc.Chars[CharID].Width;
        else if( Key == "height" )
          Converter >> CharsetDesc.Chars[CharID].Height;
        else if( Key == "xoffset" )
          Converter >> CharsetDesc.Chars[CharID].XOffset;
        else if( Key == "yoffset" )
          Converter >> CharsetDesc.Chars[CharID].YOffset;
        else if( Key == "xadvance" )
          Converter >> CharsetDesc.Chars[CharID].XAdvance;
        else if( Key == "page" )
          Converter >> CharsetDesc.Chars[CharID].Page;
      }
    }
  }

  return true;
}

// -----------------------------------------------------------------------------

void Font::RenderText(float posX, float posY, float scale, const TextJustification justification, const char * text, ...)
{
  assert(text != NULL);
  if(!text)
  {
    return;
  }

  //glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();

  ////gluOrtho2D(left, right, bottom, top);
  //glOrtho(0.0f, 800.0f, 600.0f, 0.0f, 1.0f ,150.0f);

  //glMatrixMode(GL_MODELVIEW);   // Select The Modelview Matrix
  //glLoadIdentity();             // Reset The Modelview Matrix

	// invert y axis since OpenGL uses it updown
	//glScalef(1.0f, -1.0f, 1.0f);
	//glTranslatef(0.0f, -600.0f, 0.0f);

//bmf

  glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT  | GL_ENABLE_BIT | GL_TRANSFORM_BIT);	
  glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glListBase(base_list);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //gluOrtho2D(left, right, bottom, top);
  glOrtho(0.0f, 800.0f, 600.0f, 0.0f, 1.0f ,150.0f);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();             // Reset The Modelview Matrix


  //set camera looking down the -z axis,  6 units away from the center
  gluLookAt(0, 0, 10,     0, 0, 0,     0, 1, 0); //Where we are, What we look at, and which way is up
  glBindTexture(GL_TEXTURE_2D, myTexture);  // tells opengl which texture to use

  //va_list args;
  //char text_buffer[256];

  //va_start(args, text);
  //std::vsprintf(text_buffer, text, args);

  //int character_count = strlen(text_buffer);
  //float string_length = GetStringLength(text_buffer);


  //switch(justification)
  //{
  //case TJ_CENTRE:
  //  posX -= string_length*0.5f*scale;
  //  break;

  //case TJ_RIGHT:
  //  posX -= string_length*scale;
  //  break;

  //default:
  //  break;
  //}

  int count = strlen(text);
  //glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  glTranslatef(posX,posY,0);
    glScalef(scale, scale, 1.f);
  glCallLists(count, GL_UNSIGNED_BYTE, text);  


  glBindTexture(GL_TEXTURE_2D, NULL);  // tells opengl which texture to use
  glPopAttrib();

}

// -----------------------------------------------------------------------------

float Font::GetStringLength(const char * text)
{
  float length = 0.0f;

  if(text)
  {
    int string_length = strlen(text);


    for( int i = 0; i < string_length; ++i )
      length += ( (float)charSet.Chars[(int)(text[i])].XAdvance );
  }

  return length;
}

// -----------------------------------------------------------------------------

void Font::compileText()
{
  // compile all charset characters into display lists
//	if(!text)
//		return;
//
//	va_list args;
//	char text_buffer[256];
//
//	va_start(args, text);
//	std::vsprintf(text_buffer, text, args);
//
//	UInt32 character_count = strlen(text_buffer);
//	float string_length = GetStringLength(text_buffer); // returns width of string in pixels
//
//	Vector2 cursor = Vector2(pos.x, pos.y);
//
//	switch(justification)
//	{
//	case TJ_CENTRE:
//		cursor.x -= string_length*0.5f*scale;
//		break;
//	case TJ_RIGHT:
//		cursor.x -= string_length*scale;
//		break;
//	default:
//		break;
//	}
//
//	Sprite sprite;
//	sprite.set_texture(font_texture_);
//	for( UInt32 character_index = 0; character_index < character_count; ++character_index )
//	{
  //  int CharX   = character_set.Chars[(int)(text_buffer[character_index])].x;
		//int CharY   = character_set.Chars[(int)(text_buffer[character_index])].y;
		//int Width   = character_set.Chars[(int)(text_buffer[character_index])].Width;
		//int Height  = character_set.Chars[(int)(text_buffer[character_index])].Height;
		//int OffsetX = character_set.Chars[(int)(text_buffer[character_index])].XOffset;
		//int OffsetY = character_set.Chars[(int)(text_buffer[character_index])].YOffset;

		//Vector2 uv_pos((float) CharX / (float) character_set.Width,  ((float) (CharY) / (float) character_set.Height));
		//Vector2 uv_size((float) (Width) / (float) character_set.Width, (float)(Height) / (float) character_set.Height);
		//Vector2 size(((float)Width)*scale, ((float)Height)*scale);
		//Vector3 sprite_position = Vector3(cursor.x+((float)OffsetX*scale)+size.x*0.5f, cursor.y + scale*((float)Height*0.5f +  (float)OffsetY), pos.z);

		//sprite.set_position(sprite_position);
		//sprite.set_width(size.x);
		//sprite.set_height(size.y);
		//sprite.set_uv_position(uv_pos);
		//sprite.set_uv_width(uv_size.x);
		//sprite.set_uv_height(uv_size.y);
		//sprite.set_colour(colour);
		//renderer->DrawSprite(sprite);
		//cursor.x += ((float)character_set.Chars[static_cast<UInt32>(text_buffer[character_index])].XAdvance)*scale;
//	}
//}




  base_list = glGenLists(FONT_MAX_ASCII);   // create display lists
  glBindTexture(GL_TEXTURE_2D, myTexture);  // tells opengl which texture to use

  //float UV_X = 0;
  //float UV_Y = 0;
  //float UV_W = 0;
  //float UV_H = 0;
  //float OFF_X = 0;
  //float OFF_X = 0;

  for (int ch = 0; ch < FONT_MAX_ASCII; ch++)
  {
    glNewList( (base_list + ch), GL_COMPILE);

    if (charSet.Chars[ch].Width) {

      

      glBegin(GL_TRIANGLES);
        //glTexCoord2f( , );
        //glVertex2f( , );

        //glTexCoord2f( , );
        //glVertex2f( , );

        //glTexCoord2f( , );
        //glVertex2f( , );

        //glTexCoord2f( , );
        //glVertex2f( , );

 



        glTexCoord2f(  (float)charSet.Chars[ch].x / (float)charSet.Width,
          ( (float)(charSet.Chars[ch].y + charSet.Chars[ch].Height) / (float)charSet.Height ) );

        glVertex2f( (float)charSet.Chars[ch].XOffset,
          (float)(charSet.Chars[ch].Height + charSet.Chars[ch].YOffset) );


        glTexCoord2f( (float)(charSet.Chars[ch].x + charSet.Chars[ch].Width) / (float)charSet.Width,
          ((float)(charSet.Chars[ch].y + charSet.Chars[ch].Height) / (float)charSet.Width) );

        glVertex2f( (float)(charSet.Chars[ch].Width + charSet.Chars[ch].XOffset),
          (float)(charSet.Chars[ch].Height + charSet.Chars[ch].YOffset) );


        glTexCoord2f( (float)(charSet.Chars[ch].x+charSet.Chars[ch].Width) / (float)charSet.Width,
          ( (float)charSet.Chars[ch].y / (float) charSet.Height) );

        glVertex2f( (float)(charSet.Chars[ch].Width + charSet.Chars[ch].XOffset),
          (float)charSet.Chars[ch].YOffset);


        glTexCoord2f( (float)(charSet.Chars[ch].x+charSet.Chars[ch].Width) / (float)charSet.Width,
          ( (float)charSet.Chars[ch].y / (float) charSet.Height) );

        glVertex2f( (float)(charSet.Chars[ch].Width + charSet.Chars[ch].XOffset),
          (float)charSet.Chars[ch].YOffset);


        glTexCoord2f( (float)charSet.Chars[ch].x / (float)charSet.Width,
          ( (float)charSet.Chars[ch].y / (float)charSet.Height) );

        glVertex2f( (float)charSet.Chars[ch].XOffset,
          (float)charSet.Chars[ch].YOffset);


        glTexCoord2f(  (float)charSet.Chars[ch].x / (float)charSet.Width,
          ( (float)(charSet.Chars[ch].y + charSet.Chars[ch].Height) / (float)charSet.Height ) );

        glVertex2f( (float)charSet.Chars[ch].XOffset,
          (float)(charSet.Chars[ch].Height + charSet.Chars[ch].YOffset) );



      glEnd();

      glTranslatef((float)(charSet.Chars[ch].XAdvance - charSet.Chars[ch].XOffset), 0,0);              
    }
    else
    {
      // if char has no width, treat it like a space
      glTranslatef((float)charSet.Base, 0, 0);
    }

    glEndList();  
  }  

 glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL

}

// -----------------------------------------------------------------------------

//void Font::BuildText(HDC* hdc_)
//{
//  hDC = hdc_;
//  HFONT  font;                          // Windows Font ID
//  HFONT  oldfont;                       // Used For Good House Keeping
//
//  base = glGenLists(96);                // Storage For 96 Characters
//
//  font = CreateFont(  -24,              // Height Of Font
//            0,                          // Width Of Font
//            0,                          // Angle Of Escapement
//            0,                          // Orientation Angle
//            FW_BOLD,                    // Font Weight
//            FALSE,                      // Italic
//            FALSE,                      // Underline
//            FALSE,                      // Strikeout
//            ANSI_CHARSET,               // Character Set Identifier
//            OUT_TT_PRECIS,              // Output Precision
//            CLIP_DEFAULT_PRECIS,        // Clipping Precision
//            ANTIALIASED_QUALITY,        // Output Quality
//            FF_DONTCARE|DEFAULT_PITCH,  // Family And Pitch
//            "tahoma.ttf");                   // Font Name
//
//  oldfont = (HFONT)SelectObject(*hDC, font);      // Selects The Font We Want
//  wglUseFontBitmaps(*hDC, 32, 96, base);           // Builds 96 Characters Starting At Character 32
//  SelectObject(*hDC, oldfont);                     // Selects The Font We Want
//  DeleteObject(font);                             // Delete The Font
//
//
//
//}

// -----------------------------------------------------------------------------

//void Font::KillFont()
//{
//  glDeleteLists(base, 96);              // Delete All 96 Characters
//}

// -----------------------------------------------------------------------------

//void Font::print(const char* fmt)
//{
//  char    text[256];                    // Holds Our String
//  va_list    ap;                          // Pointer To List Of Arguments
//
//  if (fmt == NULL)                      // If There's No Text
//    return;                              // Do Nothing
//
//  va_start(ap, fmt);                    // Parses The String For Variables
//      vsprintf(text, fmt, ap);          // And Converts Symbols To Actual Numbers
//  va_end(ap);                            // Results Are Stored In Text
//
//  glPushAttrib(GL_LIST_BIT);            // Pushes The Display List Bits
//  glListBase(base - 32);                // Sets The Base Character to 32
//  glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);  // Draws The Display List Text
//  glPopAttrib();                        // Pops The Display List
//
//
//}

// 80 //////////////////////////////////////////////////////////////////////////