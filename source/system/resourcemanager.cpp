#include "resourcemanager.h"


ResourceManager::ResourceManager()
{

}


ResourceManager::~ResourceManager()
{

}


// -----------------------------------------------------------------------------

GLuint ResourceManager::getTexture(const char* file)
{
  if(texture_list.find(file) == texture_list.end())
  {
    loadTexture(file);
  }

  return texture_list[file];

}

// -----------------------------------------------------------------------------

void ResourceManager::loadTexture(const char* file)
{
   /*!
  * Load a PNG using the SOIL (Simple OpenGL Image  Library)
  */
  texture_list[file] = SOIL_load_OGL_texture(file,
               SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
               SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
               );

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
  
  glNewList(QuadDList, GL_COMPILE);    // Like glBegin and End

    drawQuad();

  glEndList();

  return QuadDList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getPlane(float width, float height, int sub_w, int sub_h)
{
  GLuint PlaneDList = 0;

  glNewList(PlaneDList, GL_COMPILE);    // Like glBegin and End

    drawPlane(width, height, sub_w, sub_h);

  glEndList();


  return PlaneDList;
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getCube()
{
  GLuint CubeDList = 0;

  glNewList(CubeDList, GL_COMPILE);    // Like glBegin and End

    //drawPlane(width, height, sub_w, sub_h);

  glEndList();


  return CubeDList;
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