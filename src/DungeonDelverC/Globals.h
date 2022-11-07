#ifndef GLOBALS_H
#define GLOBALS_H
#include <SDL.h>
enum
{
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720
};
SDL_Window* Globals_GetWindow();
void Globals_SetWindow(SDL_Window* window);
SDL_Renderer* Globals_GetRenderer();
void Globals_SetRenderer(SDL_Renderer* renderer);
#endif

