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
#include "include/SOIL.h"


class ResourceManager
{

public:
  ResourceManager();
  ~ResourceManager();

  // returns display list
  // TODO edit for different subdivisions in x and y
  GLuint getQuad();
  GLuint getPlane();
  GLuint getCube();
  GLuint getSphere();     // made from quads, pitching on poles
  GLuint getSoccerBall(); // Sphere from pentagons
  GLuint getCubeSPhere(); // Sphere from cube

  GLuint getCylinder();

  GLuint getTorus();

private:


};


#endif // RESOURCE_MANAGER_H




// 80 //////////////////////////////////////////////////////////////////////////