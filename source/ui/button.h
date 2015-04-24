////////////////////////////////////////////////////////////////////////////////
/**
* \file       button.h
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


#ifndef BUTTON_H
#define BUTTON_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <assets/sprite.h>
#include <ui/input.h>




// CLASS ///////////////////////////////////////////////////////////////////////

class Button
{

public:
  Button();
  ~Button();

  virtual void init(int btnID, Input* in, GLuint tex_, float x_, float y_,
                                            float uvx_, float uvy_) = 0;

  virtual void update() = 0;
  virtual void draw() = 0;

  //bool isSelected() {return selected;}
  //void select() {selected = true;}
  //void unselect() {selected = false;}

private:


protected:
  int buttonID;
  bool mouseHower;
  //bool selected;
  Input* input;
  Sprite foreground;
  
  void handleInput();


  

};


#endif // BUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////