#include "Globals.h"
#include <SDL_image.h>
SDL_Texture* g_texture;
int Application_Updater(char command)
{
	return '.' != command;
}
void Application_Initialize()
{
	SDL_RenderSetLogicalSize(g_renderer, GetScreenWidth() / 2, GetScreenHeight() / 2);
	IMG_Init(IMG_INIT_PNG);
	g_texture = IMG_LoadTexture(g_renderer, "E:\\GIT\\lang-v-lang-c-vb\\assets\\romfont8x8.png");
}
void Application_Draw(SDL_Renderer* renderer)
{
	SDL_Rect dst = {0,0,16,16};
	SDL_Rect src = { 32,0,16,16 };
	SDL_RenderCopy(g_renderer, g_texture, &src, &dst);
}
void Application_CleanUp()
{
	if (g_texture)
	{
		SDL_DestroyTexture(g_texture);
		g_texture = 0;
	}
	IMG_Quit();
}
