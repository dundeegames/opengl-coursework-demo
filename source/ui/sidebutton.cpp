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

void SideButton::init(int btnID, Input* in, GLuint tex_, float x_, float y_,
                                             float uvx_, float uvy_)
{
  buttonID = btnID;
  input = in;


  foreground.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       uvx_, uvy_, BTN_UV_SIZE, BTN_UV_SIZE);


  background.setValues(tex_, x_, y_, BTN_SIZE, BTN_SIZE,
                       SBGR_UNSEL_UV_X, SBGR_UNSEL_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);





}

// -----------------------------------------------------------------------------

void SideButton::update()
{
  handleInput();

  if(selected)
  {
    background.set_uv_position(SBGR_SEL_UV_X, SBGR_SEL_UV_Y);
  }
  else
  {
    background.set_uv_position(SBGR_UNSEL_UV_X, SBGR_UNSEL_UV_Y);
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