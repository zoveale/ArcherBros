#include "..\include\Physics.h"

bool Physics::CheckWindowCollision(const SDL_Rect & rect)
{
	if (rect.x < 0 || ((rect.x + rect.w) > 640) || 
		rect.y < 0 || ((rect.y + rect.h) > 480)) {
		return true;
	}
	return false;
}
