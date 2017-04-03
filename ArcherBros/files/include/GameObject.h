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
#include "../include/Global.h"

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

  SDL_Point velocity{5, 5};

  bool collision = false;

  bool xCollision = false;
  bool yCollision = false;

  Global global;



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

  SDL_Rect FutureRect();
  SDL_Rect Rect();
  bool ObjectCollision(bool a);

};

/*
Game Objects made from GameObject template class
*/
class Redsquare: public GameObject {
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
    if (physics.CheckWindowCollision(FutureRect())) {
      velocity.x = 0;
      velocity.y = 0;
      std::cout << "Wall Collision\n";
    }
  }
  void Update() {
    render.Update(currentState);
    rect.x += velocity.x;
    rect.y += velocity.y;
  }
};

class Bluesquare: public GameObject {
  public:

  void Position() {
    move.PlayerTwo(velocity, KEY, currentState);
  }

  void Collision() {
    if (collision) {
      velocity.x = 0;
      velocity.y = 0;
    }
    if (physics.CheckWindowCollision(FutureRect())) {
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

//

class Ball: public GameObject {

  public:
  void Position() {
    move.Projectile(velocity, KEY, currentState);
  }

  void Collision() {
    if (physics.CheckWidthCollision(rect)
      /*|| xCollid with object*/) {
      velocity.x *= -1;
    }
    if (physics.CheckHeightCollision(rect)
      /*|| yCollid with object*/) {
      velocity.y *= -1;
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