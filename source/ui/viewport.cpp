////////////////////////////////////////////////////////////////////////////////
/**
* \file       viewport.cpp
* \brief      Viewport class - AG0800A Graphics Programming
*
* \details    Handels the position, size, coordinate system and camera
*             of renderable area
*
* \author     Jiri Klic
* \version    1.0
* \date       March 2015
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
#include <ui/viewport.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


Viewport::Viewport()
{
  input = NULL;
  activated = false;
  wiremode = false;
}


Viewport::~Viewport()
{

}

// -----------------------------------------------------------------------------

void Viewport::init(int viewID, ViewportType view, Input* in, ResourceManager* resMngr)
{
  viewportID = viewID;
  type = view;
  input  = in;

  switch(type)
  {
  case VIEW_MAIN:
    camera.init(FXP_MAIN, NULL);
    break;

  case VIEW_PERSP:
    camera.init(FLT_PERSP, input);
    break;

  case VIEW_TOP:
    camera.init(MOV_TOP, input);
    break;

  case VIEW_SIDE:
    camera.init(MOV_SIDE, input);
    break;

  case VIEW_FRONT:
    camera.init(MOV_FRONT, input);
    break;

  case VIEW_GAME:
    camera.init(FST_PERSON, input);
    break;

  default:
    break;

  }
  
  font = resMngr->getFont("tahoma");
  activated = true;
}

// -----------------------------------------------------------------------------

void Viewport::setSize(GLint x_, GLint y_, GLsizei w_, GLsizei h_)
{
  x = x_;
  y = y_;
  width = w_;
  height = h_;


  // Up side down - window coords
  //left = (GLdouble)x;
  //right = (GLdouble)(x + width);
  //top = (GLdouble)(y + height);
  //bottom = (GLdouble)y;


  // window coords
  //left = (GLdouble)x;
  //right = (GLdouble)(x + width);
  //top = (GLdouble)y;
  //bottom = (GLdouble)(y + height);


  // viewport coords
  left = 0.0;
  right = (GLdouble)width;
  top = 0.0;
  bottom = (GLdouble)height;


  // Centered coordinates
  //left = -(GLdouble)width / 2.0;
  //right = (GLdouble)width / 2.0;
  //top = (GLdouble)height / 2.0;
  //bottom = -(GLdouble)height / 2.0;

}

// -----------------------------------------------------------------------------

void Viewport::update(float dt)
{
  if(input->isViewportSelected(viewportID))
  {
    handleInput();
    camera.handleInput(dt);
  }
  camera.update();

}

// -----------------------------------------------------------------------------

void Viewport::begin(bool perspective, bool grad_bgr)
{
  //set viewport
  if (height==0)  // Prevent A Divide By Zero error
  {
    height=1;     // Make the Height Equal One
  }

  glViewport(x, y, width, height);

  orthographicView();

  //turns on normal filled rendering
  glPolygonMode(GL_FRONT, GL_FILL);
  //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // debuging normals

  drawBackground(grad_bgr);


  if(perspective)
  {
    perspectiveView();
  }

  camera.view();

  if(wiremode)
  {
    // makes the front and back face wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }



}

// -----------------------------------------------------------------------------

void Viewport::end()
{
  //set viewport
  if (height==0)  // Prevent A Divide By Zero error
  {
    height=1;     // Make the Height Equal One
  }

  // COMMENT THIS LINE TO SHOW BUG!
  glViewport(x, y, width, height);
  
  
  orthographicView();

  //turns on normal filled rendering
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


  drawLabel();
  
}

// -----------------------------------------------------------------------------

void Viewport::drawBackground(bool gradient)
{
  if(gradient)
  {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glBegin(GL_TRIANGLES);

      glColor3f(GRADIENT_TOP);        // Top colour of gradient
        glVertex3f( (GLfloat)right, (GLfloat)top, Z_POSITION);
        glVertex3f( (GLfloat)left, (GLfloat)top, Z_POSITION);

      glColor3f(GRADIENT_BOTTOM);     // Bottom colour of gradient
        glVertex3f( (GLfloat)left, (GLfloat)bottom, Z_POSITION);
        glVertex3f( (GLfloat)left, (GLfloat)bottom, Z_POSITION);
        glVertex3f( (GLfloat)right, (GLfloat)bottom, Z_POSITION);

      glColor3f(GRADIENT_TOP);        // Top colour of gradient
        glVertex3f( (GLfloat)right, (GLfloat)top, Z_POSITION);

      glColor3f(COLOUR_WHITE);        // reset colour

    glEnd();

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

  }
  else
  {
    glClearColor(COLOUR_BROWN, 1.0f);   // Gray Background
  }

}

// -----------------------------------------------------------------------------

void Viewport::orthographicView()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  glOrtho(left, right, bottom, top, 1.0 ,150.0);

  glMatrixMode(GL_MODELVIEW);   // Select The Modelview Matrix
  glLoadIdentity();             // Reset The Modelview Matrix  

  //set camera looking down the -z axis,  6 units away from the center
  gluLookAt(0.0, 0.0, 10.0,     0.0, 0.0, 0.0,     0.0, 1.0, 0.0); //Where we are, What we look at, and which way is up
  
}

// -----------------------------------------------------------------------------

void Viewport::perspectiveView()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //calculate aspect ratio
  gluPerspective(45.0, (GLdouble)width/(GLdouble)height, 1.0 ,150.0);

  glMatrixMode(GL_MODELVIEW);       // Select The Modelview Matrix
  glLoadIdentity();                 // Reset The Modelview Matrix

}

// -----------------------------------------------------------------------------

void Viewport::drawLabel()
{
  //float center = ((float)(width) * 0.5f);


  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  
  glEnable(GL_BLEND); // enable only when needed

  if( (type != VIEW_MAIN) && (type != VIEW_GAME) )
  {
    drawSelectionRect();
  }


  switch(type)
  {
  case VIEW_MAIN:
    break;

  case VIEW_PERSP:
    font->RenderText(Colour(COLOUR_GREEN, 1.0f),
                      PERSP_OFFSET, 10.0f, 0.25f, "Persp");
    break;

  case VIEW_TOP:
    font->RenderText(Colour(COLOUR_GREEN, 1.0f),
                      TOP_OFFSET, 10.0f, 0.25f, "Top");
    break;

  case VIEW_SIDE:
    font->RenderText(Colour(COLOUR_GREEN, 1.0f),
                      SIDE_OFFSET, 10.0f, 0.25f, "Side");
    break;

  case VIEW_FRONT:
    font->RenderText(Colour(COLOUR_GREEN, 1.0f),
                      FRONT_OFFSET, 10.0f, 0.25f, "Front");
    break;

  case VIEW_GAME:
    break;

  default:
    break;

  }




  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

}

// -----------------------------------------------------------------------------

void Viewport::drawSelectionRect()
{
  if(input->isViewportSelected(viewportID))
  {
    glColor3f(COLOUR_DRKYELLOW);
  }
  else
  {
    glColor3f(COLOUR_DRKGRAY);
  }

  glLineWidth(8.0f);

  glBegin(GL_LINES);
    
    glVertex3f( (GLfloat)right, (GLfloat)top, Z_POSITION);
    glVertex3f( (GLfloat)left, (GLfloat)top, Z_POSITION);

    glVertex3f( (GLfloat)left, (GLfloat)top, Z_POSITION);
    glVertex3f( (GLfloat)left, (GLfloat)bottom, Z_POSITION);

    glVertex3f( (GLfloat)left, (GLfloat)bottom, Z_POSITION);
    glVertex3f( (GLfloat)right, (GLfloat)bottom, Z_POSITION);

    glVertex3f( (GLfloat)right, (GLfloat)bottom, Z_POSITION);
    glVertex3f( (GLfloat)right, (GLfloat)top, Z_POSITION);
  glEnd();


  glColor3f(COLOUR_WHITE);      // reset colour
  glLineWidth(1.0f);            // reset line with
}

// -----------------------------------------------------------------------------

void Viewport::handleInput()
{
  if(input->isKeyDown('4'))                 // if 4 is pressed
  {
    // makes the front face wireframe, not the back face
    wiremode = true;
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    
    input->SetKeyUp('4');                   //force un-pressing of 4
  }

  if(input->isKeyDown('5'))                 // if 5 is pressed
  {
    //turns on normal filled rendering
    wiremode = false;
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    input->SetKeyUp('5');                   //force un-pressing of 5
  }


}







// 80 //////////////////////////////////////////////////////////////////////////