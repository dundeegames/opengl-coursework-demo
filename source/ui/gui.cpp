#include <ui/gui.h>


// DEFINES /////////////////////////////////////////////////////////////////////
#define RIB_ORIGIN_X        0.0f
#define RIB_ORIGIN_Y        32.0f
#define RIB_HEIGHT          46.0f
#define RIB_LR_WIDTH        8.0f
#define RIB_M_WIDTH         (windowWidth - (2*RIB_LR_WIDTH))
#define RIB_M_X             (RIB_ORIGIN_X + RIB_LR_WIDTH)
#define RIB_R_X             (windowWidth - RIB_LR_WIDTH)

#define TEXTURE_WIDTH       256.0f
#define RIB_L_UV_X          (0.0f / TEXTURE_WIDTH)
#define RIB_L_UV_Y          (0.0f / TEXTURE_WIDTH)
#define RIB_L_UV_W          (0.0f / TEXTURE_WIDTH)
#define RIB_L_UV_W          (0.0f / TEXTURE_WIDTH)

#define RIB_M_UV_X          (0.0f / TEXTURE_WIDTH)
#define RIB_M_UV_Y          (0.0f / TEXTURE_WIDTH)
#define RIB_M_UV_W          (0.0f / TEXTURE_WIDTH)
#define RIB_M_UV_W          (0.0f / TEXTURE_WIDTH)

#define RIB_UV_X            (0.0f / TEXTURE_WIDTH)
#define RIB_UV_Y            (0.0f / TEXTURE_WIDTH)
#define RIB_UV_W            (0.0f / TEXTURE_WIDTH)
#define RIB_UV_W            (0.0f / TEXTURE_WIDTH)
//#define RIB_HEIGHT





// FUNCTIONS ///////////////////////////////////////////////////////////////////

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


  initMenu();

}

// -----------------------------------------------------------------------------

void Gui::setWindowSize(float width, float height)
{
  windowWidth = width;
  windowHeight = height;

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

void Gui::initMenu()
{
  ribbonLeft.init(menuTexture, RIB_ORIGIN_X, RIB_ORIGIN_Y, RIB_LR_WIDTH, RIB_HEIGHT,
          (0.0f / 256.0f), 0.0f, (8.0f / 256.0f), (46.0f / 256.0f));

  ribbonMiddle.init(menuTexture, RIB_M_X, RIB_ORIGIN_Y, RIB_M_WIDTH, RIB_HEIGHT,
          (8.0f / 256.0f), 0.0f, (30.0f / 256.0f), (46.0f / 256.0f));

  ribbonRight.init(menuTexture, RIB_R_X, RIB_ORIGIN_Y, RIB_LR_WIDTH, RIB_HEIGHT,
          (38.0f / 256.0f), 0.0f, (8.0f / 256.0f), (46.0f / 256.0f));



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