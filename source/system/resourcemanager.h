////////////////////////////////////////////////////////////////////////////////
/**
* \file       resourcemanager.h
* \brief      ResourceManager class - AG0800A Graphics Programming
*
* \details    Handles the file loading, casching, directory paths and distribution
*             of assets (i.e. textures, meshes, etc) to other objects
*
* \author     Jiri Klic
* \version    1.0
* \date       February 2015
* \pre        
* \post       
* \bug        No known bugs
* \warning    
* \todo       
*             
* \copyright  University of Abertay - Dundee.2013.
*             Intellectual Property Policy.[online].Available from: 
*             http://www.abertay.ac.uk/media/Intellectual-Property-Policy-v2-01.pdf
*             [Accessed 22 April 2015].
*
*///////////////////////////////////////////////////////////////////////////////



#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H


// INCLUDES ////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <fstream>
#include <Gl/gl.h>
#include <gl/glu.h>
#include <soil/SOIL.h>
#include <map>
#include <string>
#include <vector>

#include <ui/font.h>
#include <system/TokenStream.h>
#include <math/vec3.h>
#include <assets/model.h>





// CLASS ///////////////////////////////////////////////////////////////////////

class ResourceManager
{

public:
  ResourceManager();
  ~ResourceManager();

  void init();

  GLuint getTexture(const char* file, bool stdandard_path = true);
  Font* getFont(const char* file, bool stdandard_path = true);
  Model* getModel(const char* file, bool stdandard_path = true);


private:


  std::string fonts_path;
  std::string images_path;
  std::string models_path;

  std::map<const char*, GLuint> texture_list;
  bool loadTexture(const char* file, bool stdandard_path);

  std::map<const char*, Font*> font_list;
  void loadFont(const char* file, bool stdandard_path);

  std::map<const char*, Model*> model_list;
  Model* loadModel(const char* file, bool stdandard_path);

};


#endif // RESOURCE_MANAGER_H




// 80 //////////////////////////////////////////////////////////////////////////