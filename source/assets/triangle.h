// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*                                                                             \n
*                             by Jiri Klic, Jan 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



#ifndef TRIANGLE_H
#define TRIANGLE_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <Gl/gl.h>
#include <gl/glu.h>
#include <assets/geometry.h>



class Triangle : public Geometry
{

public:
  Triangle();
  ~Triangle();

  //! keep values cca [-1.0,1.0] sets slope of triangle
  void setSlope(float x_) {slope = x_;}
  void draw();


private:
  float slope;

};


#endif // TRIANGLE_H




// 80 //////////////////////////////////////////////////////////////////////////