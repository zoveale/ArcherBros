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
	}
	
}


Input::~Input()
{
}
