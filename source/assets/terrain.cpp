#include <assets/terrain.h>
#include <system/macros.h>


Terrain::Terrain()
{
  scale = Vec3(1.0f, 1.0f, 1.0f);
  texture = NULL;
  terrainDlist = NULL;
  vertexCount = 0;
  tileW = 1.0f;
  tileH = 1.0f;
}


Terrain::~Terrain()
{
  cleanContainers();
}


// -----------------------------------------------------------------------------

void Terrain::init(const char* htMap, ModelGenerator* mdGen, bool waterActive)
{
  if(vertexCount == 0)
  {
    loadTerrain(htMap);
  }
  else
  {
    cleanContainers();
    loadTerrain(htMap);
  }

  water = mdGen->getPlane(scale.getX(), scale.getZ(), 10, 10, PLN_SURFACE);
  water.setColour(COLOUR_WHITE, 0.7f);
  
  renderWater = waterActive;

}

// -----------------------------------------------------------------------------

void Terrain::loadTerrain(const char* file)
{
  int width, height, channels;

  // load an image as a heightmap, forcing greyscale (so channels should be 1)
  unsigned char* heightMap = SOIL_load_image(file, &width, &height,
                                             &channels,
                                             SOIL_LOAD_L
                                            );


  float dW = (1.0f / (float)width);
  float dH = (1.0f / (float)height);

  float x1 = 0.0f;
  float x2 = 0.0f;

  float y1 = 0.0f;
  float y2 = 0.0f;
  float y3 = 0.0f;
  float y4 = 0.0f;

  float z1 = 0.0f;
  float z2 = 0.0f;

  float uvLeft = 0.0f;
  float uvTop = 0.0f;
  float uvRight = 0.0f;
  float uvBottom = 0.0f;


  for(int j = 0; j < (height-1); j++)
  {
    for(int i = 0; i < (width-1); i++)
    {
      // TODO: once textured, make sure the Top and bottom are not flipped
        x1 = PLN_OFFSET + (i * dW);
        x2 = PLN_OFFSET + ((i+1) * dW);
        z1 = PLN_OFFSET + (j * dH);
        z2 = PLN_OFFSET + ((j+1) * dH);

        // 255.0f = max unsigned char value casted as float
        y1 = PLN_OFFSET + ((float)heightMap[(j*width) + i] / 255.0f);
        y2 = PLN_OFFSET + ((float)heightMap[((j+1)*width) + i] / 255.0f);
        y3 = PLN_OFFSET + ((float)heightMap[((j+1)*width) + (i+1)] / 255.0f);
        y4 = PLN_OFFSET + ((float)heightMap[(j*width) + (i+1)] / 255.0f);


        uvLeft =    (i * dW);
        uvTop =     (j * dH);
        uvRight =   ((i+1) * dW);
        uvBottom =  ((j+1) * dH);
        
        quadToTriangle(
                        Vec3(x1, y1, z1),
                        Vec3(x1, y2, z2),                      
                        Vec3(x2, y3, z2),
                        Vec3(x2, y4, z1),
                        uvLeft,
                        uvTop,
                        uvRight,
                        uvBottom
                      );

    }
  }


  //compileTerrain();

  delete[] heightMap;
  //cleanContainers();
}

// -----------------------------------------------------------------------------

void Terrain::update(float dt)
{
  water.moveUVoffset(0.0f, dt);


}

// -----------------------------------------------------------------------------

/*!
* vTL - vertex TopLeft, vBL - vertex BottomLeft, vBR - vertex BottmRight,
* vTR - vertex TopRight, uvL - uvCoord Left, uvR - uvCoord Right,
* uvT - uvCoord Top, uvB - uvCoord Bottom
*/
void Terrain::quadToTriangle(Vec3 vTL, Vec3 vBL, Vec3 vBR, Vec3 vTR,
                             float uvL, float uvT, float uvR, float uvB)
{
  Vec3 tempNormal;


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


  //tempNormal = getNormal(vTL, vBL, vBR);
  //for(int n=0; n < 3; n++)
  //{
  //  normals.push_back(tempNormal.getX());
  //  normals.push_back(tempNormal.getY());
  //  normals.push_back(tempNormal.getZ());
  //}
  
  
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


  //tempNormal = getNormal(vBR, vTR, vTL);
  //for(int n=0; n < 3; n++)
  //{
  //  normals.push_back(tempNormal.getX());
  //  normals.push_back(tempNormal.getY());
  //  normals.push_back(tempNormal.getZ());
  //}

  for(int n=0; n < 6; n++)
  {
    normals.push_back(0.0f);
    normals.push_back(1.0f);
    normals.push_back(0.0f);
  }


  vertexCount += 6;

}

// -----------------------------------------------------------------------------

Vec3 Terrain::getNormal(Vec3 v1, Vec3 v2, Vec3 v3)
{
  Vec3 normal = (v3 - v2).cross(v1 - v2);
  normal = normal.normalize();

  return normal;
}

// -----------------------------------------------------------------------------

void Terrain::cleanContainers()
{
  vertexCount = 0;
  vertices.clear();
  normals.clear();
  uvs.clear();
}

// -----------------------------------------------------------------------------

void Terrain::compileTerrain()
{
  terrainDlist = glGenLists(1);   // create display lists

  glNewList(terrainDlist, GL_COMPILE);

    glBegin(GL_TRIANGLES);


    glEnd();

  glEndList();

}

// -----------------------------------------------------------------------------

void Terrain::render()
{
  //Rotate();
  //glCallList(terrainDlist);  

  // enble and specify pointers to vertex arrays
  glBindTexture(GL_TEXTURE_2D, texture);  //tells opengl which texture to use
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glScalef(tileW, tileH, 0.0f);


	glMatrixMode(GL_MODELVIEW);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);



  glVertexPointer (3, GL_FLOAT, 0, vertices.data());
  glNormalPointer (GL_FLOAT, 0, normals.data());
  glTexCoordPointer(2, GL_FLOAT, 0, uvs.data());
  
  glColor3f(COLOUR_WHITE);

  glPushMatrix();
    glScalef(scale.getX(), scale.getY(), scale.getZ());
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
  glPopMatrix();


  glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);

  glMatrixMode(GL_TEXTURE);
    glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


  glBindTexture(GL_TEXTURE_2D, NULL);   //set texture to NULL
  

  if(renderWater)
  {
      water.Render();
  }
  
}

// -----------------------------------------------------------------------------

void Terrain::setScale(Vec3 s)
{
  scale = s;
  water.setScale(s);
}

// -----------------------------------------------------------------------------

void Terrain::setTiling(float w, float h)
{
  tileW = w;
  tileH = h;
}

// -----------------------------------------------------------------------------






// 80 //////////////////////////////////////////////////////////////////////////