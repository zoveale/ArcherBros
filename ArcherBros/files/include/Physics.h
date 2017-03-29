#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL.h>
#include <iostream>

class Physics {

  private:
  const int SCREEN_HEIGHT = 480;
  const int SCREEN_WIDTH = 640;

  public:

  

  bool CheckWindowCollision(const SDL_Rect& rect);

  bool CheckObjectCollision(const SDL_Rect& rectA,
    const SDL_Rect& rectB);

};

#endif // !PHYSICS_H
