#include <ui/button.h>
#include <system/macros.h>

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