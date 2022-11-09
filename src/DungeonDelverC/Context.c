#include "Context.h"
#include <SDL_image.h>
#include "Constants.h"
int InitContext(struct Context* context)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) return -1; else context->sdl = 1;
	IMG_Init(IMG_INIT_PNG), context->img = 1;
	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &(context->window), &(context->renderer))) return -1;
	SDL_RenderSetLogicalSize(context->renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
	context->texture = IMG_LoadTexture(context->renderer, "romfont8x8.png");
	return 0;
}
void CleanUpContext(struct Context* context)
{
	if (context->texture) SDL_DestroyTexture(context->texture), context->texture = 0;
	if (context->renderer) SDL_DestroyRenderer(context->renderer), context->renderer = 0;
	if (context->window) SDL_DestroyWindow(context->window), context->window = 0;
	if (context->img) IMG_Quit(), context->img = 0;
	if (context->sdl) SDL_Quit(), context->sdl = 0;
}

