////////////////////////////////////////////////////////////////////////////////
/**
* \file       transpbutton.cpp
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





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/transpbutton.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


TranspButton::TranspButton()
{

}


TranspButton::~TranspButton()
{

}


// -----------------------------------------------------------------------------

void TranspButton::init(int btnID, Input* in, GLuint tex_, float x_, float y_,
                                             float uvx_, float uvy_)
{
  buttonID = btnID;
  input = in;

  foreground.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       uvx_, uvy_, BTN_UV_SIZE, BTN_UV_SIZE);





}

// -----------------------------------------------------------------------------

void TranspButton::update()
{
  handleInput();

  if(mouseHower || (input->isBottonSelected(buttonID)) )
  {
    foreground.setOpacity(TBTN_HIGHTLIGHT);
  }
  else
  {
    foreground.setOpacity(TBTN_FADE);
  }

}

// -----------------------------------------------------------------------------

void TranspButton::draw()
{
  foreground.draw();
}

// -----------------------------------------------------------------------------







// 80 //////////////////////////////////////////////////////////////////////////