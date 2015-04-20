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
  makePlane(subZ, subY, PLN_LEFT);
  makePlane(subZ, subY, PLN_RIGHT);
  makePlane(subX, subZ, PLN_TOP);
  makePlane(subX, subZ, PLN_BOTTOM);

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

Model ModelGenerator::getCubeSPhere(float r, int sub)
{
  Model model;
  Vec3 tempVec;

  makePlane(sub, sub, PLN_FRONT);
  makePlane(sub, sub, PLN_BACK);
  makePlane(sub, sub, PLN_LEFT);
  makePlane(sub, sub, PLN_RIGHT);
  makePlane(sub, sub, PLN_TOP);
  makePlane(sub, sub, PLN_BOTTOM);

  // normalize vertices
  for(int i = 0; i < vertexCount; i++)
  {
    tempVec = Vec3(vertices[(3*i)], vertices[((3*i) + 1)], vertices[((3*i) + 2)]);
    tempVec.normalize();

    vertices[(3*i)] = tempVec.getX();
    vertices[((3*i) + 1)] = tempVec.getY();
    vertices[((3*i) + 2)] = tempVec.getZ();
  }

  // normals same as pos vectors for vertices
  normals = vertices;

  model.setModel(vertexCount, vertices, normals, uvs);
  model.setScale(Vec3(r, r, r));
  cleanContainers();

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getCylinder(float r, float h, int subR, int subH)
{
  Model model;
  std::vector<float> cosT, sinT;;

  float dTheta = (360.0f / (float)subR);
  float dH = (1.0f / (float)subH); 
  float dW = (1.0f / (float)subR);
  float x1 = 0.0f;
  float x2 = 0.0f;
  float y1 = 0.0f;
  float y2 = 0.0f;
  float z1 = 0.0f;
  float z2 = 0.0f;

  float uvLeft = 0.0f;  
  float uvTop = 0.0f;   
  float uvRight = 0.0f; 
  float uvBottom = 0.0f;



  for(float theta = 0.0f; theta < 360.0f; theta += dTheta)
  {
    cosT.push_back(cosf(RADIANS(theta)) );
    sinT.push_back(sinf(RADIANS(theta)) );
  }

  // push back the orgin values again to complete cyrcle
  cosT.push_back(1.0f);
  sinT.push_back(0.0f);

  // Sides
  for(int j = 0; j < subH; j++)
  {
    for(int i = 0; i < subR; i++)
    {
      // TODO: once textured, make sure the Top and bottom are not flipped
      x1 = cosT[i];
      x2 = cosT[(i+1)];
      y1 = ((j+1) * dH);
      y2 = (j * dH);
      z1 = -sinT[i];
      z2 = -sinT[(i+1)];

      uvLeft =    (i * dW);
      uvTop =     (1 - (0.5*((j+1) * dH)));
      uvRight =   ((i+1) * dW);
      uvBottom =  (1 - (0.5*(j * dH)));

      quadToTriangle(
                      Vec3(x1, y1, z1),
                      Vec3(x1, y2, z1),                      
                      Vec3(x2, y2, z2),
                      Vec3(x2, y1, z2),
                      uvLeft,
                      uvTop,
                      uvRight,
                      uvBottom
                    );

    }
  }

  // Side normals are same as Side pos vectors
  normals = vertices;


  // Top Disk
  for(int i = 0; i < subR; i++)
  {
    // center
    vertices.push_back(0.0f);
    vertices.push_back(1.0f);
    vertices.push_back(0.0f);

    uvs.push_back(0.25f);
    uvs.push_back(0.25f);


    vertices.push_back(cosT[i]);
    vertices.push_back(1.0f);
    vertices.push_back(-sinT[i]);

    uvs.push_back((0.25f + (cosT[i]*0.25f)));
    uvs.push_back((0.25f - (sinT[i]*0.25f)));


    vertices.push_back(cosT[(i+1)]);
    vertices.push_back(1.0f);
    vertices.push_back(-sinT[(i+1)]);

    uvs.push_back((0.25f + (cosT[(i+1)]*0.25f)));
    uvs.push_back((0.25f - (sinT[i]*0.25f)));
    

    for(int n = 0; n < 3; n++)
    {
      normals.push_back(0.0f);
      normals.push_back(1.0f);
      normals.push_back(0.0f);
    }
    
    vertexCount += 3;
  }


  // Bottom Disk
  for(int i = 0; i < subR; i++)
  {
    // center
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    uvs.push_back(0.75f);
    uvs.push_back(0.75f);


    vertices.push_back(cosT[(i+1)]);
    vertices.push_back(0.0f);
    vertices.push_back(-sinT[(i+1)]);

    uvs.push_back((0.75f + (cosT[(i+1)]*0.25f)));
    uvs.push_back((0.25f - (sinT[i]*0.25f)));


    vertices.push_back(cosT[i]);
    vertices.push_back(0.0f);
    vertices.push_back(-sinT[i]);

    uvs.push_back((0.75f + (cosT[i]*0.25f)));
    uvs.push_back((0.25f - (sinT[i]*0.25f)));
    

    for(int n = 0; n < 3; n++)
    {
      normals.push_back(0.0f);
      normals.push_back(-1.0f);
      normals.push_back(0.0f);
    }
    
    vertexCount += 3;
  }

  
  model.setModel(vertexCount, vertices, normals, uvs);
  model.setScale(Vec3(r, h, r));

  sinT.clear();
  cosT.clear();
  cleanContainers();

  return model;
}

// -----------------------------------------------------------------------------

Model ModelGenerator::getTorus()
{
  Model model;

  return model;
}

// -----------------------------------------------------------------------------

/*!
* vTL - vertex TopLeft, vBL - vertex BottomLeft, vBR - vertex BottmRight,
* vTR - vertex TopRight, uvL - uvCoord Left, uvR - uvCoord Right,
* uvT - uvCoord Top, uvB - uvCoord Bottom
*/
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

/*!
*
*
*
*
*/
void ModelGenerator::makePlane(int subW, int subH, PlaneType type)
{
  float dW = (1.0f / (float)subW);
  float dH = (1.0f / (float)subH);
  float x1 = 0.0f;
  float x2 = 0.0f;
  float y1 = 0.0f;
  float y2 = 0.0f;
  float z1 = 0.0f;
  float z2 = 0.0f;

  float uvLeft = 0.0f;
  float uvTop = 0.0f;
  float uvRight = 0.0f;
  float uvBottom = 0.0f;


  for(int j = 0; j < subH; j++)
  {
    for(int i = 0; i < subW; i++)
    {
      // TODO: once textured, make sure the Top and bottom are not flipped
      switch(type)
      {
      case PLN_LEFT:
        x1 = -0.5f;
        y1 = PLN_OFFSET + ((j+1) * dH);
        y2 = PLN_OFFSET + (j * dH);
        z1 = PLN_OFFSET + (i * dW);
        z2 = PLN_OFFSET + ((i+1) * dW);

        uvLeft =    (i * dW);
        uvTop =     ((j+1) * dH);
        uvRight =   ((i+1) * dW);
        uvBottom =  (j * dH);

        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y2, z1),                      
                        Vec3(x1, y2, z2),
                        Vec3(x1, y1, z2),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(-1.0f);
          normals.push_back(0.0f);
          normals.push_back(0.0f);
        }
        break;

      case PLN_RIGHT:
        x1 = 0.5f;
        y1 = PLN_OFFSET + ((j+1) * dH);
        y2 = PLN_OFFSET + (j * dH);
        z1 = PLN_OFFSET + ((i+1) * dW);
        z2 = PLN_OFFSET + (i * dW);

        uvLeft =    ((i+1) * dW);
        uvTop =     ((j+1) * dH);
        uvRight =   (i * dW);
        uvBottom =  (j * dH);

        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y2, z1),                      
                        Vec3(x1, y2, z2),
                        Vec3(x1, y1, z2),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(1.0f);
          normals.push_back(0.0f);
          normals.push_back(0.0f);
        }
        break;

      case PLN_FRONT:
        x1 = PLN_OFFSET + (i * dW);
        x2 = PLN_OFFSET + ((i+1) * dW);
        y1 = PLN_OFFSET + ((j+1) * dH);
        y2 = PLN_OFFSET + (j * dH);
        z1 = 0.5f;

        uvLeft =    (i * dW);
        uvTop =     ((j+1) * dH);
        uvRight =   ((i+1) * dW);
        uvBottom =  (j * dH);
        
        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y2, z1),                      
                        Vec3(x2, y2, z1),
                        Vec3(x2, y1, z1),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(0.0f);
          normals.push_back(1.0f);
        }
        break;


      case PLN_CENTER:
        x1 = PLN_OFFSET + (i * dW);
        x2 = PLN_OFFSET + ((i+1) * dW);
        y1 = PLN_OFFSET + ((j+1) * dH);
        y2 = PLN_OFFSET + (j * dH);
        z1 = 0.0f;

        uvLeft =    (i * dW);
        uvTop =     ((j+1) * dH);
        uvRight =   ((i+1) * dW);
        uvBottom =  (j * dH);

        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y2, z1),                      
                        Vec3(x2, y2, z1),
                        Vec3(x2, y1, z1),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(0.0f);
          normals.push_back(1.0f);
        }
        break;


      case PLN_BACK:
        x1 = PLN_OFFSET + ((i+1) * dW);
        x2 = PLN_OFFSET + (i * dW);
        y1 = PLN_OFFSET + ((j+1) * dH);
        y2 = PLN_OFFSET + (j * dH);
        z1 = -0.5f;

        uvLeft =    ((i+1) * dW);
        uvTop =     ((j+1) * dH);
        uvRight =   (i * dW);
        uvBottom =  (j * dH);


        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y2, z1),                      
                        Vec3(x2, y2, z1),
                        Vec3(x2, y1, z1),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );


        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(0.0f);
          normals.push_back(-1.0f);
        }
        break;

      case PLN_SURFACE:
      case PLN_TOP:
        x1 = PLN_OFFSET + (i * dW);
        x2 = PLN_OFFSET + ((i+1) * dW);
        z1 = PLN_OFFSET + (j * dH);
        z2 = PLN_OFFSET + ((j+1) * dH);

        if(type == PLN_SURFACE)
        {
          y1 = 0.0f;
        }
        else
        {
          y1 = 0.5f;
        }
        

        uvLeft =    (i * dW);
        uvTop =     (j * dH);
        uvRight =   ((i+1) * dW);
        uvBottom =  ((j+1) * dH);
        
        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y1, z2),                      
                        Vec3(x2, y1, z2),
                        Vec3(x2, y1, z1),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(1.0f);
          normals.push_back(0.0f);
        }
        break;

      case PLN_BOTTOM:
        x1 = PLN_OFFSET + (i * dW);
        x2 = PLN_OFFSET + ((i+1) * dW);
        z1 = PLN_OFFSET + ((j+1) * dH);
        z2 = PLN_OFFSET + (j * dH);
        y1 = -0.5f;

        uvLeft =    (i * dW);
        uvTop =     ((j+1) * dH);
        uvRight =   ((i+1) * dW);
        uvBottom =  (j * dH);
        
        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y1, z2),                      
                        Vec3(x2, y1, z2),
                        Vec3(x2, y1, z1),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

        for(int n=0; n < 6; n++)
        {
          normals.push_back(0.0f);
          normals.push_back(-1.0f);
          normals.push_back(0.0f);
        }
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