#include <assets/triangle.h>


float verts[] = {
                  0.0f, 0.5f, 0.5f,
                  -0.5f, -0.5f, 0.5f,
                  0.5f, -0.5f, 0.5f
                };

float normals[] = {
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                  };

float uvs[] = {
                0.0f, 0.0f,
                0.0f, 1.0f,
                1.0f, 1.0f
              };





  //float verts[] = {
  //                  -0.5f, 0.5f, 0.5f,
  //                  -0.5f, -0.5f, 0.5f,
  //                  0.5f, -0.5f, 0.5f,
  //                  0.5f, -0.5f, 0.5f,
  //                  0.5f, 0.5f, 0.5f,
  //                  -0.5f, 0.5f, 0.5f    
  //                };


  //float normals[] = {
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f    
  //                };

  //float uvs[] = {
  //                  0.0f, 0.0f,
  //                  0.0f, 1.0f,
  //                  1.0f, 1.0f,
  //                  1.0f, 1.0f,
  //                  1.0f, 0.0f,
  //                  0.0f, 0.0f 
  //                };

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
  //glBindTexture(GL_TEXTURE_2D, myTexture);  //tells opengl which texture to use

  //glBegin(GL_TRIANGLES);

  //  // front face
  //  glColor3f(red, green, blue);

  //  glNormal3f(0.0f, 0.0f, 1.0f);
  //  glTexCoord2f(0.0f, 0.0f);
  //  glVertex3f(slope, 0.5f, 0.5f);

  //  glNormal3f(0.0f, 0.0f, 1.0f);
  //  glTexCoord2f(0.0f, 1.0f);
  //  glVertex3f(-0.5f, -0.5f, 0.5f);

  //  glNormal3f(0.0f, 0.0f, 1.0f);
  //  glTexCoord2f(1.0f, 1.0f);
  //  glVertex3f(0.5f, -0.5f, 0.5f);


  //  glColor3f(1.0f, 1.0f, 1.0f); // reset colour

  //glEnd();


  //glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL

  //ver.assign(verts, verts + 18);
  //nor.assign(normals, normals + 18);
  //tex.assign(uvs, uvs + 12);



  glColor3f(red, green, blue);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);



  glVertexPointer (3, GL_FLOAT, 0, verts);
  glNormalPointer (GL_FLOAT, 0, normals);
  glTexCoordPointer(2, GL_FLOAT, 0, uvs);
  //glVertexPointer (3, GL_FLOAT, 0, ver.data());
  //glNormalPointer (GL_FLOAT, 0, nor.data());
  //glTexCoordPointer(2, GL_FLOAT, 0, tex.data());


  //dereferencing method of choice
  glPushMatrix();
    glDrawArrays(GL_TRIANGLES, 0, 6);
  glPopMatrix();



  glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);

  glColor3f(1.0f, 1.0f, 1.0f); // reset colour


}






// 80 //////////////////////////////////////////////////////////////////////////