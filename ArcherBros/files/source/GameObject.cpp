#include "..\include\GameObject.h"



GameObject::GameObject()
{
}

SDL_Texture* GameObject::LoadTexture(std::string path) {
  

  SDL_Texture* loadTexture = nullptr;

  SDL_Surface* surface = IMG_Load(path.c_str());
  if (surface == NULL) { std::cout << SDL_GetError() << "\n";}
  else{
    loadTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (loadTexture == NULL) { std::cout  << SDL_GetError() << "\n";}
    SDL_FreeSurface(surface);
  }

  return loadTexture;
}

bool GameObject::InitDirectionalTextures(std::string idel, std::string up,
  std::string down, std::string left, std::string right) {

  directionTexture[IDEL] = LoadTexture(idel);
  directionTexture[UP] = LoadTexture(up);
  directionTexture[DOWN] = LoadTexture(down);
  directionTexture[LEFT] = LoadTexture(left);
  directionTexture[RIGHT] = LoadTexture(right);

  return true;
}

SDL_Texture * GameObject::GetIdelTexture() {
  return directionTexture[IDEL];
}

void GameObject::Initialization(SDL_Texture* idelTexture,
	int x, int y, int w, int h)
{

  /*
  FIX ME:: make IMG_load a fuction that can be accessed 
  by all 
  */
  texture = idelTexture;

	rect = { x, y, w, h };
}






void GameObject::Draw()
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}


void GameObject::SetRenderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void GameObject::SetInput(const KEY_STATE &KEY)
{
	this->KEY = KEY;
}

void GameObject::Close()
{
	SDL_DestroyTexture(texture);
}

GameObject::~GameObject()
{
}
