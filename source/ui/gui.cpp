#include <ui/gui.h>
#include <system/macros.h>

Gui::Gui()
{
  // set default values
  input = NULL;

  windowWidth = 0.0f;
  windowHeight = 0.0f;

  ribbonLeft.setValues();
  ribbonMiddle.setValues();
  ribbonRight.setValues();

  sidebarTop.setValues();
  sidebarMid.setValues();
  sidebarBtm.setValues();

  logo3D.setValues();
  logoTri.setValues();

  font = NULL;
  menuTexture = NULL;

}


Gui::~Gui()
{

}


// -----------------------------------------------------------------------------

void Gui::init(ResourceManager* resMngr, Input* in)
{
  input = in;
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

void Gui::update()
{
  for(std::vector<TopButton>::iterator it = topButtons.begin(); it != topButtons.end(); it++)
  {
    it->update();
  }

  for(std::vector<SideButton>::iterator it = sideButtons.begin(); it != sideButtons.end(); it++)
  {
    it->update();
  }


}

// -----------------------------------------------------------------------------

void Gui::drawGrid()
{
  
  glLineWidth(0.5f);
  glColor3f(1.0f, 1.0f, 1.0f);

  glBegin(GL_LINES);    
    for(int i = -11; i < 10; i++)
    {
      glVertex3f( (0.5f*(float)i + 0.5f), 0.0f, -5.0f);
      glVertex3f( (0.5f*(float)i + 0.5f), 0.0f, 5.0f);

      glVertex3f(-5.0f, 0.0f, (0.5f*(float)i + 0.5f));
      glVertex3f(5.0f, 0.0f, (0.5f*(float)i + 0.5f));

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
  initTopButton(TBTN1_SPHERE, TBTN1_ORIGIN_X, TBTN_ORIGIN_Y, TBTN1_UV_X, TBTN1_UV_Y);

  initTopButton(TBTN2_CUBE, TBTN2_ORIGIN_X, TBTN_ORIGIN_Y, TBTN2_UV_X, TBTN2_UV_Y);

  initTopButton(TBTN3_CYLINDER, TBTN3_ORIGIN_X, TBTN_ORIGIN_Y, TBTN3_UV_X, TBTN3_UV_Y);

  initTopButton(TBTN4_CONE, TBTN4_ORIGIN_X, TBTN_ORIGIN_Y, TBTN4_UV_X, TBTN4_UV_Y);

  initTopButton(TBTN5_PLANE, TBTN5_ORIGIN_X, TBTN_ORIGIN_Y, TBTN5_UV_X, TBTN5_UV_Y);

  initTopButton(TBTN6_TORUS, TBTN6_ORIGIN_X, TBTN_ORIGIN_Y, TBTN6_UV_X, TBTN6_UV_Y);

  initTopButton(TBTN7_PYRAMID, TBTN7_ORIGIN_X, TBTN_ORIGIN_Y, TBTN7_UV_X, TBTN7_UV_Y);

  initTopButton(TBTN8_PIPE, TBTN8_ORIGIN_X, TBTN_ORIGIN_Y, TBTN8_UV_X, TBTN8_UV_Y);

  initTopButton(TBTN9_GAME, TBTN9_ORIGIN_X, TBTN_ORIGIN_Y, TBTN9_UV_X, TBTN9_UV_Y);



  initSideButton(SBTN1_SELECT, SBTN_ORIGIN_X, SBTN1_ORIGIN_Y, SBTN1_UV_X, SBTN1_UV_Y);

  initSideButton(SBTN2_MOVE, SBTN_ORIGIN_X, SBTN2_ORIGIN_Y, SBTN2_UV_X, SBTN2_UV_Y);

  initSideButton(SBTN3_ROTATE, SBTN_ORIGIN_X, SBTN3_ORIGIN_Y, SBTN3_UV_X, SBTN3_UV_Y);

  initSideButton(SBTN4_SCALE, SBTN_ORIGIN_X, SBTN4_ORIGIN_Y, SBTN4_UV_X, SBTN4_UV_Y);

  initSideButton(SBTN5_1VIEW, SBTN_ORIGIN_X, SBTN5_ORIGIN_Y, SBTN5_UV_X, SBTN5_UV_Y);

  initSideButton(SBTN6_4VIEW, SBTN_ORIGIN_X, SBTN6_ORIGIN_Y, SBTN6_UV_X, SBTN6_UV_Y); 

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


    for(std::vector<TopButton>::iterator it = topButtons.begin(); it != topButtons.end(); it++)
    {
      it->draw();
    }

    for(std::vector<SideButton>::iterator it = sideButtons.begin(); it != sideButtons.end(); it++)
    {
      it->draw();
    }

  glDisable(GL_BLEND);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

}

// -----------------------------------------------------------------------------

void Gui::initTopButton(int btnID, float x_, float y_, float uvx_, float uvy_)
{
  TopButton button;
  button.init(btnID, input, menuTexture, x_, y_, uvx_, uvy_);

  topButtons.push_back(button);

}

// -----------------------------------------------------------------------------

void Gui::initSideButton(int btnID, float x_, float y_, float uvx_, float uvy_)
{
  SideButton button;
  button.init(btnID, input, menuTexture, x_, y_, uvx_, uvy_);

  sideButtons.push_back(button);

}

// -----------------------------------------------------------------------------









// 80 //////////////////////////////////////////////////////////////////////////