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
#include <SOIL.h>




// CLASS ///////////////////////////////////////////////////////////////////////

class Model
{

public:
  Model();
  ~Model();
  Model& operator=(const Model& m2);

  void setTexture(GLuint texture_) {texture = texture_; }

  void setModel(int vCount, std::vector<float>& vert,
                std::vector<float>& norm, std::vector<float>& tex);

  void Render();


private:
  int m_vertexCount;
  GLuint texture;

  // vectors for storing model data, for your use
  std::vector<float> vertex, normals, texCoords;

};


#endif // MODEL_H




// 80 //////////////////////////////////////////////////////////////////////////