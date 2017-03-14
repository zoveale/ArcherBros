#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>

struct KEY_STATE{
	bool UP = false;
	bool DOWN = false;
	bool LEFT = false;
	bool RIGHT = false;

};

class Input
{
private:
	SDL_Event event;
	bool quit;
	KEY_STATE KEY_STATE;
public:
	Input();
	bool Quit();
	void Process();
	~Input();
};

#endif // !INPUT_H