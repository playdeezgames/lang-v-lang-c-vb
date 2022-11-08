#ifndef GLOBALS_H
#define GLOBALS_H
#include <SDL.h>
enum
{
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720
};
struct Globals;

struct Globals* Globals_Initialize();
void Globals_CleanUp(struct Globals**);

SDL_Window* Globals_GetWindow(struct Globals* ptr);
void Globals_SetWindow(struct Globals* ptr, SDL_Window* window);

SDL_Renderer* Globals_GetRenderer(struct Globals* ptr);
void Globals_SetRenderer(struct Globals* ptr, SDL_Renderer* renderer);

#endif

