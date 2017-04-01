#include "../include/System.h"



System::System() {

}

void System::Initialization() {

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }

  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("Archer BROS!",
    SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
    global.SCREEN_HEIGHT, global.SCREEN_WIDTH,
    SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // load support for the JPG and PNG image formats
  int flags = IMG_INIT_PNG;
  int initted = IMG_Init(flags);
  if ((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
  }


  //Init GameObjects

  RedSquareOne.SetRenderer(renderer);
  RedSquareOne.InitDirectionalTextures("resource/red_square_idel.png",
    "resource/red_square_up.png", "resource/red_square_down.png",
    "resource/red_square_left.png", "resource/red_square_right.png");
  RedSquareOne.Initialization(480, 240, 50, 50);

  BlueSquareTwo.SetRenderer(renderer);
  BlueSquareTwo.InitDirectionalTextures("resource/blue_square_idel.png",
    "resource/blue_square_up.png", "resource/blue_square_down.png",
    "resource/blue_square_left.png", "resource/blue_square_right.png");
  BlueSquareTwo.Initialization(160, 240, 50, 50);

  
}

void System::GameLoop() {
  
  while (!input.Quit()) {
    

    //Input 
    input.Process();
    RedSquareOne.SetInput(input.GetInput());
    BlueSquareTwo.SetInput(input.GetInput());


    //Update Objects Positions
    RedSquareOne.Position();
    BlueSquareTwo.Position();
   
	//Checks Object Collision
    if (physics.CheckObjectCollision(RedSquareOne.Rect(),
      BlueSquareTwo.Rect())) {
      RedSquareOne.ObjectCollision(true);
      BlueSquareTwo.ObjectCollision(true);
    }

    //Update Objects Collision
    RedSquareOne.Collision();
    BlueSquareTwo.Collision();

    
    //Update Objects  Textures
    RedSquareOne.Update();
    BlueSquareTwo.Update();
    

    //Background Color (rgb, alpha)
    SDL_SetRenderDrawColor(renderer, 48, 80, 48, 255);

    //Clear Screen
    SDL_RenderClear(renderer);

    //Background Image
    //LevelMap.Update();
   

    //Draw Objects
    RedSquareOne.Draw();
    BlueSquareTwo.Draw();

    //Update Screen
    SDL_RenderPresent(renderer);

    RedSquareOne.ObjectCollision(false);
    BlueSquareTwo.ObjectCollision(false);
  }
}

void System::Close() {
  RedSquareOne.Close();
  BlueSquareTwo.Close();

  //Quit SDL subsystems
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}



System::~System() {}
