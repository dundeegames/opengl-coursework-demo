#ifndef _ANIMATED_SPRITE_H
#define _ANIMATED_SPRITE_H

#include <assets/oldsprite.h>
#include <system/timerclass.h>


class AnimatedSprite : public OldSprite
{

public:
  void update(float eTime);
  void move(float eTime);

private:
  float animTime;
  float frameStepTime;
  float elapsedTime;
  float speed;

  int offsetX;
  int frameWidth;

};



#endif