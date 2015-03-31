#include <ui/bgrbutton.h>
#include <system/macros.h>

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