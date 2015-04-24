////////////////////////////////////////////////////////////////////////////////
/**
* \file       model.cpp
* \brief      Model class - AG0800A Graphics Programming
*
* \details    original provided during laboratory exercise
*             Removed:  model loading moved to ResourceManager
*             Added:    material
*                       texture tiling and scrolling
*                       fuctionality for translation, roation and scale
*
* \author     Jiri Klic
* \author     
* \version    2.0
* \date       March 2015
* \date       February 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo
*
* \copyright  A.Sherrod and W. Jones.2011.Beginning DirectX 11 Game Programming.
*             Delmar Cengage Learning.
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////





// INCLUDES ////////////////////////////////////////////////////////////////////
#include <assets/model.h>
#include <system/macros.h>



// FUNCTIONS ///////////////////////////////////////////////////////////////////


Model::Model()
{
  //ready = true;
  m_vertexCount = NULL;

  position = Vec3();
  rotation = Vec3();
  scale = Vec3(1.0f, 1.0f, 1.0f);

  tileW = 1.0f;
  tileH = 1.0f;
  offsetU = 0.0f;
  offsetV = 0.0f;

  material = NULL;

}

// -----------------------------------------------------------------------------

Model::~Model()
{


}

// -----------------------------------------------------------------------------

Model& Model::operator=(const Model& m2)
{
  this->m_vertexCount = m2.m_vertexCount;
  this->material = m2.material;
  this->vertex = m2.vertex;
  this->normals = m2.normals;
  this->texCoords = m2.texCoords;

  return *this;
}

// -----------------------------------------------------------------------------

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
  if(material != NULL)
  {
    material->render();
  }

  glPushMatrix();
    glTranslatef(position.getX(), position.getY(), position.getZ());
    glRotatef(rotation.getX(), 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.getY(), 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.getZ(), 0.0f, 0.0f, 1.0f);
    glScalef(scale.getX(), scale.getY(), scale.getZ());  
  
  //glEnable(GL_BLEND);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glTranslatef(offsetU, offsetV, 0.0f);
    glScalef(tileW, tileH, 0.0f);

  glMatrixMode(GL_MODELVIEW);



  // enble and specify pointers to vertex arrays
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);

  glVertexPointer (3, GL_FLOAT, 0, vertex.data());
  glNormalPointer (GL_FLOAT, 0, normals.data());
  glTexCoordPointer(2, GL_FLOAT, 0, texCoords.data());


    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);


  glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  //glDisable(GL_BLEND);

  glBindTexture(GL_TEXTURE_2D, NULL);  //tells opengl which texture to use

  glMatrixMode(GL_TEXTURE);
    glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

  if(material != NULL)
  {
    material->cleanup();
  }

  //glPopAttrib(); 

}

// -----------------------------------------------------------------------------

void Model::setTiling(float w, float h)
{
  tileW = w;
  tileH = h;
}

// -----------------------------------------------------------------------------

void Model::setUVoffset(float u, float v)
{
  offsetU = u;
  offsetV = v;
}

// -----------------------------------------------------------------------------

void Model::moveUVoffset(float u, float v)
{
  offsetU += u;
  offsetV += v;
}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////