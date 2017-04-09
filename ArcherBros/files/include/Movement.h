#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SDL.h>
#include <iostream>
#include "../include/Input.h"

class Movement {
public:

	void PlayerOne(SDL_Point& velocity, const KEY_STATE& KEY,
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

	void PlayerTwo(SDL_Point& velocity, const KEY_STATE& KEY,
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

  void Projectile(SDL_Point& velocity, const KEY_STATE& KEY,
    ObjectDirection& current) {
    //velocity.x = 5;
    //velocity.y = 5;
    current = ObjectDirection::UP;

    if (velocity.x == 5 && 
      velocity.y == 5) {
      std::cout << "Moving down right\t" 
        << velocity.x << " " << velocity.y << "\n";
    }
    else if (velocity.x == 5 &&
      (velocity.y)== -5) {
      std::cout << "moving up right\t" 
        << velocity.x << " "<< velocity.y << "\n";
    }
    else if ((-velocity.x) == velocity.y){
      std::cout << "moving down left\t" 
        << velocity.x << " " << velocity.y << "\n";
    }
    else if ((velocity.x == -5) &&
      (velocity.y == -5)){
      std::cout << "moving up left\t" 
        << velocity.x << " " << velocity.y << "\n";
    }
  }
};
#endif // !MOVEMENT_H
