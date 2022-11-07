#ifndef TEXTURES_H
#define TEXTURES_H
#include <SDL.h>
enum {
	TEXTURES_ROMFONT,
	TEXTURES_COUNT
};
void Textures_Initialize();
SDL_Texture* Textures_get(int);
void Textures_CleanUp();
#endif
