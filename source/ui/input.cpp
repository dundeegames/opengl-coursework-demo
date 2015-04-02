#include <ui/input.h>



Input::Input()
{
  sensitivity = 2.5f;

  // set all keys to UP
  for(int i = 0; i < 256; i++)
  {
    keys[i] = false;
  }

  wheelDelta = 0;


  for(int i = 0; i < 256; i++)
  {
    keys[i] = false;
  }






}

Input::~Input()
{

}

// -----------------------------------------------------------------------------

void Input::SetKeyDown(WPARAM key)
{
  keys[key] = true;
}

// -----------------------------------------------------------------------------

void Input::SetKeyUp(WPARAM key)
{
  keys[key] = false;
}

// -----------------------------------------------------------------------------

bool Input::isKeyDown(int key)
{
  return keys[key];
}

// -----------------------------------------------------------------------------

void Input::setMouseX(int pos)
{
  mouse.x = pos;
}

// -----------------------------------------------------------------------------

void Input::setMouseY(int pos)
{
  mouse.y = pos;
}

// -----------------------------------------------------------------------------

int Input::getMouseX()
{
  return mouse.x;
}

// -----------------------------------------------------------------------------

int Input::getMouseY()
{
  return mouse.y;
}

// -----------------------------------------------------------------------------

void Input::setLeftMouseBtn(bool l)
{
  mouse.left = l;
}

// -----------------------------------------------------------------------------

void Input::setMiddleMouseBtn(bool m)
{
  mouse.middle = m;
}

// -----------------------------------------------------------------------------

void Input::setRightMouseBtn(bool r)
{
  mouse.right = r;
}

// -----------------------------------------------------------------------------

void Input::setLeftMouseDClick(bool d)
{
  mouse.leftDClick = d;
}

// -----------------------------------------------------------------------------

bool Input::leftMouseBtn()
{
  return mouse.left;
}

// -----------------------------------------------------------------------------

bool Input::middleMouseBtn()
{
  return mouse.middle;
}

// -----------------------------------------------------------------------------

bool Input::rightMouseBtn()
{
  return mouse.right;
}

// -----------------------------------------------------------------------------

bool Input::leftMouseDClick()
{
  return mouse.leftDClick;
}

// -----------------------------------------------------------------------------

float Input::getSensitivity()
{
  return sensitivity;
}

// -----------------------------------------------------------------------------

bool Input::isBottonSelected(int btnID)
{
  switch(btnID / 100)   // result 1-3 thakns to concatenating decimals
  {
  case 1:
    if((btnID % TOP_BUTTONS) < MAX_TOP_BUTTONS)
    {
      return topButtons[(btnID % TOP_BUTTONS)];
    }
    else
    {
      MessageBox(NULL, "btnID > MAX_TOP_BUTTONS", "Button ID Error", MB_OK);
      return false;
    }
    break;

  case 2:
    if((btnID % SIDE_BUTTONS) < MAX_SIDE_BUTTONS)
    {
      return sideButtons[(btnID % SIDE_BUTTONS)];
    }
    else
    {
      MessageBox(NULL, "btnID > MAX_SIDE_BUTTONS", "Button ID Error", MB_OK);
      return false;
    }
    break;

  case 3:
    if((btnID % VIEW_BUTTONS) < MAX_VIEW_BUTTONS)
    {
      return viewButtons[(btnID % VIEW_BUTTONS)];
    }
    else
    {
      MessageBox(NULL, "btnID > MAX_VIEW_BUTTONS", "Button ID Error", MB_OK);
      return false;
    }    
    break;

  default:
    MessageBox(NULL, "wrong btnID", "Button ID Error", MB_OK);
    return false;
    break;

  }

}

// -----------------------------------------------------------------------------

void Input::selectButton(int btnID)
{
  switch(btnID / 100)   // result 1-3 thakns to concatenating decimals
  {
  case 1:
    if((btnID % TOP_BUTTONS) < MAX_TOP_BUTTONS)
    {
      topButtons[(btnID % TOP_BUTTONS)] = true;
    }
    break;

  case 2:
    if((btnID % SIDE_BUTTONS) < MAX_SIDE_BUTTONS)
    {
      for(int i = 0; i < MAX_SIDE_BUTTONS; i++) // only one selected at the time
      {
        if(i == (btnID % SIDE_BUTTONS))
        {
          sideButtons[i] = true;
        }
        else
        {
          sideButtons[i] = false;
        }
      }
    }
    break;

  case 3:
    if((btnID % VIEW_BUTTONS) < MAX_VIEW_BUTTONS)
    {
      for(int i = 0; i < MAX_VIEW_BUTTONS; i++) // only one selected at the time
      {
        if(i == (btnID % VIEW_BUTTONS))
        {
          viewButtons[i] = true;
        }
        else
        {
          viewButtons[i] = false;
        }
      }
    }
    break;

  default:
    break;

  }

}

// -----------------------------------------------------------------------------

void Input::unselectButton(int btnID)
{
  switch(btnID / 100)   // result 1-3 thakns to concatenating decimals
  {
  case 1:
    if((btnID % TOP_BUTTONS) < MAX_TOP_BUTTONS)
    {
      topButtons[(btnID % TOP_BUTTONS)] = false;
    }
    break;

  case 2:
    if((btnID % SIDE_BUTTONS) < MAX_SIDE_BUTTONS)
    {
      sideButtons[(btnID % SIDE_BUTTONS)] = false;
    }
    break;

  case 3:
    if((btnID % VIEW_BUTTONS) < MAX_VIEW_BUTTONS)
    {
      viewButtons[(btnID % VIEW_BUTTONS)] = false;
    }
    break;

  default:
    break;

  }

}

// -----------------------------------------------------------------------------

bool Input::isViewportSelected(int viewID)
{
  return   viewports[viewID];
}

// -----------------------------------------------------------------------------

void Input::selectViewport(int viewID)
{
  for(int i = 0; i < MAX_VIEWPORTS; i++) // only one selected at the time
  {
    if(i == viewID)
    {
      viewports[i] = true;
    }
    else
    {
      viewports[i] = false;
    }
  }

}

// -----------------------------------------------------------------------------

//void Input::unselectViewport(int viewID)
//{
//  viewports[viewID] = false;
//}

// -----------------------------------------------------------------------------

void Input::resetLDragCoords()
{
  mouse.leftDragX = mouse.x;
  mouse.leftDragY = mouse.y;
}

// -----------------------------------------------------------------------------

int Input::getLDragXdt()
{
  return (mouse.x - mouse.leftDragX);
}

// -----------------------------------------------------------------------------

int Input::getLDragYdt()
{
  return (mouse.leftDragY - mouse.y);

}

// -----------------------------------------------------------------------------

void Input::resetRDragCoords()
{
  mouse.rightDragX = mouse.x;
  mouse.rightDragY = mouse.y;
}

// -----------------------------------------------------------------------------

int Input::getRDragXdt()
{
  return (mouse.x - mouse.rightDragX);
}

// -----------------------------------------------------------------------------

int Input::getRDragYdt()
{
  return (mouse.rightDragY - mouse.y);

}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////