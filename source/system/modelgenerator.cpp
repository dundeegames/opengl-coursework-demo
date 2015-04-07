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

  quadToTriangle(
                  Vec3(QUAD_LFT, QUAD_TOP, 0.0f),
                  Vec3(QUAD_LFT, QUAD_BTM, 0.0f),
                  Vec3(QUAD_RGT, QUAD_BTM, 0.0f),
                  Vec3(QUAD_RGT, QUAD_TOP, 0.0f)
                );

  for(int n=0; n < 6; n++)
  {
    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(1.0f);
  }

  model.setModel(vertexCount, vertices, normals, uvs);
  model.setScale(Vec3(width, height, 1.0f));
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

Model ModelGenerator::getPlane(float width, float height, int subX, int subY, PlaneType type)
{
  Model model;

  makePlane(subX, subY, type);

  model.setModel(vertexCount, vertices, normals, uvs);
  model.setScale(Vec3(width, height, 1.0f));
  cleanContainers();
  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getCube(float width, float height, float depth,
                              int subX, int subY, int subZ)
{
  Model model;


  makePlane(subX, subY, PLN_FRONT);
  makePlane(subX, subY, PLN_BACK);

  model.setModel(vertexCount, vertices, normals, uvs);
  model.setScale(Vec3(width, height, depth));
  cleanContainers();

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

void ModelGenerator::quadToTriangle(Vec3 vTL, Vec3 vBL, Vec3 vBR, Vec3 vTR,
                                    float uvL, float uvT, float uvR, float uvB)
{
  vertices.push_back(vTL.getX());
  vertices.push_back(vTL.getY());
  vertices.push_back(vTL.getZ());

  uvs.push_back(uvL);
  uvs.push_back(uvT);


  vertices.push_back(vBL.getX());
  vertices.push_back(vBL.getY());
  vertices.push_back(vBL.getZ());

  uvs.push_back(uvL);
  uvs.push_back(uvB);


  vertices.push_back(vBR.getX());
  vertices.push_back(vBR.getY());
  vertices.push_back(vBR.getZ());

  uvs.push_back(uvR);
  uvs.push_back(uvB);


  vertices.push_back(vBR.getX());
  vertices.push_back(vBR.getY());
  vertices.push_back(vBR.getZ());

  uvs.push_back(uvR);
  uvs.push_back(uvB);


  vertices.push_back(vTR.getX());
  vertices.push_back(vTR.getY());
  vertices.push_back(vTR.getZ());

  uvs.push_back(uvR);
  uvs.push_back(uvT);


  vertices.push_back(vTL.getX());
  vertices.push_back(vTL.getY());
  vertices.push_back(vTL.getZ());

  uvs.push_back(uvL);
  uvs.push_back(uvT);


  vertexCount += 6;

}

// -----------------------------------------------------------------------------

void ModelGenerator::makePlane(int subX, int subY, PlaneType type)
{
  float dx = (1.0f / (float)subX);
  float dy = (1.0f / (float)subY);
  float x1 = 0.0f;
  float x2 = 0.0f;
  float y1 = 0.0f;
  float y2 = 0.0f;


  for(int j = 0; j < subY; j++)
  {
    for(int i = 0; i < subX; i++)
    {
      x1 = PLANE_OFFX + (i * dx);
      x2 = PLANE_OFFX + ((i+1) * dx);
      y1 = PLANE_OFFY + (j * dy);
      y2 = PLANE_OFFY + ((j+1) * dy);

      switch(type)
      {
      case PLN_LEFT:
        //quadToTriangle(
        //                Vec3(x1, y1, 0.0f),
        //                Vec3(x1, y2, 0.0f),                      
        //                Vec3(x2, y2, 0.0f),
        //                Vec3(x2, y1, 0.0f),
        //                i * dx,
        //                j * dy,
        //                (i+1) * dx,
        //                (j+1) * dy
        //              );

        //for(int n=0; n < 6; n++)
        //{
        //  normals.push_back(0.0f);
        //  normals.push_back(0.0f);
        //  normals.push_back(1.0f);
        //}
        break;

      case PLN_RIGHT:
        //quadToTriangle(
        //                Vec3(x1, y1, 0.0f),
        //                Vec3(x1, y2, 0.0f),                      
        //                Vec3(x2, y2, 0.0f),
        //                Vec3(x2, y1, 0.0f),
        //                i * dx,
        //                j * dy,
        //                (i+1) * dx,
        //                (j+1) * dy
        //              );

        //for(int n=0; n < 6; n++)
        //{
        //  normals.push_back(0.0f);
        //  normals.push_back(0.0f);
        //  normals.push_back(1.0f);
        //}
        break;

      case PLN_FRONT:
        quadToTriangle(
                        Vec3(x1, y1, 0.5f),
                        Vec3(x1, y2, 0.5f),                      
                        Vec3(x2, y2, 0.5f),
                        Vec3(x2, y1, 0.5f),
                        i * dx,
                        j * dy,
                        (i+1) * dx,
                        (j+1) * dy
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(0.0f);
          normals.push_back(1.0f);
        }
        break;


      case PLN_CENTER:
        quadToTriangle(
                        Vec3(x1, y1, 0.0f),
                        Vec3(x1, y2, 0.0f),                      
                        Vec3(x2, y2, 0.0f),
                        Vec3(x2, y1, 0.0f),
                        i * dx,
                        j * dy,
                        (i+1) * dx,
                        (j+1) * dy
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(0.0f);
          normals.push_back(1.0f);
        }
        break;


      case PLN_BACK:
        quadToTriangle(
                        Vec3(x2, y1, -0.5f),
                        Vec3(x2, y2, -0.5f),                      
                        Vec3(x1, y2, -0.5f),
                        Vec3(x1, y1, -0.5f),
                        i * dx,
                        j * dy,
                        (i+1) * dx,
                        (j+1) * dy
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(0.0f);
          normals.push_back(-1.0f);
        }
        break;

      case PLN_TOP:
        //quadToTriangle(
        //                Vec3(x1, y1, 0.0f),
        //                Vec3(x1, y2, 0.0f),                      
        //                Vec3(x2, y2, 0.0f),
        //                Vec3(x2, y1, 0.0f),
        //                i * dx,
        //                j * dy,
        //                (i+1) * dx,
        //                (j+1) * dy
        //              );

        //for(int n=0; n < 6; n++)
        //{
        //  normals.push_back(0.0f);
        //  normals.push_back(0.0f);
        //  normals.push_back(1.0f);
        //}
        break;

      case PLN_BOTTOM:
        //quadToTriangle(
        //                Vec3(x1, y1, 0.0f),
        //                Vec3(x1, y2, 0.0f),                      
        //                Vec3(x2, y2, 0.0f),
        //                Vec3(x2, y1, 0.0f),
        //                i * dx,
        //                j * dy,
        //                (i+1) * dx,
        //                (j+1) * dy
        //              );

        //for(int n=0; n < 6; n++)
        //{
        //  normals.push_back(0.0f);
        //  normals.push_back(0.0f);
        //  normals.push_back(1.0f);
        //}
        break;


      default:
        break;
      }

    }
  }

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