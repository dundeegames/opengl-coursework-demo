#include <ui/transpbutton.h>
#include <system/macros.h>


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