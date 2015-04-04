// /////////////////////////////////////////////////////////////////////////////
/*!                                                                           \n
*             ResourceManager class - WinAPI and OpenGL laboratory            \n
*                             by Jiri Klic, Feb 2015                          \n
*                                                                             \n
*/ /////////////////////////////////////////////////////////////////////////////



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