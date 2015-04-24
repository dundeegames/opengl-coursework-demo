////////////////////////////////////////////////////////////////////////////////
/**
* \file       modelgenerator.h
* \brief      ModelGenerator class - AG0800A Graphics Programming
*
* \details    Proceduraly generates 3D primitives
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



#ifndef MODELGENERATOR_H
#define MODELGENERATOR_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <assets/model.h>
#include <math/vec3.h>


enum PlaneType{ PLN_LEFT,
                PLN_RIGHT,
                PLN_FRONT,
                PLN_CENTER,
                PLN_BACK,
                PLN_TOP,
                PLN_BOTTOM,
                PLN_SURFACE
              };

// CLASS ///////////////////////////////////////////////////////////////////////

class ModelGenerator
{

public:
  ModelGenerator();
  ~ModelGenerator();

  Model getQuad(float width = 1.0f, float height = 1.0f);

  Model getTriangle(float r = 1.0f);

  Model getPlane(float width = 1.0f, float height = 1.0f,
                 int subX = 1.0f, int subY = 1.0f, PlaneType type = PLN_CENTER);

  Model getCube(float width = 1.0f, float height = 1.0f, float depth = 1.0f,
                int subX = 1, int subY = 1, int subZ = 1);

  Model getCubeSPhere(float r, int sub);          // Sphere from cube

  Model getCylinder(float r, float h, int subR, int subH);

  Model getCone(float r, float h, int subR);

  Model getSphere(int subX, int subY, int subZ);  // made from quads, pitching on poles
  Model getSoccerBall();                          // Sphere from pentagons
  Model getTorus();


private:
  int vertexCount;
  std::vector<float> vertices, normals, uvs;

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

  void makePlane(int subW, int subH, PlaneType type);

  Vec3 getNormal(Vec3 v1, Vec3 v2, Vec3 v3);
  void cleanContainers();
};


#endif // MODELGENERATOR_H




// 80 //////////////////////////////////////////////////////////////////////////