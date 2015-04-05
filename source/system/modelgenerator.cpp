#include <system/modelgenerator.h>
#include <system/macros.h>


ModelGenerator::ModelGenerator()
{
  vertexCount = 0;
}


ModelGenerator::~ModelGenerator()
{

}


// -----------------------------------------------------------------------------

Model ModelGenerator::getQuad(float w, float h)
{
  Model model;
  float cosT, sinT;
  float r = 1.0f / sqrt(2.0f);

  for(float i = 45.0f; i < 360.0f; i += 180.0f)
  {
    for(float theta = i; theta < (270.0f + i); theta += 90.0f)
    {
      // r = radius
      cosT = cosf(RADIANS(theta));
      sinT = sinf(RADIANS(theta));

      vertices.push_back( (r * cosT) );
      vertices.push_back( (r * sinT) );
      vertices.push_back(0.0f);

      normals.push_back(0.0f);
      normals.push_back(0.0f);
      normals.push_back(1.0f);

      uvs.push_back( ((cosT / (2.0f * r)) + 0.5f) );
      uvs.push_back( ((sinT / (2.0f * r)) + 0.5f) );

      vertexCount++;

    }
  }

  model.setModel(vertexCount, vertices, normals, uvs);
  model.setScale(Vec3(w, h, 1.0f));
  cleanContainers();

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getTriangle(float r)
{
  Model model;
  float cosT, sinT;


  for(float theta = 90.0f; theta < 360.0f; theta += 120.0f)
  {
    // r = radius
    cosT = cosf(RADIANS(theta));
    sinT = sinf(RADIANS(theta));

    vertices.push_back( (r * cosT) );
    vertices.push_back( (r * sinT) );
    vertices.push_back(0.0f);

    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(1.0f);

    uvs.push_back( ((cosT / (2.0f * r)) + 0.5f) );
    uvs.push_back( ((sinT / (2.0f * r)) + 0.5f) );

    vertexCount++;

  }

  model.setModel(vertexCount, vertices, normals, uvs);

  cleanContainers();

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getPlane(int subX, int subY)
{
  vertexCount = 0;


  float dx = (1.0f / (float)subX);
  float dy = (1.0f / (float)subY);

  for(int j = 0; j < subY; j++)
  {
    for(int i = 0; i < subX; i++)
    {


    }
  }





  Model model;

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getCube(int subX, int subY, int subZ)
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getSphere(int subX, int subY, int subZ)
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getSoccerBall()
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getCubeSPhere()
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getCylinder()
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getTorus()
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

void ModelGenerator::setTriangle(Vec3 v1, Vec3 v2, Vec3 v3)
{
  vertices.push_back(v1.getX());
  vertices.push_back(v1.getY());
  vertices.push_back(v1.getZ());

  vertices.push_back(v2.getX());
  vertices.push_back(v2.getY());
  vertices.push_back(v2.getZ());

  vertices.push_back(v3.getX());
  vertices.push_back(v3.getY());
  vertices.push_back(v3.getZ());

}

// -----------------------------------------------------------------------------

Vec3 ModelGenerator::getNormal(Vec3 v1, Vec3 v2, Vec3 v3)
{
  Vec3 normal = (v3 - v2).cross(v1 - v2);

  return normal;
}

// -----------------------------------------------------------------------------

void ModelGenerator::cleanContainers()
{
  vertexCount = 0;
  vertices.clear();
  normals.clear();
  uvs.clear();
}

// -----------------------------------------------------------------------------












// 80 //////////////////////////////////////////////////////////////////////////