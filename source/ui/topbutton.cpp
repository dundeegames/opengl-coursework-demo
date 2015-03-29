#include <ui/topbutton.h>
#include <system/macros.h>


TopButton::TopButton()
{

}


TopButton::~TopButton()
{

}


// -----------------------------------------------------------------------------

void TopButton::init(Input* in, GLuint tex_, float x_, float y_,
                                             float uvx_, float uvy_)
{
  input = in;

  foreground.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       uvx_, uvy_, BTN_UV_SIZE, BTN_UV_SIZE);





}

// -----------------------------------------------------------------------------

void TopButton::update()
{
  handleInput();

  if(mouseHower)
  {
    foreground.setOpacity(TBTN_HIGHTLIGHT);
  }
  else
  {
    foreground.setOpacity(TBTN_FADE);
  }

}

// -----------------------------------------------------------------------------

void TopButton::draw()
{
  foreground.draw();
}

// -----------------------------------------------------------------------------







// 80 //////////////////////////////////////////////////////////////////////////