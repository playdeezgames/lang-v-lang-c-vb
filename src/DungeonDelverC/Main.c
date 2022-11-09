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
	if (InitContext(context)) return 0;
	InitSrcRects();
	InitDstRects();
	InitCellMap();
	return 1;
}
void HandleKeyDown(int* index, SDL_KeyCode sym)
{
	int nextIndex = 0;
	int delta = 0;
	delta =
		(SDLK_LEFT == sym) ? (-1) :
		(SDLK_RIGHT == sym) ? (1) :
		(SDLK_UP == sym) ? (-GRID_COLUMNS) :
		(SDLK_DOWN == sym) ? (GRID_COLUMNS) :
		(0);
	nextIndex = (*index + delta) % (GRID_COUNT);

	*index = (0 == GetCellMap(nextIndex % GRID_COLUMNS, nextIndex / GRID_COLUMNS)) ? (nextIndex) : (*index);
}
int HandleEvents(int* index)
{
	static SDL_Event event = { 0 };
	for(;;)
		if (!SDL_PollEvent(&event)) return 1; 
		else if (event.type == SDL_QUIT) return 0; 
		else if (event.type == SDL_KEYDOWN) HandleKeyDown(index, event.key.keysym.sym);
}
int main(int argc, char** argv)
{
	struct Context context = { 0 };
	int index = GRID_COLUMNS/2 + (GRID_ROWS/2) * GRID_COLUMNS;
	if (Init(&context)) 
		do Draw(&context, index); 
		while (HandleEvents(&index));
	CleanUpContext(&context);
	return 0;
}
