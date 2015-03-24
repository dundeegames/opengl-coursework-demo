#include <ui/gui.h>
#include <system/macros.h>

Gui::Gui()
{

}


Gui::~Gui()
{

}


// -----------------------------------------------------------------------------

void Gui::init(ResourceManager* resMngr)
{  
  font = resMngr->getFont("tahoma");
  menuTexture = resMngr->getTexture("menuSheet.png");


  resizeMenu();

}

// -----------------------------------------------------------------------------

void Gui::setWindowSize(float width, float height)
{
  windowWidth = width;
  windowHeight = height;


  resizeMenu();

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
                  150.0f, 105.0f, 0.5f, "Hello, World!");

  
  font->RenderText(Colour(COLOUR_BLACK, 0.5f),
                  150.0f, 125.0f, 1.0f, "Buddy");

  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}

// -----------------------------------------------------------------------------

void Gui::resizeMenu()
{
  ribbonLeft.setValues(menuTexture, RIB_ORIGIN_X, RIB_ORIGIN_Y, RIB_LR_WIDTH, RIB_HEIGHT,
                                RIB_L_UV_X, RIB_UV_Y, RIB_LR_UV_W, RIB_UV_H);

  ribbonMiddle.setValues(menuTexture, RIB_M_X, RIB_ORIGIN_Y, RIB_M_WIDTH, RIB_HEIGHT,
                                RIB_M_UV_X, RIB_UV_Y, RIB_M_UV_W, RIB_UV_H);

  ribbonRight.setValues(menuTexture, RIB_R_X, RIB_ORIGIN_Y, RIB_LR_WIDTH, RIB_HEIGHT,
                                RIB_R_UV_X, RIB_UV_Y, RIB_LR_UV_W, RIB_UV_H);



}

// -----------------------------------------------------------------------------

void Gui::renderMenu()
{
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  
  glEnable(GL_BLEND); // enable only when needed

    ribbonLeft.draw();
    ribbonMiddle.draw();
    ribbonRight.draw();

  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////