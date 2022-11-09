#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "CellMap.h"
#include "Context.h"
#include "Entity.h"
#include "Draw.h"
int Init(struct Context* context)
{
	if (InitContext(context)) return -1;
	InitSrcRects();
	InitDstRects();
	InitCellMap();
	return 0;
}
int HandleEvents(int* index)
{
	int nextIndex = 0;
	int delta = 0;
	static SDL_Event event = { 0 };
StartEventLoop:
	if (!SDL_PollEvent(&event)) return 1;

	if (event.type == SDL_QUIT) return 0;

	if (event.type != SDL_KEYDOWN) goto PostKeyDownEvent;
	delta =
		(SDLK_LEFT == event.key.keysym.sym) ? (-1) :
		(SDLK_RIGHT == event.key.keysym.sym) ? (1) :
		(SDLK_UP == event.key.keysym.sym) ? (-GRID_COLUMNS) :
		(SDLK_DOWN == event.key.keysym.sym) ? (GRID_COLUMNS) :
		(0);
	nextIndex = (*index + delta) % (GRID_COUNT);

	*index = (0 == GetCellMap(nextIndex % GRID_COLUMNS, nextIndex / GRID_COLUMNS)) ? (nextIndex) : (*index);
PostKeyDownEvent:

	goto StartEventLoop;
}
int main(int argc, char** argv)
{
	struct Context context = { 0 };
	int index = GRID_COLUMNS/2 + (GRID_ROWS/2) * GRID_COLUMNS;

	if (Init(&context)) goto CleanUp;

	do Draw(&context, index); while (HandleEvents(&index));

CleanUp:
	CleanUpContext(&context);
	return 0;
}
