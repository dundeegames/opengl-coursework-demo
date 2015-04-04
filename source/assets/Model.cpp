#include <assets/model.h>


Model::Model()
{
  //ready = true;
  m_vertexCount = NULL;
  texture = NULL;

  position = Vec3();
  rotation = Vec3();
  scale = Vec3(1.0f, 1.0f, 1.0f);

  setColour();

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

//void Model::setModel(int vCount, int mode_, std::vector<float>& vert,
//                     std::vector<float>& norm, std::vector<float>& tex)
void Model::setModel(int vCount, std::vector<float>& vert,
                     std::vector<float>& norm, std::vector<float>& tex)
{
  //mode = mode_;
  m_vertexCount = vCount;
  vertex = vert;
  normals = norm;
  texCoords = tex;

}

// -----------------------------------------------------------------------------

void Model::Render()
{
  
  

  // enble and specify pointers to vertex arrays
  glBindTexture(GL_TEXTURE_2D, texture);  //tells opengl which texture to use

  glEnable(GL_BLEND);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  //glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);



  glVertexPointer (3, GL_FLOAT, 0, vertex.data());
  glNormalPointer (GL_FLOAT, 0, normals.data());
  //glColorPointer(3, GL_FLOAT, 0, colors.data());
  glTexCoordPointer(2, GL_FLOAT, 0, texCoords.data());

  glColor4f(colour[0], colour[1], colour[2], colour[3]);

  //dereferencing method of choice
  glPushMatrix();
    glTranslatef(position.getX(), position.getY(), position.getZ());
    glRotatef(rotation.getX(), 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.getY(), 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.getZ(), 0.0f, 0.0f, 1.0f);
    glScalef(scale.getX(), scale.getY(), scale.getZ());

    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
    //glDrawArrays(mode, 0, m_vertexCount);     // bug with generated models
  glPopMatrix();

  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);    // reset colour

  glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
  glDisableClientState(GL_NORMAL_ARRAY);
  //glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisable(GL_BLEND);


  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL
  
}

// -----------------------------------------------------------------------------

void Model::setColour(float R, float G, float B, float A)
{
  colour[0] = R;
  colour[1] = G;
  colour[2] = B;
  colour[3] = A;
}

// -----------------------------------------------------------------------------










// 80 //////////////////////////////////////////////////////////////////////////