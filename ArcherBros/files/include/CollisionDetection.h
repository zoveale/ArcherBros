#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H
#include "../include/GameObject.h"

class CollisionDetection {

  public:
  CollisionDetection();

  void ObjectCollision(Redsquare& a, Bluesquare& b);
  bool CheckCollision(SDL_Rect& a,SDL_Rect& b);
  ~CollisionDetection();
};

#endif // !COLLISIONDETECTION_H