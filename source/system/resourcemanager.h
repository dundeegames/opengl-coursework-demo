// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*             ResourceManager class - WinAPI and OpenGL laboratory            \n
*                             by Jiri Klic, Feb 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
#include <soil/SOIL.h>

#include <map>


// CLASS ///////////////////////////////////////////////////////////////////////

class ResourceManager
{

public:
  ResourceManager();
  ~ResourceManager();

  GLuint getTexture(const char* file);
  


  // returns display list
  // TODO edit for different subdivisions in x and y
  GLuint getQuad();
  GLuint getPlane(float width, float height, int sub_w, int sub_h);
  GLuint getCube();
  GLuint getSphere();     // made from quads, pitching on poles
  GLuint getSoccerBall(); // Sphere from pentagons
  GLuint getCubeSPhere(); // Sphere from cube

  GLuint getCylinder();

  GLuint getTorus();

private:
  void drawQuad();
  void drawPlane(float width, float height, int sub_w, int sub_h);

  std::map<const char*, GLuint> texture_list;
  void loadTexture(const char* file);


};


#endif // RESOURCE_MANAGER_H




// 80 //////////////////////////////////////////////////////////////////////////