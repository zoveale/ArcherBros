#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>

struct KEY_STATE{
	bool UP = false;
	bool DOWN = false;
	bool LEFT = false;
	bool RIGHT = false;

	bool W = false;
	bool S = false;
	bool A = false;
	bool D = false;
};

enum ObjectDirection {
	IDEL, UP, DOWN, LEFT, RIGHT, TOTAL
};

class Input
{
private:
	SDL_Event event;
	bool quit;
	KEY_STATE KEY;
public:
	Input();
	bool Quit();
	void Process();
	KEY_STATE GetInput();
	~Input();
};

#endif // !INPUT_H