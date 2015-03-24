// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                 Sprite class - - WinAPI and OpenGL laboratory               \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*    Usend for menu                                                           \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef SPRITE_H
#define SPRITE_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>




class Sprite
{

public:
  Sprite();
  ~Sprite();
  void setValues(GLuint tex_ = NULL, float x_ = 0.0f, float y_ = 0.0f,
                                     float w_ = 100.0f, float h_ = 100.0f,
                                     float uvx_ = 0.0f, float uvy_ = 0.0f,
                                     float uvw = 1.0f, float uvh = 1.0f);

  void draw();

  void setTexture(GLuint texture_) {myTexture = texture_; }

  void setColor3f(GLfloat red_, GLfloat green_, GLfloat blue_);
  void setColor4f(GLfloat red_, GLfloat green_, GLfloat blue_, GLfloat alpha_);
  void serOpacity(GLfloat alpha_) {alpha = alpha_; };
  
  void setPosition(float x_, float y_);
  void move(float x_, float y_);

  inline const float x() const {return positionX; }
  inline const float y() const {return positionY; }
  inline const float getWidth() const {return width; }
  inline const float getHeight() const {return height; }

  void setWidth(float w_) {width = w_; };
  void setHeight(float h_) {height = h_; };

  void set_uv_position(float x_, float y_);
  void set_uv_width(float w_) {uv_width = w_; };
  void set_uv_height(float h_) {uv_height = h_; };


private:
  float positionX;
  float positionY;

  float width;
  float height;

  float uv_posX;
  float uv_posY;
  float uv_width;
  float uv_height;


  GLuint myTexture;
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat alpha;



  GLuint DisplayList;

  void setDList();

};


#endif // SPRITE_H




// 80 //////////////////////////////////////////////////////////////////////////