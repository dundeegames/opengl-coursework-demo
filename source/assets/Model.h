// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                  Model class - WinAPI and OpenGL laboratory                 \n
*                         edited by Jiri Klic, Mar 2015                       \n
*                                                                             \n
*      Based on:                                                              \n
*         Beginning DirectX 11 Game Programming                               \n
*         By Allen Sherrod and Wendy Jones                                    \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef MODEL_H
#define MODEL_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>

#include <system/TokenStream.h>
#include <vector>
#include <math/vec3.h>
//#include <SOIL.h>
#include <math/vec3.h>



// CLASS ///////////////////////////////////////////////////////////////////////

class Model
{

public:
  Model();
  ~Model();
  Model& operator=(const Model& m2);

  void setTexture(GLuint texture_) {texture = texture_; }
  void setTiling(float w, float h);
  void setUVoffset(float u, float v);
  void moveUVoffset(float u, float v);

  //void setModel(int vCount, int mode_, std::vector<float>& vert,
  //              std::vector<float>& norm, std::vector<float>& tex);

  void setModel(int vCount, std::vector<float>& vert,
                std::vector<float>& norm, std::vector<float>& tex);

  void setScale(Vec3 s) {scale = s;}
  void resize(Vec3 s, float magnitude = 1.0) {scale.add(s, magnitude);}

  void setRotation(Vec3 r) {rotation = r;}
  void rotate(Vec3 r, float magnitude = 1.0) {rotation.add(r, magnitude);}

  void setPosition(Vec3 p) {position = p;}
  void move(Vec3 p, float magnitude = 1.0) {position.add(p, magnitude);}

  void setColour(float R=1.0f, float G=1.0f, float B=1.0f, float A=1.0f);

  void Render();


private:
  int mode;
  float colour[4];
  float tileW;
  float tileH;
  float offsetU;
  float offsetV;


  Vec3 position;
  Vec3 rotation;
  Vec3 scale;

  int m_vertexCount;
  GLuint texture;

  // vectors for storing model data, for your use
  std::vector<float> vertex, normals, texCoords;

};


#endif // MODEL_H




// 80 //////////////////////////////////////////////////////////////////////////