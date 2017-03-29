#ifndef RENDER_H
#define RENDER_H


#include <vector>
#include "../include/Input.h"

class Render {
private:
	SDL_Texture* currentState;
	std::vector<SDL_Texture*> state;

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

	SDL_Texture* GetState() const { return currentState; }

	void AddState(SDL_Texture* state) { this->state.push_back(state); }

  //Destroy Fuctions
  void Close() {
	  for (int i = 0; i < state.size(); i++) {
		  SDL_DestroyTexture(state.at(i));
	  }
	  currentState = nullptr;
  }
};

#endif // !RENDER_H

