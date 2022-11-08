#include "Globals.h"
#include <SDL_image.h>
#include "Textures.h"
#include "Utility.h"
struct Application
{
	struct Textures* textures;
	struct Globals* globals;
	SDL_Rect dst;
	SDL_Rect src;
};
int Application_HandleCommand(struct Application* ptr, char command)
{
	switch (command)
	{
	case '8':
		ptr->dst.y -= 16;
		return 1;
	case '2':
		ptr->dst.y += 16;
		return 1;
	case '4':
		ptr->dst.x -= 16;
		return 1;
	case '6':
		ptr->dst.x += 16;
		return 1;
	case '.':
		return 0;
	default:
		return 1;
	}
}
struct Globals* Application_GetGlobals(struct Application* ptr)
{
	return ptr->globals;
}
struct Application* Application_Initialize(struct Globals* globals)
{
	struct Application* ptr = Utility_Allocate(sizeof(struct Application));
	ptr->globals = globals;
	ptr->textures = Textures_Initialize(globals);
	IMG_Init(IMG_INIT_PNG);
	ptr->src.x = 32;
	ptr->src.y = 0;
	ptr->src.w = 16;
	ptr->src.h = 16;
	ptr->dst.x = SCREEN_WIDTH/2;
	ptr->dst.y = SCREEN_HEIGHT/2;
	ptr->dst.w = 16;
	ptr->dst.h = 16;
	return ptr;
}
void Application_Draw(struct Application* ptr)
{
	SDL_RenderCopy(
		Globals_GetRenderer(ptr->globals), 
		Textures_get(ptr->textures, TEXTURES_ROMFONT), 
		&(ptr->src), 
		&(ptr->dst));
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
