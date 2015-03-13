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
using namespace std;

// MY CLASS INCLUDES ///////////////////////////////////////////////////////////
#include <system/TokenStream.h>
#include <vector>
#include <math/vec3.h>
#include <SOIL.h>


class Model
{

public:
  Model();
  ~Model();


  bool Load(char* modelFilename, char* textureFilename);

  void LoadTexture(char*);
  bool LoadModel(char*);

  void Render();


private:  
  int m_vertexCount;
  GLuint texture;

  // vectors for storing model data, for your use
  vector<float> vertex, normals, texCoords;

};


#endif // MODEL_H




// 80 //////////////////////////////////////////////////////////////////////////