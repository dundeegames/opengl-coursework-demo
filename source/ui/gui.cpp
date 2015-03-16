#include <ui/gui.h>


Gui::Gui()
{

}


Gui::~Gui()
{

}


// -----------------------------------------------------------------------------

void Gui::init()
{  
  font.Load("../../media/fonts/tahoma");
}

// -----------------------------------------------------------------------------

void Gui::drawGrid()
{

  glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(0.5f);

    for(int i = -11; i < 10; i++)
    {
      glVertex3f( (0.5*i + 0.5f), 0.0f, -5.0f);
      glVertex3f( (0.5*i + 0.5f), 0.0f, 5.0f);

      glVertex3f(-5.0f, 0.0f, (0.5*i + 0.5f));
      glVertex3f(5.0f, 0.0f, (0.5*i + 0.5f));

    }

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(10.0f);
      glVertex3f(0.0f, 0.0f, -5.0f);
      glVertex3f(0.0f, 0.0f, 5.0f);

      glVertex3f(-5.0f, 0.0f, 0.0f);
      glVertex3f(5.0f, 0.0f, 0.0f);

  glEnd();

}

// -----------------------------------------------------------------------------

void Gui::renderText()
{
  glEnable(GL_BLEND); // enable only when needed
  font.RenderText(Colour(1.0f, 1.0f, 1.0f, 1.0f),
                  150.0f, 80.0f, 0.5f, "Hello, World!");

  
  font.RenderText(Colour(0.0f, 0.0f, 0.0f, 0.5f),
                  150.0f, 100.0f, 1.0f, "Buddy");

  glDisable(GL_BLEND);

}

// -----------------------------------------------------------------------------

void Gui::test1()
{
  glEnable(GL_BLEND); // enable only when needed
  font.RenderText(Colour(1.0f, 1.0f, 1.0f, 1.0f),
                  50.0f, 80.0f, 0.5f, "Test1!");

  
  font.RenderText(Colour(0.0f, 0.0f, 0.0f, 0.5f),
                  50.0f, 100.0f, 1.0f, "Test1");

  glDisable(GL_BLEND);

}


void Gui::test2()
{
  glEnable(GL_BLEND); // enable only when needed
  font.RenderText(Colour(1.0f, 1.0f, 1.0f, 1.0f),
                  575.0f, 80.0f, 0.5f, "Test2!");

  
  font.RenderText(Colour(0.0f, 0.0f, 0.0f, 0.5f),
                  575.0f, 100.0f, 1.0f, "Test2");

  glDisable(GL_BLEND);

}


void Gui::test3()
{
  glEnable(GL_BLEND); // enable only when needed
  font.RenderText(Colour(1.0f, 1.0f, 1.0f, 1.0f),
                  100.0f, 80.0f, 0.5f, "Test3!");

  
  font.RenderText(Colour(0.0f, 0.0f, 0.0f, 0.5f),
                  100.0f, 100.0f, 1.0f, "Test3");

  glDisable(GL_BLEND);

}


void Gui::test4()
{
  glEnable(GL_BLEND); // enable only when needed
  font.RenderText(Colour(1.0f, 1.0f, 1.0f, 1.0f),
                  150.0f, 80.0f, 0.5f, "Test4!");

  
  font.RenderText(Colour(0.0f, 0.0f, 0.0f, 0.5f),
                  150.0f, 100.0f, 1.0f, "Test4");

  glDisable(GL_BLEND);

}



// 80 //////////////////////////////////////////////////////////////////////////