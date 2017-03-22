#include "..\include\GameObject.h"



GameObject::GameObject()
{
}

void GameObject::Initialization(std::string path,
	int x, int y, int w, int h)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL) { std::cout << SDL_GetError(); }

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) { std::cout << SDL_GetError(); }

	SDL_FreeSurface(surface);
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
