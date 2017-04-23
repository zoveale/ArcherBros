#include "../include/System.h"



System::System() {}

void System::Initialization() {

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }

  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("Archer BROS!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    global.SCREENWIDTH(), global.SCREENHEIGHT(),
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

  PurpleBall.SetRenderer(renderer);
  PurpleBall.InitDirectionalTextures("resource/purple_ball_idle.png",
    "resource/purple_ball_idle.png", "resource/purple_ball_idle.png",
    "resource/purple_ball_idle.png", "resource/purple_ball_idle.png");
  PurpleBall.Initialization(320, 240, 40, 40);
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
    PurpleBall.Position();

    //Checks Object Collision
    PlayerCollision();
    HorzCollision();

    //check Objects Collision and update velocity

    RedSquareOne.Collision();
    BlueSquareTwo.Collision();
    PurpleBall.Collision();
    
    

    //Update Objects  Textures
    RedSquareOne.Update();
    BlueSquareTwo.Update();
    PurpleBall.Update();

    //Background Color (rgb, alpha)

    SDL_SetRenderDrawColor(renderer, 48, 80, 48, 255);

    //Clear Screen
    SDL_RenderClear(renderer);

    //Draw Objects
    RedSquareOne.Draw();
    BlueSquareTwo.Draw();
    PurpleBall.Draw();

    //Update Screen
    SDL_RenderPresent(renderer);

    //
    ResetCollision();
  }
}

void System::Close() {
  //Destroy Textures
  RedSquareOne.Close();
  BlueSquareTwo.Close();
  PurpleBall.Close();

  //Quit SDL subsystems
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

System::~System() {}

void System::PlayerCollision() {
  if (physics.CheckObjectCollision(
    RedSquareOne.FutureRect(),
    BlueSquareTwo.FutureRect())) {
    RedSquareOne.ObjectCollision(true);
    BlueSquareTwo.ObjectCollision(true);
  }
}

void System::HorzCollision() {

  if (physics.HorzCollision(BlueSquareTwo.Rect(),
    PurpleBall.Rect())) {
    PurpleBall.HorzCollision(true);
  }

}

void System::ResetCollision() {
  RedSquareOne.ResetCollision();
  BlueSquareTwo.ResetCollision();
  PurpleBall.ResetCollision();
}

void System::DrawLines(SDL_Rect& a, SDL_Rect& b) {
  SDL_RenderDrawLine(renderer, a.x, a.y + a.h, b.x + b.w, b.y + b.h);
  SDL_RenderDrawLine(renderer, a.x, a.y, b.x + b.w, b.y);
  SDL_RenderDrawLine(renderer, a.x + a.w, a.y, b.x, b.y);
  SDL_RenderDrawLine(renderer, a.x + a.w, a.y + a.h, b.x, b.y + b.h);
}
//SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//DrawLines(BlueSquareTwo.Rect(), PurpleBall.Rect());
//DrawLines(RedSquareOne.Rect(), PurpleBall.Rect());
//SDL_RenderPresent(renderer);