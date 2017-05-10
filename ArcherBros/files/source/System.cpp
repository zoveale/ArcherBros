#include "../include/System.h"



System::System() {}

void System::Initialization() {

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }

  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("Archer BROS!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 480,
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
  LevelOne.SetRenderer(renderer);
  LevelOne.Initialization(0, 0,
    global.LEVEL_W(), global.LEVEL_H());
  LevelOne.SetLevel();



  RedSquareOne.SetRenderer(renderer);
  RedSquareOne.InitDirectionalTextures("resource/red_square_idel.png",
    "resource/red_square_up.png", "resource/red_square_down.png",
    "resource/red_square_left.png", "resource/red_square_right.png");
  RedSquareOne.Initialization(0, 0, 50, 50);

  InitTrees();

}

void System::GameLoop() {

  while (!input.Quit()) {
    ResetCollision();

    //Input 
    input.Process();
    RedSquareOne.SetInput(input.GetInput());


    //Update Objects Positions
    RedSquareOne.Position();

    //Checks Object Collision

    //check Objects Collision and update velocity
    RedSquareOne.ObjectCollision(PlayerCollision());
    RedSquareOne.Collision();

    //Update Objects  Textures

    RedSquareOne.Update();


    //Background Color (rgb, alpha)

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //Clear Screen
    SDL_RenderClear(renderer);

    //Draw Objects
    LevelOne.CameraVeiw(&RedSquareOne.Camera());

    for (int i = 0; i < 32; i++) {
      Tree[i].DrawPosition(RedSquareOne.CamX(),
        RedSquareOne.CamY());
    }

    RedSquareOne.DrawCamView(RedSquareOne.CamX(),
      RedSquareOne.CamY());



//DrawLines(RedSquareOne.FutureRect(), RedSquareOne.Camera());

//Update Screen
    SDL_RenderPresent(renderer);

    //

  }
}

void System::Close() {
  //Destroy Textures
  RedSquareOne.Close();
  LevelOne.Close();
  

  //Quit SDL subsystems
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

System::~System() {}

bool System::PlayerCollision() {

  for (int i = 0; i < 32; i++) {
    if (physics.CheckObjectCollision(
      RedSquareOne.FutureRect(),
      Tree[i].Rect())){
      return true;
    }
  }
  return false;
}

void System::HorzCollision() {}

void System::ResetCollision() {
  RedSquareOne.ResetCollision();
}


void System::InitTrees() {
  int h = 0;
  int x = 60;
  int y = 100;
  for (int u = 0; u < 32; u++) {
    Tree[u].SetRenderer(renderer);
    Tree[u].SetTreeTexture("resource/treeThree.png");

  }
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 8; i++) {
      Tree[h].Initialization(x, y, 128, 128);
      std::cout << "h = " << h << "\n";
      h += 1;
      x += 240;
    }
    y += 245;
    x = 60;
  }

  SDL_Delay(1000);
}

void System::DrawLines(SDL_Rect& a, SDL_Rect& b) {
  SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
  SDL_RenderDrawLine(renderer, a.x + a.w, a.y, b.x + b.w, b.y);
  SDL_RenderDrawLine(renderer, a.x, a.y + a.h, b.x, b.y + b.h);
  SDL_RenderDrawLine(renderer, a.x + a.w, a.y + a.h, b.x + b.w, b.y + b.h);
}
