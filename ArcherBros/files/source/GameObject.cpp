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

  render.AddState(LoadTexture(up));
  render.AddState(LoadTexture(down));
  render.AddState(LoadTexture(left));
  render.AddState(LoadTexture(right));
  render.AddState(LoadTexture(idel));

  return true;
}



void GameObject::Initialization(int x, int y, int w, int h)
{
    
	rect = { x, y, w, h };
}

void GameObject::Draw()
{
	SDL_RenderCopy(renderer, render.GetState(), NULL, &rect);
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
  for (int i = 0; i < render.AllTextures(); i++) 
  {
    SDL_DestroyTexture(render.States(i));
  }
	
}

GameObject::~GameObject()
{
}


SDL_Rect GameObject::Rect() {
  return rect;
}


