#ifndef TEXTURES_H
#define TEXTURES_H
#include <SDL.h>
enum {
	TEXTURES_ROMFONT,
	TEXTURES_COUNT
};
struct Textures;
struct Textures* Textures_Initialize(struct Globals*);
SDL_Texture* Textures_get(struct Textures*, int);
void Textures_CleanUp(struct Textures**);
#endif
