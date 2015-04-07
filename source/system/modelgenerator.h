// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                Scene3D class - - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Apr 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



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
                PLN_BOTTOM
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

  Model getSphere(int subX, int subY, int subZ);  // made from quads, pitching on poles
  Model getSoccerBall();                          // Sphere from pentagons
  Model getCubeSPhere();                          // Sphere from cube
  Model getCylinder();
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

  void makePlane(int subX, int subY, PlaneType type);

  Vec3 getNormal(Vec3 v1, Vec3 v2, Vec3 v3);
  void cleanContainers();
};


#endif // MODELGENERATOR_H




// 80 //////////////////////////////////////////////////////////////////////////