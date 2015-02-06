#include "font.h"


Font::Font()
{
  myTexture = NULL;
}


Font::~Font()
{

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
    bool success = ParseFont(font_stream, character_set);
 
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

	return true;

}

// -----------------------------------------------------------------------------

bool Font::ParseFont( std::istream& Stream, Charset& CharsetDesc )
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

//void Font::RenderText(float x_, float y_, float scale, const TextJustification justification, const char * text, ...)
//{
	//if(!text)
	//	return;

	//va_list args;
	//char text_buffer[256];

	//va_start(args, text);
	//std::vsprintf(text_buffer, text, args);

	//int character_count = strlen(text_buffer);
	//float string_length = GetStringLength(text_buffer);

	////Vector2 cursor = Vector2(pos.x, pos.y);

	//switch(justification)
	//{
	//case TJ_CENTRE:
	//	cursor.x -= string_length*0.5f*scale;
	//	break;
	//case TJ_RIGHT:
	//	cursor.x -= string_length*scale;
	//	break;
	//default:
	//	break;
	//}

	//Sprite sprite;
	//sprite.set_texture(font_texture_);
	//for( UInt32 character_index = 0; character_index < character_count; ++character_index )
	//{
	//	int CharX = character_set.Chars[static_cast<int>(text_buffer[character_index])].x;
	//	int CharY = character_set.Chars[static_cast<int>(text_buffer[character_index])].y;
	//	int Width = character_set.Chars[static_cast<int>(text_buffer[character_index])].Width;
	//	int Height = character_set.Chars[static_cast<int>(text_buffer[character_index])].Height;
	//	int OffsetX = character_set.Chars[static_cast<int>(text_buffer[character_index])].XOffset;
	//	int OffsetY = character_set.Chars[static_cast<int>(text_buffer[character_index])].YOffset;

	//	Vector2 uv_pos((float) CharX / (float) character_set.Width,  ((float) (CharY) / (float) character_set.Height));
	//	Vector2 uv_size((float) (Width) / (float) character_set.Width, (float)(Height) / (float) character_set.Height);
	//	Vector2 size(((float)Width)*scale, ((float)Height)*scale);
	//	Vector3 sprite_position = Vector3(cursor.x+((float)OffsetX*scale)+size.x*0.5f, cursor.y + scale*((float)Height*0.5f +  (float)OffsetY), pos.z);

	//	sprite.set_position(sprite_position);
	//	sprite.set_width(size.x);
	//	sprite.set_height(size.y);
	//	sprite.set_uv_position(uv_pos);
	//	sprite.set_uv_width(uv_size.x);
	//	sprite.set_uv_height(uv_size.y);
	//	sprite.set_colour(colour);
	//	renderer->DrawSprite(sprite);
	//	cursor.x += ((float)character_set.Chars[static_cast<UInt32>(text_buffer[character_index])].XAdvance)*scale;
	//}
//}






// 80 //////////////////////////////////////////////////////////////////////////