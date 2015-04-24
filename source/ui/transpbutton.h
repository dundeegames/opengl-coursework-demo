////////////////////////////////////////////////////////////////////////////////
/**
* \file       transpbutton.h
* \brief      TranspButton class - AG0800A Graphics Programming
*
* \details    Button with semitrasparent effect
*
* \author     Jiri Klic
* \version    1.0
* \date       January 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////



#ifndef TRANSPBUTTON_H
#define TRANSPBUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class TranspButton : public Button
{

public:
  TranspButton();
  ~TranspButton();

  void init(int btnID, Input* in, GLuint tex_, float x_, float y_, float uvx_, float uvy_);
  void update();
  void draw();

private:

};


#endif // TRANSPBUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////