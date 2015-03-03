#include "Shape.h"

Shape::Shape()
{


}

Shape::~Shape()
{


}

// -----------------------------------------------------------------------------


extern GLubyte indices[] = { 0,   1,   2,  //front
                             0,   2,   3,
                           };

extern float verts[] = {  -1.0,  1.0, 1.0,    // Vertex #0
                          -1.0, -1.0, 1.0,    // Vertex #1
                           1.0, -1.0, 1.0,    // Vertex #2
                           1.0,  1.0, 1.0,    // Vertex #3
                           //1.0, -1.0, 1.0
                       };
  
extern float norms[] = { 0.0, 0.0, 1.0,    //0
                         0.0, 0.0, 1.0,    //1
                         0.0, 0.0, 1.0,    //2
                         0.0, 0.0, 1.0,    //3
                       };    
  
  
extern float texcoords[] = {  0.0, 0.0,     //0
                              0.0, 1.0,     //1
                               1.0, 1.0,     //2
                              1.0, 0.0,     //3
                           };




// -----------------------------------------------------------------------------

void Shape::render1()
{
  // add code to render the cube (above) using method 1

  glBegin(GL_TRIANGLES);
    glArrayElement(2);
    glArrayElement(3);
    glArrayElement(5);
  glEnd();
  

}

// -----------------------------------------------------------------------------

void Shape::render2()
{
  // add code to render the cube (above) using method 2
  //glDrawArrays(type, offset, count)
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

// -----------------------------------------------------------------------------

void Shape::render3()
{
  // add code to render the cube (above) using method 3
  // glDrawElements()
  // glDrawElements(mode, count, type, indices) - Requires index array

  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

}


// 80 //////////////////////////////////////////////////////////////////////////