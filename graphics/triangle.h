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
//#include "include/SOIL.h"
#include "geometry.h"



class Triangle : public Geometry
{

public:
  Triangle();
  ~Triangle();
  void draw();


private:


};


#endif // TRIANGLE_H




// 80 //////////////////////////////////////////////////////////////////////////