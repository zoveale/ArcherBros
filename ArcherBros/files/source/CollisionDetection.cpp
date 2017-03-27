#include "..\include\CollisionDetection.h"



CollisionDetection::CollisionDetection() {}

void CollisionDetection::ObjectCollision(Redsquare& A,
  Bluesquare& B) {
  
  
  

  std::cout << "Redsquare = " << A.XPos() << "," << A.YPos() << "\t";
  std::cout << "Bluesquare = " << B.XPos() << "," << B.YPos() << "\n";
  /*
  */
  //FIX ME:: MAKE VEOLICTY A FUCTION FROM MOVE.H
  //FIX ME:: Include screen hieght and width globals
  //FIX ME:: enter bool (checkcollison()) for if statements
 
    if ((A.XPos() < 0) || (A.XPos() + A.Width() > 640)) {
      A.SetX(A.XPos() - 5);
    }
    if (A.YPos() < 0) {
      A.SetY(A.YPos() + 5);
    }

    /*

    */
    if (B.XPos() < 0) {
      B.SetX(B.XPos() + 5);
    }
    if (B.YPos() < 0) {
      B.SetY(B.YPos() + 5);
    }

    /*

    */

    if ((A.XPos() + A.Width() > 640)) {
      A.SetX(A.XPos() - 5);
    }
    if (A.YPos() + A.Height() > 480) {
      A.SetY(A.YPos() - 5);
    }

    /*

    */
    if (B.XPos() + B.Width() > 640) {
      B.SetX(B.XPos() - 5);
    }
    if (B.YPos() + B.Height() > 480) {
      B.SetY(B.YPos() - 5);
    }
  
}

bool CollisionDetection::OutsideBounds(int A_X, int A_Y, int B_X, int B_Y) {}

bool CollisionDetection::CheckCollision(SDL_Rect& a, SDL_Rect& b) {

  



  return false;
}



CollisionDetection::~CollisionDetection() {}
