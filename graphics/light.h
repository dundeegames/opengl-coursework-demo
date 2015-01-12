#ifndef LIGHT_H
#define LIGHT_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>


class Light
{

public:
  Light(int id_);
  ~Light();
  void init(GLfloat aR, GLfloat aG, GLfloat aB, GLfloat aA,  GLfloat dR, GLfloat dG, GLfloat dB, GLfloat dA, GLfloat x, GLfloat y, GLfloat z, GLfloat t);
  void render();


private:
  int id;
  GLfloat Ambient[4];
  GLfloat Diffuse[4];
  GLfloat Position[4];


};


#endif