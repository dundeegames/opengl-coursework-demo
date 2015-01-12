#ifndef PLANETS_H
#define PLANETS_H

// Planets class
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>



class Planets
{
  float rotation, rotation2, rotation3, speed;

public:
  void init();
  void update(float dt);
  void render();

private:


};


#endif
