#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SDL.h>
#include "../include/Input.h"

class Movement {
public:

	void Left(SDL_Rect& RECT, const KEY_STATE& KEY ) {
			if (KEY.UP) {
				RECT.y -= 5;
			}
			if (KEY.DOWN) {
				RECT.y += 5;
			}
			if (KEY.LEFT) {
				RECT.x -= 5;
			}
			if (KEY.RIGHT) {
				RECT.x += 5;
			}
			
	}

	void Right(SDL_Rect& RECT, const KEY_STATE& KEY) {
		if (KEY.W) {
			RECT.y -= 5;
		}
		if (KEY.S) {
			RECT.y += 5;
		}
		if (KEY.A) {
			RECT.x -= 5;
		}
		if (KEY.D) {
			RECT.x += 5;
		}

		
	}

};
#endif // !MOVEMENT_H
