#include "..\include\Input.h"



Input::Input()
{
	quit = false;
}

bool Input::Quit()
{
	return quit;
}

void Input::Process()
{
	
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit = true;
		}
		if (event.type == SDL_KEYDOWN && 
			event.key.keysym.sym == SDLK_UP) {
			KEY.UP = true;
		}
		else { 
			KEY.UP = false; 
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_DOWN) {
			KEY.DOWN = true;
		}
		else {
			KEY.DOWN = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_LEFT) {
			KEY.LEFT = true;
		}
		else {
			KEY.LEFT = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_RIGHT) {
			KEY.RIGHT = true;
		}
		else {
			KEY.RIGHT = false;
		}
	}
	
}

KEY_STATE Input::GetInput()
{
	return KEY;
}


Input::~Input()
{
	
}
