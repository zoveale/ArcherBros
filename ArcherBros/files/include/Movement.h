#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SDL.h>
#include "../include/Input.h"

class Movement {
public:

	void Left(SDL_Point& velocity, const KEY_STATE& KEY,
		ObjectDirection& current) {

		velocity.x = 0;
		velocity.y = 0;

		if (KEY.UP) {
			velocity.y = -10;
			current = ObjectDirection::UP;
		}
		if (KEY.DOWN) {
			velocity.y = 10;
			current = ObjectDirection::DOWN;
		}
		if (KEY.LEFT) {
			velocity.x = -10;
			current = ObjectDirection::LEFT;
		}
		if (KEY.RIGHT) {
			velocity.x = 10;
			current = ObjectDirection::RIGHT;
		}
		if ((velocity.x == 0) && (velocity.y == 0)) {
			current = ObjectDirection::IDEL;
		}

	}

	void Right(SDL_Point& velocity, const KEY_STATE& KEY,
		ObjectDirection& current) {

		velocity.x = 0;
		velocity.y = 0;

		if (KEY.W) {
			velocity.y = -10;
			current = ObjectDirection::UP;
		}
		if (KEY.S) {
			velocity.y = 10;
			current = ObjectDirection::DOWN;
		}
		if (KEY.A) {
			velocity.x = -10;
			current = ObjectDirection::LEFT;
		}
		if (KEY.D) {
			velocity.x = 10;
			current = ObjectDirection::RIGHT;
		}
		if ((velocity.x == 0) && (velocity.y == 0)) {
			current = ObjectDirection::IDEL;
		}

	}

};
#endif // !MOVEMENT_H
