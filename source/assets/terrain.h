////////////////////////////////////////////////////////////////////////////////
/**
* \file       terrain.h
* \brief      Terrain class - AG0800A Graphics Programming
*
* \details    generates and displays the terrain based on height map 
*
* \author     Jiri Klic
* \version    1.0
* \date       April 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////


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