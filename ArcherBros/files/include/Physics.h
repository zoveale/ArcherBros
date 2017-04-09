#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL.h>
#include <iostream>
#include "../include/Global.h"
#include "Claculate.h"

class Physics {
  private:
  Global global;
  Calculate calc;
  public:

  bool CheckWindowCollision(const SDL_Rect& rect);
  bool CheckWidthCollision(const SDL_Rect& rect);
  bool CheckHeightCollision(const SDL_Rect& rect);
  bool CheckObjectCollision(const SDL_Rect& rectA,
    const SDL_Rect& rectB);

  bool xCollision(const SDL_Rect& a, const SDL_Rect& b);


  bool HorzCollision(const SDL_Rect& rectA,
    const SDL_Rect& rectB);
  bool VertCollision(const SDL_Rect& rectA,
    const SDL_Rect& rectB);
};

#endif // !PHYSICS_H
