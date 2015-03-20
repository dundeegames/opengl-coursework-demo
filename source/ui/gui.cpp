#include <ui/gui.h>


Gui::Gui()
{

}


Gui::~Gui()
{

}


// -----------------------------------------------------------------------------

void Gui::init(Font* fnt)
{  
  font = fnt;
}

// -----------------------------------------------------------------------------

void Gui::drawGrid()
{
  
  glLineWidth(0.5f);
  glColor3f(1.0f, 1.0f, 1.0f);

  glBegin(GL_LINES);    
    for(int i = -11; i < 10; i++)
    {
      glVertex3f( (0.5*i + 0.5f), 0.0f, -5.0f);
      glVertex3f( (0.5*i + 0.5f), 0.0f, 5.0f);

      glVertex3f(-5.0f, 0.0f, (0.5*i + 0.5f));
      glVertex3f(5.0f, 0.0f, (0.5*i + 0.5f));

    }
  glEnd();


  glColor3f(0.0f, 0.0f, 0.0f);
  glLineWidth(1.0f);

  glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, -5.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);

    glVertex3f(-5.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);

  glEnd();

}

// -----------------------------------------------------------------------------

void Gui::renderText()
{
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  
  glEnable(GL_BLEND); // enable only when needed
  font->RenderText(Colour(COLOUR_WHITE, 1.0f),
                  150.0f, 35.0f, 0.5f, "Hello, World!");

  
  font->RenderText(Colour(COLOUR_BLACK, 0.5f),
                  150.0f, 55.0f, 1.0f, "Buddy");

  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}

// -----------------------------------------------------------------------------

void Gui::test1()
{
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  
  glEnable(GL_BLEND); // enable only when needed

  font->RenderText(Colour(COLOUR_GREEN, 1.0f),
                  10.0f, 10.0f, 0.5f, "Test1!");

  
  font->RenderText(Colour(COLOUR_BLACK, 0.5f),
                  10.0f, 30.0f, 1.0f, "Test1");

  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}




// 80 //////////////////////////////////////////////////////////////////////////