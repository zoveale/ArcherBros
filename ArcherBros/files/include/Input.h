#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>

class Input
{
private:
	SDL_Event event;
	bool quit;
public:
	Input();
	bool Quit();
	void Process();
	~Input();
};

#endif // !INPUT_H