#include <SDL.h>
SDL_Window* g_window = 0;
SDL_Renderer* g_renderer = 0;
struct Globals
{
	SDL_Window* window;
	SDL_Renderer* renderer;
};
struct Globals* Globals_Initialize()
{
	struct Globals* ptr = SDL_malloc(sizeof(struct Globals));
	SDL_memset(ptr, 0, sizeof(struct Globals));
	return ptr;
}
void Globals_CleanUp(struct Globals** ptr)
{
	if (ptr && *ptr)
	{
		SDL_free(*ptr);
		*ptr = 0;
	}
}
SDL_Window* Globals_GetWindow(struct Globals* ptr)
{
	return g_window;
}

void Globals_SetWindow(struct Globals* ptr, SDL_Window* window)
{
	g_window = window;
}

SDL_Renderer* Globals_GetRenderer(struct Globals* ptr)
{
	return g_renderer;
}

void Globals_SetRenderer(struct Globals* ptr, SDL_Renderer* renderer)
{
	g_renderer = renderer;
}
