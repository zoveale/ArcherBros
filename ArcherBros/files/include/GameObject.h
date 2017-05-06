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
  SDL_Rect camera;

  Physics physics;
  Render render;
  ObjectDirection currentState;
  Movement move;

  SDL_Point velocity{2, 2};

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
  SDL_Rect Camera();
  bool ObjectCollision(bool a);
  bool HorzCollision(bool a);
  bool VertCollision(bool a);
  void ResetCollision();
  

  void SetVelocity(int x, int y);
  SDL_Point GetVeloctiy();

};

/*
Game Objects made from GameObject template class
*/

class LevelSet : public GameObject{
  private:

  SDL_Texture* levelOne;
  
  public:
  SDL_Texture* GetLevel() {
    return levelOne;
  }
  /**/
  void CameraVeiw(SDL_Rect* camClip) {
    SDL_RenderCopy(renderer, levelOne,
                   camClip, NULL);
  }
  void SetLevel() {

    levelOne = LoadTexture("resource/Map.png");
    render.SetState(levelOne);
  }

  void Update() {
    render.Update(currentState);
  }
};

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

    this->camera.x = (rect.x + (rect.w / 2)) - 320;
    this->camera.y = (rect.y + (rect.h / 2)) - 240;
    
    std::cout << rect.x << ", " << rect.y << "\n";
    /**/
    if (camera.x < 0) { camera.x = 0; }
    if (camera.y < 0) { camera.y = 0; }
    if (camera.x > (global.LEVELWIDTH() - camera.w)) {
      camera.x = (global.LEVELWIDTH() - camera.w);
    }
    if (camera.y >(global.LEVELHEIGHT() - camera.h)) {
      camera.y = (global.LEVELHEIGHT() - camera.h);
    } 
  }

  /**/
  int CamX() { return camera.x; }
  int CamY() { return camera.y; }

  /**/
  void DrawCamView(int x, int y) 
  {
    SDL_Rect test = {rect.x - x, rect.y - y,rect.w, rect.h };
    SDL_RenderCopy(renderer, render.GetState(), NULL, &test);
  }
};

#endif //!GAMEOBJECT

/*
std::cout << "Rect : ";
std::cout << rect.x << "\t" << rect.y << "\t";
std::cout << "Collision Rect : ";
std::cout << tempA.x << "\t" << tempA.y << "\n";
*/