#include <ui/font.h>


Font::Font()
{
  myTexture = NULL;
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

void Font::RenderText(Colour colour, float x_, float y_,
                      float scale, const char * text, ...)
{
  assert(text != NULL);
  if(!text)
  {
    return;
  }
  int count = strlen(text); 

  glListBase(base_list);

  glBindTexture(GL_TEXTURE_2D, myTexture);  // tells opengl which texture to use
  glColor4f(colour.R, colour.G, colour.B, colour.A);
  
  glPushMatrix();                           // Remember where we are.

    //glScalef(scale, scale, 1.f);
    //  glTranslatef(x_,y_,0);

    glTranslatef(x_,y_,0);  
      glScalef(scale, scale, 1.f);    
    glCallLists(count, GL_UNSIGNED_BYTE, text);  

  glPopMatrix();                            // go back to origin

  glBindTexture(GL_TEXTURE_2D, NULL);       // tells opengl which texture to use

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
  base_list = glGenLists(FONT_MAX_ASCII);   // create display lists
  glBindTexture(GL_TEXTURE_2D, myTexture);  // tells opengl which texture to use


  for (int ch = 0; ch < FONT_MAX_ASCII; ch++)
  {
    glNewList( (base_list + ch), GL_COMPILE);

    if (charSet.Chars[ch].Width) {

      

      glBegin(GL_TRIANGLES);

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



// 80 //////////////////////////////////////////////////////////////////////////