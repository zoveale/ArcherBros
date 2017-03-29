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

  bool collision = false;


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

  bool ObjectCollision(bool a) {
    if (a) {
      this->collision = true;
      return collision;
    }
    else {
      this->collision = false;
      return collision;
    }
  }

};



/*
Game Objects made from GameObject template class
*/
class Redsquare: public GameObject {
  private:
  //int time = 10;
  public:
  void Position() {
    move.PlayerOne(velocity, KEY, currentState);
	
  }
/*
*/
  void Collision() {
    
    if (collision) {
		velocity.x = 0;
		velocity.y = 0;
		std::cout << "Collision\n";
      
    }
	if (physics.CheckWindowCollision(Rect())) {
		velocity.x = 0;
		velocity.y = 0;
		std::cout << "Wall Collision\n";

	}
    
    
/*
*/
  }
  void Update() {
    render.Update(currentState);
    rect.x += velocity.x;
    rect.y += velocity.y;
  }
};

class Bluesquare: public GameObject {
  private:
  //int time = 1;
  public:

  void Position() {
    move.PlayerTwo(velocity, KEY, currentState);
    
  }

  void Collision() {
	  if (collision) {
		  velocity.x = 0;
		  velocity.y = 0;
	  }
	  if (physics.CheckWindowCollision(Rect())) {
		  velocity.x = 0;
		  velocity.y = 0;
	  }
  }

  void Update() {
    render.Update(currentState);
    rect.x += velocity.x;
    rect.y += velocity.y;
  }

};


#endif //!GAMEOBJECT

/*
std::cout << "Rect : ";
std::cout << rect.x << "\t" << rect.y << "\t";
std::cout << "Collision Rect : ";
std::cout << tempA.x << "\t" << tempA.y << "\n";
*/