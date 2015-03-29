#include <ui/sidebutton.h>
#include <system/macros.h>

SideButton::SideButton()
{
  background.setValues();
}


SideButton::~SideButton()
{

}

// -----------------------------------------------------------------------------

void SideButton::init(Input* in, GLuint tex_, float x_, float y_,
                                             float uvx_, float uvy_)
{
  input = in;


  foreground.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       uvx_, uvy_, BTN_UV_SIZE, BTN_UV_SIZE);


  background.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       uvx_, uvy_, BTN_UV_SIZE, BTN_UV_SIZE);





}

// -----------------------------------------------------------------------------

void SideButton::update()
{
  handleInput();

  if(selected)
  {

  }
  else
  {

  }

}

// -----------------------------------------------------------------------------

void SideButton::draw()
{
  background.draw();
  foreground.draw();
}

// -----------------------------------------------------------------------------







// 80 //////////////////////////////////////////////////////////////////////////