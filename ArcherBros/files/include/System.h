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
	Physics physics;

  
  LevelSet LevelOne;
  //Create GameObjects from Classes made from template
  Redsquare RedSquareOne;
  Trees Tree[3];

  //FIX ME:: will add fuctions later to SDL create window
  Global global;

public:
	System();

  

	void Initialization();
	void GameLoop();
	void Close();
	~System();


  //Old Fuctions
  void PlayerCollision();
  void HorzCollision();
  void ResetCollision();
  void DrawLines(SDL_Rect& a, SDL_Rect& b);
};

#endif //!SYSTEM_H
