#include "Textures.h"
#include "Globals.h"
#include <SDL_image.h>
static const char* s_filenames[TEXTURES_COUNT] = {"romfont8x8.png"};
struct Textures
{
	struct Globals* globals;
	SDL_Texture* textures[TEXTURES_COUNT];
};
struct Textures* Textures_Initialize(struct Globals* globals)
{
	struct Textures* ptr = (struct Textures*)SDL_malloc(sizeof(struct Textures));
	SDL_memset(ptr, 0, sizeof(struct Textures));
	ptr->globals = globals;
	for (int index = 0; index < TEXTURES_COUNT; ++index)
	{
		ptr->textures[index] = IMG_LoadTexture(Globals_GetRenderer(ptr->globals), s_filenames[index]);
	}
	return ptr;
}
SDL_Texture* Textures_get(struct Textures* ptr, int index)
{
	return ptr->textures[index];
}
void Textures_CleanUp(struct Textures** ptr)
{
	if (ptr && *ptr)
	{
		for (int index = 0; index < TEXTURES_COUNT; ++index)
		{
			if ((*ptr)->textures[index])
			{
				SDL_DestroyTexture((*ptr)->textures[index]);
				(*ptr)->textures[index] = 0;
			}
		}
		SDL_free(*ptr);
		*ptr = 0;
	}
}
