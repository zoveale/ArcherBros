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

  //Create GameObjects from Classes made from template
	Redsquare RedSquareOne;
	Bluesquare BlueSquareTwo;

  //FIX ME:: will add fuctions later to SDL create window
  const int screenWidth = 640;
  const int screenHeight = 480;

public:
	System();
  
  

	void Initialization();
	void GameLoop();
	void Close();

	~System();
};

#endif //!SYSTEM_H
