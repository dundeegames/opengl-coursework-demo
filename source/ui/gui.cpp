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
  setButtons();

}

// -----------------------------------------------------------------------------

void Gui::setWindowSize(float width, float height)
{
  windowWidth = width;
  windowHeight = height;


  resizeMenu();
  //setButtons();

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
                  105.0f, 105.0f, 0.5f, "Hello, World!");

  
  font->RenderText(Colour(COLOUR_BLACK, 0.5f),
                  105.0f, 125.0f, 1.0f, "Buddy");

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


  sidebarTop.setValues(menuTexture, SDB_ORIGIN_X, SDB_ORIGIN_Y, SDB_WIDTH, SDB_T_HEIGHT,
                                SDB_UV_X, SDB_T_UV_Y, SDB_UV_W, SDB_T_UV_H);

  sidebarMid.setValues(menuTexture, SDB_ORIGIN_X, SDB_M_Y, SDB_WIDTH, SDB_M_HEIGHT,
                                SDB_UV_X, SDB_M_UV_Y, SDB_UV_W, SDB_MB_UV_H);

  sidebarBtm.setValues(menuTexture, SDB_ORIGIN_X, SDB_B_Y, SDB_WIDTH, SDB_B_HEIGHT,
                                SDB_UV_X, SDB_B_UV_Y, SDB_UV_W, SDB_MB_UV_H);

  
  
  logoTri.setValues(menuTexture, TRI_ORIGIN_X, TRI_ORIGIN_Y, TRI_SIZE, TRI_SIZE,
                                TRI_UV_X, TRI_UV_Y, TRI_UV_SIZE, TRI_UV_SIZE);

  logo3D.setValues(menuTexture, L3D_ORIGIN_X, L3D_ORIGIN_Y, L3D_SIZE, L3D_SIZE,
                                L3D_UV_X, L3D_UV_Y, L3D_UV_SIZE, L3D_UV_SIZE);
}

// -----------------------------------------------------------------------------

void Gui::setButtons()
{
  topBtn1.setValues(menuTexture, TBTN1_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN1_UV_X, TBTN1_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn2.setValues(menuTexture, TBTN2_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN2_UV_X, TBTN2_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn3.setValues(menuTexture, TBTN3_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN3_UV_X, TBTN3_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn4.setValues(menuTexture, TBTN4_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN4_UV_X, TBTN4_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn5.setValues(menuTexture, TBTN5_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN5_UV_X, TBTN5_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn6.setValues(menuTexture, TBTN6_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN6_UV_X, TBTN6_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn7.setValues(menuTexture, TBTN7_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN7_UV_X, TBTN7_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn8.setValues(menuTexture, TBTN8_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN8_UV_X, TBTN8_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

  topBtn9.setValues(menuTexture, TBTN9_ORIGIN_X, TBTN_ORIGIN_Y, BTN_SIZE, BTN_SIZE,
                                TBTN9_UV_X, TBTN9_UV_Y, BTN_UV_SIZE, BTN_UV_SIZE);

 

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

    sidebarTop.draw();
    sidebarMid.draw();
    sidebarBtm.draw();

    logoTri.draw();
    logo3D.draw();

    topBtn1.draw();
    topBtn2.draw();
    topBtn3.draw();
    topBtn4.draw();
    topBtn5.draw();
    topBtn6.draw();
    topBtn7.draw();
    topBtn8.draw();
    topBtn9.draw();

  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////