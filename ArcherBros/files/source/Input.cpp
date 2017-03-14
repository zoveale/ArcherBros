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
			KEY_STATE.UP = true;
		}
		else { 
			KEY_STATE.UP = false; 
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_DOWN) {
			KEY_STATE.DOWN = true;
		}
		else {
			KEY_STATE.DOWN = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_LEFT) {
			KEY_STATE.LEFT = true;
		}
		else {
			KEY_STATE.LEFT = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_RIGHT) {
			KEY_STATE.RIGHT = true;
		}
		else {
			KEY_STATE.RIGHT = false;
		}
	}
	
}


Input::~Input()
{
}
