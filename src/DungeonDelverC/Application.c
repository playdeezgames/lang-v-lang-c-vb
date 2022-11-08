#include "Globals.h"
#include <SDL_image.h>
#include "Textures.h"
struct Application
{
	struct Textures* textures;
	struct Globals* globals;
};
int Application_HandleCommand(struct Application* ptr, char command)
{
	return '.' != command;
}
struct Globals* Application_GetGlobals(struct Application* ptr)
{
	return ptr->globals;
}
struct Application* Application_Initialize(struct Globals* globals)
{
	struct Application* ptr = SDL_malloc(sizeof(struct Application));
	SDL_memset(ptr, 0, sizeof(struct Application));
	ptr->globals = globals;
	ptr->textures = Textures_Initialize(globals);
	SDL_RenderSetLogicalSize(Globals_GetRenderer(ptr->globals), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	IMG_Init(IMG_INIT_PNG);
	return ptr;
}
void Application_Draw(struct Application* ptr)
{
	SDL_Rect dst = {0,0,16,16};
	SDL_Rect src = { 32,0,16,16 };
	SDL_RenderCopy(Globals_GetRenderer(ptr->globals), Textures_get(ptr->textures, TEXTURES_ROMFONT), &src, &dst);
}
void Application_CleanUp(struct Application** ptr)
{
	if (ptr && *ptr)
	{
		Textures_CleanUp(&(*ptr)->textures);
		IMG_Quit();
		SDL_free(*ptr);
		*ptr = 0;
	}
}
