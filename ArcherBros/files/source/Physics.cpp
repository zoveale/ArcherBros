#include "..\include\Physics.h"



bool Physics::CheckWindowCollision(const SDL_Rect & rect)
{
	if (rect.x < 0 || ((rect.x + rect.w) > SCREEN_HEIGHT)
     || rect.y < 0 || ((rect.y + rect.h) > SCREEN_HEIGHT)) {
		return true;
	}
  
	return false;
}
