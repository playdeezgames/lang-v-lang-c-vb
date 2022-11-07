#include "Globals.h"
#include <SDL_image.h>
#include "Textures.h"
int Application_Updater(char command)
{
	return '.' != command;
}
void Application_Initialize()
{
	SDL_RenderSetLogicalSize(Globals_GetRenderer(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	IMG_Init(IMG_INIT_PNG);
	Textures_Initialize();
}
void Application_Draw(SDL_Renderer* renderer)
{
	SDL_Rect dst = {0,0,16,16};
	SDL_Rect src = { 32,0,16,16 };
	SDL_RenderCopy(Globals_GetRenderer(), Textures_get(TEXTURES_ROMFONT), &src, &dst);
}
void Application_CleanUp()
{
	Textures_CleanUp();
	IMG_Quit();
}
