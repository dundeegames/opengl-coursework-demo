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
#include <assets/model.h>
#include <assets/material.h>
#include <system/modelgenerator.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class Terrain
{

public:
  Terrain();
  ~Terrain();

  // Pass ModelGenerator* to have a water
  void init(const char* htMap, ModelGenerator* mdGen, bool waterActive = true);
  void setScale(Vec3 s);
  void setMaterial(Material* mat) {material = mat; }
  void setSeaMaterial(Material* mat) {water.setMaterial(mat); }
  void setTiling(float w, float h);
  void setSeaTiling(float w, float h) {water.setTiling(w, h);}

  void update(float dt);

  void render();
  void display();

private:
  Vec3 scale;
  float tileW;
  float tileH;
  Material* material;

  GLuint terrainDlist;

  int vertexCount;
  std::vector<float> vertices, normals, uvs;

  bool renderWater;
  Model water;


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