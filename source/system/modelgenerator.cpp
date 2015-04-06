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

Model ModelGenerator::getQuad(float width, float height)
{
  Model model;
  //float cosT, sinT;
  //float r = 1.0f / sqrt(2.0f);

  //for(float i = 45.0f; i < 360.0f; i += 180.0f)
  //{
  //  for(float theta = i; theta < (270.0f + i); theta += 90.0f)
  //  {
  //    // r = radius
  //    cosT = cosf(RADIANS(theta));
  //    sinT = sinf(RADIANS(theta));

  //    vertices.push_back( (r * cosT) );
  //    vertices.push_back( (r * sinT) );
  //    vertices.push_back(0.0f);

  //    normals.push_back(0.0f);
  //    normals.push_back(0.0f);
  //    normals.push_back(1.0f);

  //    uvs.push_back( ((cosT / (2.0f * r)) + 0.5f) );
  //    uvs.push_back( ((sinT / (2.0f * r)) + 0.5f) );

  //    vertexCount++;

  //  }
  //}
  float offsetX = (-width * 0.5f);
  float offsetY = (-height * 0.5f);

  //quadToTriangle(
  //                Vec3(),
  //                Vec3(),
  //                Vec3(),
  //                Vec3(),
  //                Vec3(),
  //              );







  vertices.push_back(offsetX + width);
  vertices.push_back(offsetY);
  vertices.push_back(0.0f);
  uvs.push_back(1.0f);
  uvs.push_back(0.0f);
      

  vertices.push_back(offsetX);
  vertices.push_back(offsetY);
  vertices.push_back(0.0f);
  uvs.push_back(0.0f);
  uvs.push_back(0.0f);
      

  vertices.push_back(offsetX);
  vertices.push_back(offsetY + height);
  vertices.push_back(0.0f);
  uvs.push_back(0.0f);
  uvs.push_back(1.0f);

      
  vertices.push_back(offsetX);
  vertices.push_back(offsetY + height);
  vertices.push_back(0.0f);
  uvs.push_back(0.0f);
  uvs.push_back(1.0f);
      

  vertices.push_back(offsetX + width);
  vertices.push_back(offsetY + height);
  vertices.push_back(0.0f);
  uvs.push_back(1.0f);
  uvs.push_back(1.0f);
      

  vertices.push_back(offsetX + width);
  vertices.push_back(offsetY);
  vertices.push_back(0.0f);
  uvs.push_back(1.0f);
  uvs.push_back(0.0f);


  for(int n=0; n < 6; n++)
  {
    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(1.0f);
  }

  vertexCount += 6;






  model.setModel(vertexCount, vertices, normals, uvs);
  //model.setScale(Vec3(w, h, 1.0f));
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

Model ModelGenerator::getPlane(float width, float height, int subX, int subY)
{
  //vertexCount = 0;
  Model model;
  float offsetX = (-width * 0.5f);
  float offsetY = (-height * 0.5f);
  float dx = (1.0f / (float)subX);
  float dy = (1.0f / (float)subY);
  float wdx = width * dx;
  float hdy = height * dy;


  for(int j = 0; j < subY; j++)
  {
    for(int i = 0; i < subX; i++)
    {
      vertices.push_back(offsetX + ((i+1) * wdx));
      vertices.push_back(offsetY + (j * hdy));
      vertices.push_back(0.0f);

      uvs.push_back((i+1) * dx);
      uvs.push_back(j * dy);
      

      vertices.push_back(offsetX + (i * wdx));
      vertices.push_back(offsetY + (j * hdy));
      vertices.push_back(0.0f);

      uvs.push_back(i * dx);
      uvs.push_back(j * dy);
      

      vertices.push_back(offsetX + (i * wdx));
      vertices.push_back(offsetY + ((j+1) * hdy));
      vertices.push_back(0.0f);

      uvs.push_back(i * dx);
      uvs.push_back((j+1) * dy);

      
      vertices.push_back(offsetX + (i * wdx));
      vertices.push_back(offsetY + ((j+1) * hdy));
      vertices.push_back(0.0f);

      uvs.push_back(i * dx);
      uvs.push_back((j+1) * dy);
      

      vertices.push_back(offsetX + ((i+1) * wdx));
      vertices.push_back(offsetY + ((j+1) * hdy));
      vertices.push_back(0.0f);

      uvs.push_back((i+1) * dx);
      uvs.push_back((j+1) * dy);
      

      vertices.push_back(offsetX + ((i+1) * wdx));
      vertices.push_back(offsetY + (j * hdy));
      vertices.push_back(0.0f);

      uvs.push_back((i+1) * dx);
      uvs.push_back(j * dy);


      for(int n=0; n < 6; n++)
      {
        normals.push_back(0.0f);
        normals.push_back(0.0f);
        normals.push_back(1.0f);
      }

      vertexCount += 6;

    }
  }

  model.setModel(vertexCount, vertices, normals, uvs);
  cleanContainers();
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

void ModelGenerator::quadToTriangle(Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4, Vec3* norm)
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

  vertices.push_back(v3.getX());
  vertices.push_back(v3.getY());
  vertices.push_back(v3.getZ());

  vertices.push_back(v4.getX());
  vertices.push_back(v4.getY());
  vertices.push_back(v4.getZ());

  vertices.push_back(v1.getX());
  vertices.push_back(v1.getY());
  vertices.push_back(v1.getZ());

  if(norm != NULL)
  {
    for(int n=0; n < 6; n++)
    {
      normals.push_back(norm->getX());
      normals.push_back(norm->getY());
      normals.push_back(norm->getZ());
    }
  }
  else
  {
    Vec3* tempN = new Vec3(getNormal(v1, v2, v3));

    for(int n=0; n < 3; n++)
    {
      normals.push_back(tempN->getX());
      normals.push_back(tempN->getY());
      normals.push_back(tempN->getZ());
    }


    *tempN = getNormal(v3, v4, v1);
    
    for(int n=0; n < 3; n++)
    {
      normals.push_back(tempN->getX());
      normals.push_back(tempN->getY());
      normals.push_back(tempN->getZ());
    }

    delete tempN;

  }

  vertexCount += 6;





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