#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "../include/Input.h"
#include "../include/GameObject.h"


class System
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Input input;
	GameObject RedSquareOne;

public:
	System();

	void Initialization();
	void GameLoop();
	void Close();

	~System();
};

#endif //!SYSTEM_H
