#include "..\include\CollisionDetection.h"



CollisionDetection::CollisionDetection() {}

void CollisionDetection::ObjectCollision(Redsquare& A,
  Bluesquare& B) 
{ 
  int Velocity = 5;



  std::cout << "Redsquare = " << A.XPos() << "," << A.YPos() << "\t";
  std::cout << "Bluesquare = " << B.XPos() << "," << B.YPos() << "\n";
  /*
  */
  //FIX ME:: MAKE VEOLICTY A FUCTION FROM MOVE.H
  //FIX ME:: enter bool (checkcollison()) for if statements
  if ((A.XPos() < 0)) {
    std::cout << "Redsquare X < 0 = TRUE\n";
    A.SetX(A.XPos() + 5);
  }
  if (A.YPos() < 0) {
    std::cout << "Redsquare Y < 0 = TRUE\n";
    A.SetY(A.YPos() + 5);
  }

  /*
  
  */
  if (B.XPos() < 0) {
    std::cout << "Bluesquare X < 0 = TRUE\n";
    B.SetX(B.XPos() + 5 );
  }
  if (B.YPos() < 0) {
    std::cout << "Bluesquare Y < 0 = TRUE\n";
    B.SetY(B.YPos() + 5);
  }

  /*
  
  */

  if (A.XPos() + A.GetBoundsWidth() > 640) {
    A.SetX(A.XPos() - 5);
  }
  if (A.YPos()+ A.GetBoundsHeight() > 480) {
    A.SetY(A.YPos() - 5);
  }

  /*
  
  */
  if (B.XPos() + B.GetBoundsWidth() > 640) {
    B.SetX(B.XPos() - 5);
  }
  if (B.YPos() + B.GetBoundsHeight() > 480) {
    B.SetY(B.YPos() - 5);
  }
}

bool CollisionDetection::CheckCollision() {
  return false;
}



CollisionDetection::~CollisionDetection() {}
