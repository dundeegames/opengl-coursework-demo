// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                Geometry class - - WinAPI and OpenGL laboratory              \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*       Used as Base Class for geometry primitives:                           \n
*                                                                             \n
*       Cube, Quad, Triangle, Sprite                                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////


#ifndef GEOMETRY_H
#define GEOMETRY_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
//#include <SOIL.h>

// TODO rotate(), rotateBy(); 


class Geometry
{

public:
  Geometry();
  ~Geometry();

  void setTexture(GLuint texture_) {myTexture = texture_; }

  void setColor3f(GLfloat red_, GLfloat green_, GLfloat blue_);
  void setColor4f(GLfloat red_, GLfloat green_, GLfloat blue_, GLfloat alpha_);
  void serOpacity(GLfloat alpha_) {alpha = alpha_; };


  virtual void draw() = 0;
  
  void setPosition(float x_, float y_);
  void move(float x_, float y_);

  inline const float x() const {return positionX; }
  inline const float y() const {return positionY; }
  inline const float z() const {return positionZ; }
  inline const float getWidth() const {return width; }
  inline const float getHeight() const {return height; }

  void setWidth(float w_) {width = w_; };
  void setHeight(float h_) {height = h_; };
  void setDepth(float d_) {depth = d_; };

  void set_uv_position(float x_, float y_);
  void set_uv_width(float w_) {uv_width = w_; };
  void set_uv_height(float h_) {uv_height = h_; };


protected:
  float positionX;
  float positionY;
  float positionZ;

  float width;
  float height;
  float depth;

  float uv_posX;
  float uv_posY;
  float uv_width;
  float uv_height;


  GLuint myTexture;
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat alpha;

};


#endif // GEOMETRY_H




// 80 //////////////////////////////////////////////////////////////////////////