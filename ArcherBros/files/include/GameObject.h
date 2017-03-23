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
class GameObject {
  protected:

  /*
  Enum for direction of GameObjects
  */
  enum ObjectDirection {
    IDEL, UP, DOWN, LEFT, RIGHT, TOTAL
  };

  SDL_Renderer* renderer;
  KEY_STATE KEY;
  SDL_Rect rect;

  SDL_Texture* texture;
  SDL_Texture* directionTexture[TOTAL];
  Movement move;

  


  public:
  GameObject();

  SDL_Texture* LoadTexture(std::string path);

  bool InitDirectionalTextures(std::string idel, std::string up,
    std::string down, std::string left, std::string right);

  SDL_Texture* GetIdelTexture();

  void Initialization(SDL_Texture* texture,
    int x, int y, int w, int h);


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
class Redsquare: public GameObject {
  private:

  const int h = 50;
  const int w = 50;


  public:

  int getH() {
    return h;
  }
  int getW() {
    return w;
  }

  void Update() {
    move.Left(rect, KEY);

    texture = directionTexture[IDEL];

    if (KEY.UP) {
      texture = directionTexture[UP];
    }
    if (KEY.DOWN) {
      texture = directionTexture[DOWN];
    }
    if (KEY.LEFT) {
      texture = directionTexture[LEFT];
    }
    if (KEY.RIGHT) {
      texture = directionTexture[RIGHT];
    }
  }

};

class Bluesquare: public GameObject {
  public:

  void Update() {
    move.Right(rect, KEY);

    texture = directionTexture[IDEL];

    if (KEY.W) {
      texture = directionTexture[UP];
    }
    if (KEY.S) {
      texture = directionTexture[DOWN];
    }
    if (KEY.A) {
      texture = directionTexture[LEFT];
    }
    if (KEY.D) {
      texture = directionTexture[RIGHT];
    }

  }
};


#endif //!GAMEOBJECT