// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                       Light class - Graphics programming                    \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef LIGHT_H
#define LIGHT_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>



enum Light_Type {AMBIENT, DIFFUSE, DIRECTIONAL};


class Light
{

public:
  Light(int id_);
  ~Light();
  void init(Light_Type tp, GLfloat R, GLfloat G, GLfloat B, GLfloat A,
            GLfloat x = 0.0f, GLfloat y = 0.0f, GLfloat z = 0.0f);

  void render();


private:
  GLfloat Colour[4];
  GLfloat Position[4];
  int id;
  Light_Type type;

};


#endif // LIGHT_H



// 80 //////////////////////////////////////////////////////////////////////////