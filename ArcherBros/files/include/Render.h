#ifndef RENDER_H
#define RENDER_H


#include <vector>
#include "../include/Input.h"

class Render {
private:
	SDL_Texture* currentState;
	std::vector<SDL_Texture*> state;
  SDL_Texture* currentLevel;
  std::vector<SDL_Texture*> level;

public:
	void Update(const ObjectDirection& current) {
		switch (current) {
		case ObjectDirection::UP:
			currentState = state.at(0);
			break;
		case ObjectDirection::DOWN:
			currentState = state.at(1);
			break;
		case ObjectDirection::LEFT:
			currentState = state.at(2);
			break;
		case ObjectDirection::RIGHT:
			currentState = state.at(3);
			break;
		default :
			currentState = state.at(4);
		}

	}
  
  
  void AddState(SDL_Texture* state) {this->state.push_back(state); }
	SDL_Texture* GetState() const { return currentState; }

  void SetLevel(SDL_Texture* level){ currentLevel = level;};
	void AddLevel(SDL_Texture* level) {this->level.push_back(level);}
  SDL_Texture*  GetLevel()  const { return currentLevel; }

  //Destroy Fuctions
  void Close() {
	  for (int i = 0; i < state.size(); i++) {
		  SDL_DestroyTexture(state.at(i));
	  }
    for (int i = 0; i < level.size(); i++) {
      SDL_DestroyTexture(level.at(i));
    }
	  currentState = nullptr;
    currentLevel = nullptr;
  }
};

#endif // !RENDER_H

