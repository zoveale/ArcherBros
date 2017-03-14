#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "../include/Input.h"

class GameObject
{
private:
	SDL_Renderer* renderer;
	KEY_STATE KEY;
	SDL_Rect rect;
	SDL_Texture* texture;

public:
	GameObject();

	void Initialization(std::string path, int x, int y, int w, int h);
	void Update();
	void Draw();
	void SetRenderer(SDL_Renderer* renderer);
	void SetInput(const KEY_STATE &KEY);
	void Close();

	~GameObject();
};

#endif //!GAMEOBJECT