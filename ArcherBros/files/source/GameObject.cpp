#include "..\include\GameObject.h"



GameObject::GameObject(){}

SDL_Texture* GameObject::LoadTexture(std::string path) {
 
  SDL_Texture* loadTexture = nullptr;
  SDL_Surface* surface = IMG_Load(path.c_str());
  if (surface == nullptr) { std::cout << SDL_GetError() << "\n";}
  else{
    loadTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (loadTexture == nullptr) { std::cout  << SDL_GetError() << "\n";}
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



void GameObject::Initialization(int x, int y,
                                int w, int h)
{
	this->rect = { x, y, w, h };

  this->camera = {x - 295, y - 215, 640, 480};
}

void GameObject::Draw()
{
  rect.x -= camera.x;
  rect.y -= camera.y;
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
	render.Close();
}

GameObject::~GameObject(){}

//Future Rect
SDL_Rect GameObject::FutureRect() {
	SDL_Rect future{ rect.x + velocity.x,
    rect.y + velocity.y, rect.w, rect.h };
  return future;
}

SDL_Rect GameObject::Rect() {
  return rect;
}

SDL_Rect GameObject::Camera() {
  return camera;
}

bool GameObject::ObjectCollision(bool a) {
  if (a) {this->collision = true;
    return collision;}
  else {this->collision = false;
    return collision;}
}

bool GameObject::HorzCollision(bool a) {
  if (a) {
    this->xCollision = true;
    return xCollision;
  }
  
}

bool GameObject::VertCollision(bool a) {
  if (a) {
    this->yCollision = true;
    return yCollision;
  }
  else {
    this->yCollision = false;
    return yCollision;
  }
}

void GameObject::ResetCollision() {
  this->collision = false;
  this->xCollision = false;
  this->yCollision = false;
}

void GameObject::SetVelocity(int x, int y) {

  this->velocity.x = x;
  this->velocity.y = y;

}

SDL_Point GameObject::GetVeloctiy() {
  return velocity;
}



