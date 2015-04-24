////////////////////////////////////////////////////////////////////////////////
/**
* \file       bgrbutton.cpp
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





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/bgrbutton.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


BgrButton::BgrButton()
{
  background.setValues();
}


BgrButton::~BgrButton()
{

}

// -----------------------------------------------------------------------------

void BgrButton::init(int btnID, Input* in, GLuint tex_, float x_, float y_,
                                             float uvx_, float uvy_)
{
  buttonID = btnID;
  input = in;


  foreground.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       uvx_, uvy_, BTN_UV_SIZE, BTN_UV_SIZE);


  background.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       BGR_UNSEL_UV_X, BGR_UNSEL_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);





}

// -----------------------------------------------------------------------------

void BgrButton::update()
{
  handleInput();

  //if(selected)
  if(input->isBottonSelected(buttonID))
  {
    background.set_uv_position(BGR_SEL_UV_X, BGR_SEL_UV_Y);
  }
  else
  {
    background.set_uv_position(BGR_UNSEL_UV_X, BGR_UNSEL_UV_Y);
  }

}

// -----------------------------------------------------------------------------

void BgrButton::draw()
{
  background.draw();
  foreground.draw();
}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////