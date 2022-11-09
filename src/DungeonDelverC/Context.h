#ifndef CONTEXT_H
#define CONTEXT_H
#include <SDL.h>
struct Context
{
	int sdl;
	int img;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};
int InitContext(struct Context*);
void CleanUpContext(struct Context*);
#endif
