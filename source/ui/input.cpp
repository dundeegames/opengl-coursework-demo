////////////////////////////////////////////////////////////////////////////////
/**
* \file       input.cpp
* \brief      Input class - AG0800A Graphics Programming
*
* \details    Detailed description 
*
* \author     Jiri Klic
* \author     Paul Robertson
* \version    2.0
* \date       January 2015    [2.0]
* \date       September 2014  [1.0]
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo
*
* \copyright  Based on:  Input class.[2014].Paul Robertson
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/input.h>




// FUNCTIONS ///////////////////////////////////////////////////////////////////


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

  case 4:
    if((btnID % LIGHT_BUTTONS) < MAX_LIGHT_BUTTONS)
    {
      return lightButtons[(btnID % LIGHT_BUTTONS)];
    }
    else
    {
      MessageBox(NULL, "btnID > MAX_LIGHT_BUTTONS", "Button ID Error", MB_OK);
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

  case 4:

    if((btnID % LIGHT_BUTTONS) < MAX_LIGHT_BUTTONS)
    {
      lightButtons[(btnID % LIGHT_BUTTONS)] = true;
    }
    else
    {
      MessageBox(NULL, "btnID > MAX_LIGHT_BUTTONS", "Button ID Error", MB_OK);
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

  case 4:
    if((btnID % LIGHT_BUTTONS) < MAX_LIGHT_BUTTONS)
    {
      lightButtons[(btnID % LIGHT_BUTTONS)] = false;
    }
    else
    {
      MessageBox(NULL, "btnID > MAX_LIGHT_BUTTONS", "Button ID Error", MB_OK);
    }    
    break;






  default:
    break;

  }

}

// -----------------------------------------------------------------------------

bool Input::isViewportSelected(int viewID)
{
  return   viewports[viewID].selected;
}

// -----------------------------------------------------------------------------

void Input::selectViewport(int viewID)
{
  for(int i = 0; i < MAX_VIEWPORTS; i++) // only one selected at the time
  {
    if(i == viewID)
    {
      viewports[i].selected = true;
    }
    else
    {
      viewports[i].selected = false;
    }
  }

}

// -----------------------------------------------------------------------------

bool Input::isViewportActive(int viewID)
{
  return viewports[viewID].active;
}

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