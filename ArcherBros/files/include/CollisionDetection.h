#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H
#include "../include/GameObject.h"

class CollisionDetection {

  public:
  CollisionDetection();

  void ObjectCollision(Redsquare& a, Bluesquare& b);
  bool CheckCollision();
  ~CollisionDetection();
};

#endif // !COLLISIONDETECTION_H