#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "../include/Input.h"
#include "../include/Movement.h"
/*
GameObject is now a template (Abstract base Class) 
*/
class GameObject
{
protected:

	SDL_Renderer* renderer;
	KEY_STATE KEY;
	SDL_Rect rect;
	SDL_Texture* texture;
	Movement move;

public:
	GameObject();

	void Initialization(std::string path, int x, int y, int w, int h);
	virtual void Update() = 0;
	void Draw();
	void SetRenderer(SDL_Renderer* renderer);
	void SetInput(const KEY_STATE &KEY);
	void Close();

	~GameObject();
};

/*
Game Objects made from GameObject template class
*/
class Redsquare : public GameObject
{
public: 

	void Update() {
		move.Left(rect, KEY);
	}
};

class Bluesquare : public GameObject
{
public:

	void Update() {
		move.Right(rect, KEY);
	}
};


#endif //!GAMEOBJECT