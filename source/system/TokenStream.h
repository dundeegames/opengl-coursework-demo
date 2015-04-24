////////////////////////////////////////////////////////////////////////////////
/**
* \file       tokenstream.h
* \brief      TokenStream class - AG0800A Graphics Programming
*
* \details    Used to return blocks of text in a file 
*
* \author     
* \version    1.0
* \date       [2015] Provided during laboratory exercise
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  A.Sherrod and W. Jones.2011.Beginning DirectX 11 Game Programming.
*             Delmar Cengage Learning.
*
*///////////////////////////////////////////////////////////////////////////////



#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H


// INCLUDES ////////////////////////////////////////////////////////////////////






// CLASS ///////////////////////////////////////////////////////////////////////

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