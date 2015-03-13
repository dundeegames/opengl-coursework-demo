// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*      Beginning DirectX 11 Game Programming                                  \n
*      By Allen Sherrod and Wendy Jones                                       \n
*                                                                             \n
*      TokenStream - Used to return blocks of text in a file.                 \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H


// INCLUDES ////////////////////////////////////////////////////////////////////




class TokenStream
{

public:
  TokenStream( );

  void ResetStream( );

  void SetTokenStream( char* data );
  bool GetNextToken( std::string* buffer, char* delimiters, int totalDelimiters );
  bool MoveToNextLine( std::string *buffer );


private:
  int startIndex_, endIndex_;
  std::string data_;

};


#endif // TOKEN_STREAM_H




// 80 //////////////////////////////////////////////////////////////////////////