////////////////////////////////////////////////////////////////////////////////
/**
* \file       bgrbutton.h
* \brief      BgrButton class - AG0800A Graphics Programming
*
* \details    Button made from two sprites, making background effect
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


#ifndef BGRBUTTON_H
#define BGRBUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class BgrButton : public Button
{

public:
  BgrButton();
  ~BgrButton();

  void init(int btnID, Input* in, GLuint tex_, float x_, float y_, float uvx_, float uvy_);
  void update();
  void draw();

private:
  Sprite background;


};


#endif // BGRBUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////