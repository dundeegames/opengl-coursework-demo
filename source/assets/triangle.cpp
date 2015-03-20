#include <assets/triangle.h>

Triangle::Triangle()
{
  slope = 0.0f;
}


Triangle::~Triangle()
{

}


// -----------------------------------------------------------------------------

void Triangle::draw()
{
  glBindTexture(GL_TEXTURE_2D, myTexture);  //tells opengl which texture to use

  glBegin(GL_TRIANGLES);

    // front face
    glColor3f(red, green, blue);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(slope, 0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);


    glColor3f(1.0f, 1.0f, 1.0f); // reset colour

  glEnd();


  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL



}






// 80 //////////////////////////////////////////////////////////////////////////