#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <string>
#include "../include/Input.h"

class GameObject
{
private:
	SDL_Renderer* renderer;
	Input input;
	SDL_Rect rect;
	SDL_Texture* texture;

public:
	GameObject();

	void Initialization(std::string path);
	void Update();
	void Draw();
	void SetRenderer(const SDL_Renderer* renderer);
	void SetInput(const Input &input);

	~GameObject();
};

#endif //!GAMEOBJECT