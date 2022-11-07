#include <SDL.h>
SDL_Window* g_window = 0;
SDL_Renderer* g_renderer = 0;
SDL_Window* Globals_GetWindow()
{
	return g_window;
}

void Globals_SetWindow(SDL_Window* window)
{
	g_window = window;
}

SDL_Renderer* Globals_GetRenderer()
{
	return g_renderer;
}

void Globals_SetRenderer(SDL_Renderer* renderer)
{
	g_renderer = renderer;
}
