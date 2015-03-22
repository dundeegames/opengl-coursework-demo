#include <assets/model.h>


Model::Model()
{
  //ready = true;
  m_vertexCount = NULL;
  texture = NULL;
}

// -----------------------------------------------------------------------------

Model::~Model()
{


}

// -----------------------------------------------------------------------------

Model& Model::operator=(const Model& m2)
{
  this->m_vertexCount = m2.m_vertexCount;
  this->texture = m2.texture;
  this->vertex = m2.vertex;
  this->normals = m2.normals;
  this->texCoords = m2.texCoords;

  return *this;
}

// -----------------------------------------------------------------------------

void Model::setModel(int vCount, std::vector<float>& vert,
                     std::vector<float>& norm, std::vector<float>& tex)
{
  m_vertexCount = vCount;
  vertex = vert;
  normals = norm;
  texCoords = tex;

}

// -----------------------------------------------------------------------------

void Model::Render()
{
  // You must insert code here to render your model
  // This function will be called from Scene3D.drawScene()
  // enble and specify pointers to vertex arrays
  glBindTexture(GL_TEXTURE_2D, texture);  //tells opengl which texture to use

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  //glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);



  glVertexPointer (3, GL_FLOAT, 0, vertex.data());
  glNormalPointer (GL_FLOAT, 0, normals.data());
  //glColorPointer(3, GL_FLOAT, 0, colors.data());
  glTexCoordPointer(2, GL_FLOAT, 0, texCoords.data());



  //dereferencing method of choice
  glPushMatrix();
    //glTranslatef(10, 10, 30);                  // move to upper-right corner
    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
  glPopMatrix();



  glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
  glDisableClientState(GL_NORMAL_ARRAY);
  //glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);

  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL

}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////