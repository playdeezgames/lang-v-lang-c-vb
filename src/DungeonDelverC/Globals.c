#include <SDL.h>
#include "Utility.h"
struct Globals
{
	SDL_Window* window;
	SDL_Renderer* renderer;
};
struct Globals* Globals_Initialize()
{
	struct Globals* ptr = Utility_Allocate(sizeof(struct Globals));
	return ptr;
}
void Globals_CleanUp(struct Globals** ptr)
{
	Utility_free(ptr);
}
SDL_Window* Globals_GetWindow(struct Globals* ptr)
{
	return ptr->window;
}

void Globals_SetWindow(struct Globals* ptr, SDL_Window* window)
{
	ptr->window = window;
}

SDL_Renderer* Globals_GetRenderer(struct Globals* ptr)
{
	return ptr->renderer;
}

void Globals_SetRenderer(struct Globals* ptr, SDL_Renderer* renderer)
{
	ptr->renderer = renderer;
}
