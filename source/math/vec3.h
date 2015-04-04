// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                   Vec3 class - WinAPI and OpenGL laboratory                 \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*    Based on:  Vec3 class.[2014].Paul Robertson                              \n
*                                                                             \n
*    Added rotation functionality                                             \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef VEC3_H
#define VEC3_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <cmath>
#include <iostream>






// CLASS ///////////////////////////////////////////////////////////////////////

class Vec3
{

public:
  Vec3(float x = 0, float y = 0, float z = 0);
  ~Vec3();

  Vec3 copy();


  Vec3& set(float x, float y, float z);
  Vec3& setX(float x);
  Vec3& setY(float y);
  Vec3& setZ(float z);

  float getX();
  float getY();
  float getZ();
 
  Vec3 add(const Vec3& v1, float scale=1.0);
  Vec3 subtract(const Vec3& v1, float scale=1.0);
  Vec3 scale(float scale);

  float dot(const Vec3& v2);
  Vec3 cross(const Vec3& v2);

  Vec3& normalize();
  float length();
  float lengthSquared();

  bool equals(const Vec3& v2, float epsilon);
  float operator[](int pos) const;

  Vec3 operator+(const Vec3& v2);
  Vec3 operator-(const Vec3& v2);

  Vec3& operator+=(const Vec3& v2);
  Vec3& operator-=(const Vec3& v2);

  /*!
  * rotates Vec3 in X, Y or Z axis by angle in degrees
  */
  Vec3 rotateInX(float angleX, float scale = 1.0f);
  Vec3 rotateInY(float angleY, float scale = 1.0f);
  Vec3 rotateInZ(float angleZ, float scale = 1.0f);
  //Vec3& rotateXY(float angleX, float angleY, float scale = 1.0f);

  // rotate by angle about axis v(x,y,z)
  Vec3 rotate(float angle, float x, float y, float z);
  
private:
  float elements[3];

};


#endif // VEC3_H




// 80 //////////////////////////////////////////////////////////////////////////