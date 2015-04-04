#include "resourcemanager.h"


ResourceManager::ResourceManager()
{
  init();
}


ResourceManager::~ResourceManager()
{

}

// -----------------------------------------------------------------------------

void ResourceManager::init()
{
  fonts_path = "../../media/fonts/";
  images_path = "../../media/images/";
  models_path = "../../media/models/";
}

// -----------------------------------------------------------------------------

GLuint ResourceManager::getTexture(const char* file, bool stdandard_path)
{
  if(texture_list.find(file) == texture_list.end())
  {
    if(loadTexture(file, stdandard_path) )
    {
      return texture_list[file];
    }
    else
    {
      // report an error
      std::string message = ("SOIL loading error: '%s'\n", SOIL_last_result() );
      MessageBox(NULL, (LPCSTR)message.c_str(), "Load Error", MB_OK);
      return NULL;
    }
  }
  else
  {
    return texture_list[file];
  }
}

// -----------------------------------------------------------------------------

bool ResourceManager::loadTexture(const char* file, bool stdandard_path)
{
  std::string path;

  if(stdandard_path)
  {
    path = images_path;
    path += file;
  }
  else
  {
    path = file;
  }

  //! Load a PNG using the SOIL (Simple OpenGL Image  Library)
  GLuint texture = SOIL_load_OGL_texture(path.c_str(),
               SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
               SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
               );

  //! check for an error during the load process
  if(texture == 0)
  {
    return false;
  }

  texture_list[file] = texture;
  return true;

}

// -----------------------------------------------------------------------------

Font* ResourceManager::getFont(const char* file, bool stdandard_path)
{
  if(font_list.find(file) == font_list.end())
  {
    loadFont(file, stdandard_path);
  }

  return font_list[file];

}

// -----------------------------------------------------------------------------

void ResourceManager::loadFont(const char* file, bool stdandard_path)
{
  std::string path;

  if(stdandard_path)
  {
    path = fonts_path;
    path += file;
  }
  else
  {
    path = file;
  }


  Font* font = new Font();
  font->Load(path.c_str() );

  font_list[file] = font;

}

// -----------------------------------------------------------------------------

Model* ResourceManager::getModel(const char* file, bool stdandard_path)
{
  if(stdandard_path)
  {
    Model* tempModel = new Model();

    if(model_list.find(file) == model_list.end())
    {
      tempModel = loadModel(file, stdandard_path);
      if(tempModel != NULL)
      {
        model_list[file] = tempModel;
        return tempModel;
      }
      else
      {
        return NULL;
      }
    }
    else
    {
      *tempModel = *model_list[file];
      return tempModel;
    }
  }
  else
  {
    return loadModel(file, stdandard_path);
  }

}

// -----------------------------------------------------------------------------

Model* ResourceManager::loadModel(const char* file, bool stdandard_path)
{
  std::string path;

  if(stdandard_path)
  {
    path = models_path;
    path += file;
  }
  else
  {
    path = file;
  }

  
  std::ifstream fileStream;
  int fileSize = 0;

  fileStream.open( path.c_str(), std::ifstream::in );
   
  if( fileStream.is_open() == false )
  {
    return NULL;
  }

  fileStream.seekg( 0, std::ios::end );
  fileSize = ( int )fileStream.tellg( );
  fileStream.seekg( 0, std::ios::beg );

  if( fileSize <= 0 )
  {
    return NULL;
  }

  char *buffer = new char[fileSize];

  if( buffer == 0 )
  {
    return NULL;
  }

  memset( buffer, '\0', fileSize );

  TokenStream tokenStream, lineStream, faceStream;
  std::string tempLine, token;

  fileStream.read( buffer, fileSize );
  tokenStream.SetTokenStream( buffer );

  delete[] buffer;

  tokenStream.ResetStream( );

  float tempx, tempy, tempz;
  std::vector<Vec3> verts, norms, texC;
  std::vector<int> faces;
  

  char lineDelimiters[2] = { '\n', ' ' };

  while( tokenStream.MoveToNextLine( &tempLine ) )
  {
    lineStream.SetTokenStream( ( char* )tempLine.c_str( ) );
    tokenStream.GetNextToken( 0, 0, 0 );

    if( !lineStream.GetNextToken( &token, lineDelimiters, 2 ) )
    {
      continue;
    }

    if( strcmp( token.c_str( ), "v" ) == 0 )
    {
      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempx = (float)atof(token.c_str());

      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempy = (float)atof(token.c_str());

      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempz = (float)atof(token.c_str());

      verts.push_back(Vec3(tempx, tempy, tempz));
    }
    else if( strcmp( token.c_str( ), "vn" ) == 0 )
    {
      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempx = (float)atof(token.c_str());

      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempy = (float)atof(token.c_str());

      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempz = (float)atof(token.c_str());

      norms.push_back(Vec3(tempx, tempy, tempz));
    }
    else if( strcmp( token.c_str( ), "vt" ) == 0 )
    {
      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempx = (float)atof(token.c_str());

      lineStream.GetNextToken( &token, lineDelimiters, 2 );
      tempy = (float)atof(token.c_str());

      texC.push_back(Vec3(tempx, tempy, 0));
    }
    else if( strcmp( token.c_str( ), "f" ) == 0 )
    {
      char faceTokens[3] = { '\n', ' ', '/' };
      std::string faceIndex;

      faceStream.SetTokenStream( ( char* )tempLine.c_str( ) );
      faceStream.GetNextToken( 0, 0, 0 );

      for( int i = 0; i < 3; i++ )
      {
          faceStream.GetNextToken( &faceIndex, faceTokens, 3 );
          faces.push_back( ( int )atoi( faceIndex.c_str( ) ) );

          faceStream.GetNextToken( &faceIndex, faceTokens, 3 );
          faces.push_back( ( int )atoi( faceIndex.c_str( ) ) );

          faceStream.GetNextToken( &faceIndex, faceTokens, 3 );
          faces.push_back( ( int )atoi( faceIndex.c_str( ) ) );
      }
    }
    else if( strcmp( token.c_str( ), "#" ) == 0 )
    {
        //skip
    }

      token[0] = '\0';
  }

  //! "Unroll" the loaded obj information into a list of triangles.
  
  int numFaces = (int)faces.size() / 9;
  int vertexCount = numFaces * 3;
  std::vector<float> vertices, normals, uvs;

  /*!
  * sort the model data
  * Model data is stored in stored in vectors verts, norms, texC and faces
  * Sort through the data and store it in the vectors provided (see header file)
  */
  for( int i = 0; i < (int)faces.size(); i+=3 )
  {
    vertices.push_back( verts[( faces[i + 0] - 1 )].getX() );
    vertices.push_back( verts[( faces[i + 0] - 1 )].getY() );
    vertices.push_back( verts[( faces[i + 0] - 1 )].getZ() );


    //if(texCoords_)
    uvs.push_back( texC[( faces[i + 1] - 1 )].getX() );
    uvs.push_back( texC[( faces[i + 1] - 1 )].getY() );


    //if(normals_)
    normals.push_back( norms[( faces[i + 2] - 1 )].getX() );
    normals.push_back( norms[( faces[i + 2] - 1 )].getY() );
    normals.push_back( norms[( faces[i + 2] - 1 )].getZ() );

  }
  
  
  
  // Your code must end here, prior to the loaded data being deleted
  verts.clear();
  norms.clear();
  texC.clear();
  faces.clear();


  Model* model = new Model();
  //model->setModel(vertexCount, GL_TRIANGLES, vertices, normals, uvs);
  model->setModel(vertexCount, vertices, normals, uvs);
  //model_list[file] = model;


  return model;

}

// -----------------------------------------------------------------------------











// 80 //////////////////////////////////////////////////////////////////////////