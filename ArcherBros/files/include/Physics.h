#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL.h>
#include <iostream>
#include "../include/Global.h"

class Physics {
  private:
  Global global;
  public:

  

  bool CheckWindowCollision(const SDL_Rect& rect);

  bool CheckObjectCollision(const SDL_Rect& rectA,
    const SDL_Rect& rectB);

};

#endif // !PHYSICS_H
