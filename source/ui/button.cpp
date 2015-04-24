////////////////////////////////////////////////////////////////////////////////
/**
* \file       button.cpp
* \brief      Button class - AG0800A Graphics Programming
*
* \details    Detailed description 
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





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/button.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


Button::Button()
{
  mouseHower = false;
  //selected = false;
  input = NULL;
  foreground.setValues();
}


Button::~Button()
{

}

// -----------------------------------------------------------------------------

void Button::handleInput()
{
  if( (input->getMouseX() >= BTN_LEFT) && (input->getMouseX() <= BTN_RIGHT) )
  {
    if( (input->getMouseY() >= BTN_TOP) && (input->getMouseY() <= BTN_BOTTOM) )
    {
      mouseHower = true;

      if(input->leftMouseBtn())
      {
        input->selectButton(buttonID);
        //selected = true;
      }

      if(input->rightMouseBtn())
      {
        input->unselectButton(buttonID);
        //selected = true;
      }

    }
    else
    {
      mouseHower = false;
    }

  }
  else
  {
    mouseHower = false;
  }

}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////