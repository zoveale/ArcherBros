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



	// load support for the JPG and PNG image formats
	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted&flags) != flags) {
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
		// handle error
	}

	RedSquareOne.SetRenderer(renderer);
	RedSquareOne.Initialization("resource/red_square.png", 320, 240, 100, 100);

}

void System::GameLoop()
{
	
	
	while (!input.Quit()) {

		input.Process();
		RedSquareOne.SetInput(input.GetInput());

		RedSquareOne.Update();


		SDL_SetRenderDrawColor(renderer, 48, 80, 48, 255);
		SDL_RenderClear(renderer);
		RedSquareOne.Draw();
		SDL_RenderPresent(renderer);
		


	}


}

void System::Close()
{
	RedSquareOne.Close();
	//Quit SDL subsystems
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}



System::~System()
{
}
