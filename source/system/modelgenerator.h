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








// CLASS ///////////////////////////////////////////////////////////////////////

class ModelGenerator
{

public:
  ModelGenerator();
  ~ModelGenerator();

  Model getQuad(float width = 1.0f, float height = 1.0f);
  Model getTriangle(float r = 1.0f);

  Model getPlane(float width, float height, int subX, int subY);
  Model getCube(int subX, int subY, int subZ);
  Model getSphere(int subX, int subY, int subZ);  // made from quads, pitching on poles
  Model getSoccerBall();                          // Sphere from pentagons
  Model getCubeSPhere();                          // Sphere from cube
  Model getCylinder();
  Model getTorus();


private:
  int vertexCount;
  std::vector<float> vertices, normals, uvs;

  void quadToTriangle(Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4, Vec3* norm = NULL);
  Vec3 getNormal(Vec3 v1, Vec3 v2, Vec3 v3);
  void cleanContainers();
};


#endif // MODELGENERATOR_H




// 80 //////////////////////////////////////////////////////////////////////////