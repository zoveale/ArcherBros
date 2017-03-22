#include "..\include\Input.h"
#include <iostream>


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

		//

		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_UP) {
			KEY.UP = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_UP) {
			KEY.UP = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_DOWN) {
			KEY.DOWN = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_DOWN) {
			KEY.DOWN = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_LEFT) {
			KEY.LEFT = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_LEFT) {
			KEY.LEFT = false;
		}

		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_RIGHT) {
			KEY.RIGHT = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_RIGHT) {
			KEY.RIGHT = false;
		}

		//

		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_w) {
			KEY.W = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_w) {
			KEY.W = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_s) {
			KEY.S = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_s) {
			KEY.S = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_a) {
			KEY.A = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_a) {
			KEY.A = false;
		}
		if (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_d) {
			KEY.D = true;
		}
		if (event.type == SDL_KEYUP &&
			event.key.keysym.sym == SDLK_d) {
			KEY.D = false;

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
