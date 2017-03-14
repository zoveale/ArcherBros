#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <SDL.h>
#include "../include/Input.h"

class System
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Input input;

public:
	System();

	void Initialization();
	void GameLoop();
	void Close();

	~System();
};

#endif //!SYSTEM_H
