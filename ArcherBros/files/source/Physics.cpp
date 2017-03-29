#include "..\include\Physics.h"



bool Physics::CheckWindowCollision(const SDL_Rect & rect)
{
	if (rect.x < 0 || ((rect.x + rect.w) > SCREEN_WIDTH)
     || rect.y < 0 || ((rect.y + rect.h) > SCREEN_HEIGHT)) {
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
