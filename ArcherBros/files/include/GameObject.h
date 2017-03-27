#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "../include/Input.h"
#include "../include/Movement.h"
#include "../include/Render.h"
#include "../include/Physics.h"

/*
GameObject is now a template (Abstract base Class)
*/
class GameObject {
protected:
	SDL_Renderer* renderer;
	KEY_STATE KEY;
	SDL_Rect rect;

  Physics physics;
	Render render;
	ObjectDirection currentState;
	Movement move;

	SDL_Point velocity;

	


public:
	GameObject();

	SDL_Texture* LoadTexture(std::string path);

	bool InitDirectionalTextures(std::string idel, std::string up,
		std::string down, std::string left, std::string right);



	void Initialization(int x, int y, int w, int h);


	virtual void Update() = 0;
	void Draw();
	void SetRenderer(SDL_Renderer* renderer);
	void SetInput(const KEY_STATE &KEY);
	void Close();
	~GameObject();

	SDL_Rect Rect();




};



/*
Game Objects made from GameObject template class
*/
class Redsquare : public GameObject {

public:
	void Update() {
		move.PlayerOne(velocity, KEY, currentState);

		SDL_Rect temp{ rect.x + velocity.x, rect.y + velocity.y,
		rect.w, rect.h };

		if (physics.CheckWindowCollision(temp)) {
			velocity.x = 0;
			velocity.y = 0;
		}

		render.Update(currentState);
		rect.x += velocity.x;
		rect.y += velocity.y;
	}

};

class Bluesquare : public GameObject {
public:

	void Update() {
		move.PlayerTwo(velocity, KEY, currentState);

		SDL_Rect temp{ rect.x + velocity.x, rect.y + velocity.y,
			rect.w, rect.h };

		if (physics.CheckWindowCollision(temp)) {
			velocity.x = 0;
			velocity.y = 0;
      
		}

		render.Update(currentState);
		

		rect.x += velocity.x;
		rect.y += velocity.y;
	}
};


#endif //!GAMEOBJECT