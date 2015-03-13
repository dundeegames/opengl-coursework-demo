#include <assets/animatedsprite.h>




void AnimatedSprite::update(float eTime)
{
  
  // add delta time to animate elapsed time
  animTime += eTime;
  // if enough time has passed change frame
  if(animTime >= frameStepTime)
  {
    // update offsets
    offsetX += frameWidth;
    if(offsetX > width - frameWidth)
    {
      // offset is outside sprite size
      offsetX = 0;
    }
    // reset animation elapsed time
    animTime = 0;
  }
  
}


void AnimatedSprite::move(float eTime)
{
  
  // if elapsed time is greater than speed 
  // move sprite
  elapsedTime += eTime;
  if(elapsedTime > speed)
  {
    // move sprite
    x++;
    elapsedTime = 0;
  }
  
}