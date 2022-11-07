#include "Textures.h"
#include "Globals.h"
#include <SDL.h>
#include <SDL_image.h>
static const char* s_filenames[TEXTURES_COUNT] = {"romfont8x8.png"};
static SDL_Texture* s_textures[TEXTURES_COUNT];
void Textures_Initialize()
{
	for (int index = 0; index < TEXTURES_COUNT; ++index)
	{
		s_textures[index] = IMG_LoadTexture(Globals_GetRenderer(), s_filenames[index]);
	}
}

SDL_Texture* Textures_get(int index)
{
	return s_textures[index];
}

void Textures_CleanUp()
{
	for (int index = 0; index < TEXTURES_COUNT; ++index)
	{
		if (s_textures[index])
		{
			SDL_DestroyTexture(s_textures[index]);
			s_textures[index] = 0;
		}
	}
}
