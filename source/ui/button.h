// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                Button class - - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



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

  virtual void init(Input* in, GLuint tex_, float x_, float y_,
                                            float uvx_, float uvy_) = 0;

  virtual void update() = 0;
  virtual void draw() = 0;

  bool isSelected() {return selected;}
  void select() {selected = true;}
  void unselect() {selected = false;}

private:


protected:
  bool mouseHower;
  bool selected;
  Input* input;
  Sprite foreground;
  
  void handleInput();


  

};


#endif // BUTTON_H




// 80 //////////////////////////////////////////////////////////////////////////