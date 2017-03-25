#include "..\include\GameObject.h"



GameObject::GameObject()
{
  xPos = 0;
  yPos = 0;

  objectCollider = {0,0,0,0};
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
  objectCollider.w = w;
  objectCollider.h = h;
  objectCollider.x = x;
  objectCollider.y = y;

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

void GameObject::SetX(int a) {
rect.x = a;
}

void GameObject::SetY(int a) {
rect.y = a;
}


int GameObject::XPos() {
  return rect.x;
}

int GameObject::YPos() {
  return rect.y;
}

int GameObject::Height() {
  return rect.h;
}

int GameObject::Width() {
  return rect.w;
}

SDL_Rect GameObject::Rect() {
  return rect;
}
