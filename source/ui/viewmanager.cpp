////////////////////////////////////////////////////////////////////////////////
/**
* \file       viewmanager.cpp
* \brief      ViewManager class - AG0800A Graphics Programming
*
* \details    manages interaction, resizing and activation of all viewports
*             in the application
*
* \author     Jiri Klic
* \version    1.0
* \date       April 2015
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





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <ui/viewmanager.h>




// FUNCTIONS ///////////////////////////////////////////////////////////////////

ViewManager::ViewManager()
{

}


ViewManager::~ViewManager()
{

}


// -----------------------------------------------------------------------------

void ViewManager::init(ResourceManager* resMngr, Input* in)
{
  input = in;

  viewports[VIEWPORT_MAIN].init(VIEWPORT_MAIN, VIEW_MAIN, input, resMngr);
  viewports[VIEWPORT_SIDE].init(VIEWPORT_SIDE, VIEW_SIDE, input, resMngr);
  viewports[VIEWPORT_FRNT].init(VIEWPORT_FRNT, VIEW_FRONT, input, resMngr);
  viewports[VIEWPORT_TOP].init(VIEWPORT_TOP, VIEW_TOP, input, resMngr);
  viewports[VIEWPORT_PERS].init(VIEWPORT_PERS, VIEW_PERSP, input, resMngr);
  input->selectViewport(VIEWPORT_PERS);

}

// -----------------------------------------------------------------------------

void ViewManager::setWindowSize(float width, float height)
{
  GLsizei viewWidth = (GLsizei)((width - VIEW_XOFFSET) * 0.5f);
  GLsizei viewHeight =(GLsizei)((height - VIEW_YOFFSET) * 0.5f);

  viewports[VIEWPORT_MAIN].setSize(0, 0, (GLsizei)width, (GLsizei)height);
  setViewRects(VIEWPORT_MAIN, 0, (int)height, 0, (int)width);

  viewports[VIEWPORT_SIDE].setSize((int)VIEW_XPOS, 0, viewWidth, viewHeight);
  setViewRects(VIEWPORT_SIDE, (int)(height - viewHeight), (int)height,
                              (int)VIEW_XPOS, (int)(VIEW_XPOS + viewWidth));

  viewports[VIEWPORT_FRNT].setSize( (GLint)(viewWidth + VIEW_XOFFSET), 0, viewWidth, viewHeight);
  setViewRects(VIEWPORT_FRNT, (int)(height - viewHeight), (int)height,
                              (int)(viewWidth + VIEW_XOFFSET), (int)width);

  viewports[VIEWPORT_TOP].setSize((int)VIEW_XPOS, (viewHeight + 4), viewWidth, viewHeight);
  setViewRects(VIEWPORT_TOP, (int)VIEW_YPOS, (int)(VIEW_YPOS + viewHeight),
                             (int)VIEW_XPOS, (int)(VIEW_XPOS + viewWidth));

  viewports[VIEWPORT_PERS].setSize( (GLint)(viewWidth + VIEW_XOFFSET), (viewHeight + 4), viewWidth, viewHeight);
  setViewRects(VIEWPORT_PERS, (int)VIEW_YPOS, (int)(VIEW_YPOS + viewHeight),
                              (int)(viewWidth + VIEW_XOFFSET), (int)width);

}

// -----------------------------------------------------------------------------

void ViewManager::update(float dt)
{
  handleInput();

  for(int i=0; i<MAX_VIEWPORTS; i++)
  {
    viewports[i].update(dt);
  }

}

// -----------------------------------------------------------------------------

void ViewManager::beginView(int viewID, bool perspective, bool grad_bgr)
{
  viewports[viewID].begin(perspective, grad_bgr);
}

// -----------------------------------------------------------------------------

void ViewManager::endView(int viewID)
{
  viewports[viewID].end();
}

// -----------------------------------------------------------------------------

void ViewManager::setViewRects(int viewID, int top, int btm, int lft, int rgt)
{
  viewRects[viewID].top = top;
  viewRects[viewID].bottom = btm;
  viewRects[viewID].left = lft;
  viewRects[viewID].right = rgt;
}

// -----------------------------------------------------------------------------

void ViewManager::handleInput()
{
  if(input->leftMouseBtn())
  {
    for(int i = 1; i < MAX_VIEWPORTS; i++)
    {
      if((input->getMouseX() >= viewRects[i].left) && (input->getMouseX() <= viewRects[i].right) )
      {
        if((input->getMouseY() >= viewRects[i].top) && (input->getMouseY() <= viewRects[i].bottom) )
        {
          if(input->isViewportSelected(i) == false)
          {
            input->selectViewport(i);
          }
          break;
        }
      }

    }

  }

}

// -----------------------------------------------------------------------------



// 80 //////////////////////////////////////////////////////////////////////////