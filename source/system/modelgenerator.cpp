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

Model ModelGenerator::getQuad()
{
  Model model;
  vertexCount = 6;

  Vec3 vecs[] = {
                  Vec3(-0.5f, 0.5f, 0.0f),
                  Vec3(-0.5f, -0.5f, 0.0f),
                  Vec3(0.5f, -0.5f, 0.0f),
                  Vec3(0.5f, 0.5f, 0.0f),
                };

  setTriangle(vecs[0], vecs[1], vecs[2]);
  setTriangle(vecs[2], vecs[3], vecs[0]);


  float texC;

  for(int j = 0; j < 4; j++)
  {
    switch(j)
    {
    case 0:
    case 3:
      texC = 0.0f;
      break;
        
    case 1:
    case 2:
      texC = 1.0f;
      break;
        
    default:
      exit(-1);
    }

    for(int i = 0; i < 3; i++)
    {
      uvs.push_back(texC);
    }
  }

  for(int n = 0; n < vertexCount; n++)
  {
    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(1.0f);
  }

  //float verts[] = {
  //                  -0.5f, 0.5f, 0.5f,
  //                  -0.5f, -0.5f, 0.5f,
  //                  0.5f, -0.5f, 0.5f,
  //                  0.5f, -0.5f, 0.5f,
  //                  0.5f, 0.5f, 0.5f,
  //                  -0.5f, 0.5f, 0.5f    
  //                };


  //float norms[] = {
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f,
  //                  0.0f, 0.0f, 1.0f    
  //                };

  //float texC[] = {
  //                  0.0f, 0.0f,
  //                  0.0f, 1.0f,
  //                  1.0f, 1.0f,
  //                  1.0f, 1.0f,
  //                  1.0f, 0.0f,
  //                  0.0f, 0.0f 
  //                };

  //vertices.assign(verts, verts + 18);
  //normals.assign(norms, norms + 18);
  //uvs.assign(texC, texC + 12);

  model.setModel(vertexCount, vertices, normals, uvs);
  cleanContainers();

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getTriangle()
{
  Model model;
  float x, y;


  for(float theta = 90.0f; theta < 360.0f; theta += 120.0f)
  {
    // radius = 1.0
    x = cosf(RADIANS(theta));
    y = sinf(RADIANS(theta));

    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(0.0f);

    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(1.0f);

    uvs.push_back( ((x * 0.5f) + 0.5f) );
    uvs.push_back( ((y * 0.5f) + 0.5f) );

  }

  model.setModel(3, vertices, normals, uvs);

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