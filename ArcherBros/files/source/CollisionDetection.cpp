#include "..\include\CollisionDetection.h"



CollisionDetection::CollisionDetection() {}

void CollisionDetection::ObjectCollision(Redsquare& A,
  Bluesquare& B) 
{
  if (A.XPos() < 0) {
    std::cout << "Redsquare X < 0 = TRUE\n";
    A.SetX(0);
  }
  if (A.YPos() < 0) {
    std::cout << "Redsquare Y < 0 = TRUE\n";
    A.SetY(0);
  }


  if (B.XPos() < 0) {
    std::cout << "Bluesquare X < 0 = TRUE\n";
    B.SetX(0);
  }
  if (B.YPos() < 0) {
    std::cout << "Bluesquare Y < 0 = TRUE\n";
    B.SetY(0);
  }
}

bool CollisionDetection::CheckCollision() {
  return false;
}



CollisionDetection::~CollisionDetection() {}
