#include "../include/System.h"



System::System()
{
	
}

void System::Initialization()
{
	

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << SDL_GetError();
	}

	window = SDL_CreateWindow("Archer BROS!", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
}

void System::GameLoop()
{
	
	
	while (!input.Quit()) {

		input.Process();

		SDL_SetRenderDrawColor(renderer, 48, 80, 48, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		


	}


}

void System::Close()
{
	//Quit SDL subsystems
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}



System::~System()
{
}
