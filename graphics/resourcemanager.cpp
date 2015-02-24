#include "resourcemanager.h"


ResourceManager::ResourceManager()
{

}


ResourceManager::~ResourceManager()
{

}


// -----------------------------------------------------------------------------

void ResourceManager::drawQuad()
{
  glBegin(GL_TRIANGLES);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);

  glEnd();

}

// -----------------------------------------------------------------------------

void ResourceManager::drawPlane(float width, float height, int sub_w, int sub_h)
{


}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getQuad()
{
  GLuint QuadDList = 0;
  
  glNewList(QuadDList, GL_COMPILE);		// Like glBegin and End

    drawQuad();

  glEndList();

  return QuadDList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getPlane(float width, float height, int sub_w, int sub_h)
{
  GLuint PlaneDList = 0;

  glNewList(PlaneDList, GL_COMPILE);		// Like glBegin and End

    drawPlane(width, height, sub_w, sub_h);

  glEndList();


  return PlaneDList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getCube()
{
  GLuint DispList = 0;
  
  return DispList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getSphere()     // made from quads, pitching on poles
{
  GLuint DispList = 0;
  
  return DispList;
}



GLuint ResourceManager::getSoccerBall() // Sphere from pentagons
{
  GLuint DispList = 0;
  
  return DispList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getCubeSPhere() // Sphere from cube
{
  GLuint DispList = 0;
  
  return DispList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getCylinder()
{
  GLuint DispList = 0;
  
  return DispList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getTorus()
{
  GLuint DispList = 0;
  
  return DispList;
}

// -----------------------------------------------------------------------------




// 80 //////////////////////////////////////////////////////////////////////////