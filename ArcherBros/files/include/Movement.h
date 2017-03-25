#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SDL.h>
#include "../include/Input.h"

class Movement {
  private:
  int velocity;
  public:
  Movement(){ velocity = 5; }

  int GetVelo() { return velocity; }

  void Left(SDL_Rect& RECT, const KEY_STATE& KEY) {
    if (KEY.UP) {
      RECT.y -= velocity;

    }
    if (KEY.DOWN) {
      RECT.y += velocity;
    }
    if (KEY.LEFT) {
      RECT.x -= velocity;
    }
    if (KEY.RIGHT) {
      RECT.x += velocity;
    }

  }

  void Right(SDL_Rect& RECT, const KEY_STATE& KEY) {
    if (KEY.W) {
      RECT.y -= velocity;
    }
    if (KEY.S) {
      RECT.y += velocity;
    }
    if (KEY.A) {
      RECT.x -= velocity;
    }
    if (KEY.D) {
      RECT.x += velocity;
    }


  }

};
#endif // !MOVEMENT_H
