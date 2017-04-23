#include "..\include\Physics.h"



bool Physics::CheckWindowCollision(const SDL_Rect & rect) {
  if (rect.x < 0 || ((rect.x + rect.w) > global.LEVELWIDTH())
    || rect.y < 0 || ((rect.y + rect.h) > global.LEVELHEIGHT())) {
    return true;
  }

  return false;
}

bool Physics::CheckWidthCollision(const SDL_Rect & rect) {
  if (rect.x < 0 || ((rect.x + rect.w) > global.LEVELWIDTH())) {
    return true;
  }

  return false;
}
bool Physics::CheckHeightCollision(const SDL_Rect & rect) {
  if (rect.y < 0 || ((rect.y + rect.h) > global.LEVELHEIGHT())) {
    return true;
  }

  return false;
}

bool Physics::CheckObjectCollision(const SDL_Rect& a,
  const SDL_Rect& b) {

  //The sides of the rectangles
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  //Calculate the sides of rect A
  leftA = a.x;
  rightA = a.x + a.w;
  topA = a.y;
  bottomA = a.y + a.h;

  //Calculate the sides of rect B
  leftB = b.x;
  rightB = b.x + b.w;
  topB = b.y;
  bottomB = b.y + b.h;

  //Axis Testing
  if (bottomA <= topB) {
    return false;
  }

  if (topA >= bottomB) {
    return false;
  }

  if (rightA <= leftB) {
    return false;
  }

  if (leftA >= rightB) {
    return false;
  }

  //If none of the sides from A are outside B
  return true;
}

//bool xCollision(const SDL_Rect& a, const SDL_Rect& b);

//bool Physics::xCollision(const SDL_Rect & a,
//  const SDL_Rect & b) {
//
//  if (CheckObjectCollision(a, b)) {
//    int i = 0, j = 0;
//        //(ax, ayh)-> (bxw, byh)
//    i = calc.Distance(a.x, a.y + a.h,
//        b.x + b.w, b.y + b.h)
//        + //add both fuctions
//        //(ax,ay)->(bxw,by)
//        calc.Distance(a.x, a.y, b.x + b.w, b.y);
//
//        //(axw, ay)->(bx, by)
//    j = calc.Distance(a.x + a.w, a.y, b.x, b.y)
//        + //add both fuctions
//        //(axw,ayh)->(bx,byh)
//        calc.Distance(a.x + a.w, a.y + a.h,
//        b.x, b.y + b.h);
//    std::cout << i << " " << j << "\n";
//
//    if (i < j) {
//      std::cout << "left side hit\n";
//    }
//    if (i > j) {
//      std::cout << "right side hit\n";
//    }
//  }
//  return false;
//}

bool Physics::HorzCollision(const SDL_Rect & rectA, const SDL_Rect & rectB) {
 
  
  if ((rectA.x >= (rectB.x + rectB.w)) 
    || ((rectA.x + rectA.w) >= rectB.x)) {
    std::cout << " 1\n";
    return true;
 }
 
  
 // return false;
}

bool Physics::VertCollision(const SDL_Rect & rectA, const SDL_Rect & rectB) {
  return false;
}
