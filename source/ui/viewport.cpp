#include <ui/viewport.h>


Viewport::Viewport()
{

}


Viewport::~Viewport()
{

}

// -----------------------------------------------------------------------------

void Viewport::init(ViewportType view, CameraType cmr, Input* in, ResourceManager* resMngr)
{
  type = view;
  camera.init(cmr, in);
  font = resMngr->getFont("tahoma");
  selected = false;
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
  if(selected)
  {
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
  drawBackground(grad_bgr);


  if(perspective)
  {
    perspectiveView();
  }

  camera.view();

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
  if(selected)
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









// 80 //////////////////////////////////////////////////////////////////////////