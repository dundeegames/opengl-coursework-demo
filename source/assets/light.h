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



enum Light_Type {L_AMBIENT, L_POINT, L_DIRECTIONAL, L_SPOT};


class Light
{

public:
  Light(int id_);
  ~Light();
  void init(Light_Type tp, GLfloat R, GLfloat G, GLfloat B, GLfloat A,
            GLfloat posX = 0.0f, GLfloat posY = 0.0f, GLfloat posZ = 0.0f,
            GLfloat dirX = 0.0f, GLfloat dirY = 0.0f, GLfloat dirZ = 0.0f,
            float cut = 0.0f, float exp = 45.0f
            );

  void setVisibility(bool vis) {visible = vis;}
  void render();


private:
  GLfloat Colour[4];
  GLfloat Position[4];
  GLfloat Direction[3];

  float CutOff;
  float Exponent;

  int id;
  Light_Type type;

  bool visible;

};


#endif // LIGHT_H



// 80 //////////////////////////////////////////////////////////////////////////