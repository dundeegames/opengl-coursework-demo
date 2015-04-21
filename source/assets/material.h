// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                 Material class - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Apr 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef MATERIAL_H
#define MATERIAL_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class Material
{

public:
  Material();
  Material(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  Material(GLuint tex);

  ~Material();
  Material& operator=(const Material& m2);

  void render();

  void setAmbient(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setDiffuse(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setSpecular(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
  void setEmission(GLfloat R, GLfloat G, GLfloat B, GLfloat A);

  void setShininess(GLfloat shin) {shininess = shin;}
  void setTexture(GLuint tex) {texture = tex;}
  void setFace(GLenum face_) {face = face_;}

private:
  GLenum face;
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat emission[4];
  GLfloat shininess;
  GLuint texture;

  void init();

};


#endif // TEMP_H




// 80 //////////////////////////////////////////////////////////////////////////