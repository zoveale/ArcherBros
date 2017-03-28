#ifndef PHYSICS_H
#define PHYSICS_H
#include <SDL.h>

class Physics {

  private:
  const int SCREEN_HEIGHT = 640;
  const int SCREEN_WIDTH = 480;

  public:

  

  bool CheckWindowCollision(const SDL_Rect& rect);

};

#endif // !PHYSICS_H
