// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                Terrain class - - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Apr 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef TERRAIN_H
#define TERRAIN_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
#include <soil/SOIL.h>
#include <vector>

#include <math/vec3.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class Terrain
{

public:
  Terrain();
  ~Terrain();

  void init(const char* file);
  void render();
  void display();

private:
  Vec3 scale;
  GLuint texture;
  GLuint terrainDlist;

  int vertexCount;
  std::vector<float> vertices, normals, uvs;


  void loadTerrain(const char* file);

  /*!
  * vTL - vertex TopLeft,
  * vBL - vertex BottomLeft,
  * vBR - vertex BottmRight,
  * vTR - vertex TopRight,
  * uvL - uvCoord Left,
  * uvR - uvCoord Right,
  * uvT - uvCoord Top,
  * uvB - uvCoord Bottom
  */
  void quadToTriangle(Vec3 vTL, Vec3 vBL, Vec3 vBR, Vec3 vTR,
                      float uvL = 0.0f, float uvT = 0.0f,
                      float uvR = 1.0f, float uvB = 1.0f);


  Vec3 getNormal(Vec3 v1, Vec3 v2, Vec3 v3);


  void compileTerrain();

  void cleanContainers();








};


#endif // TERRAIN_H




// 80 //////////////////////////////////////////////////////////////////////////