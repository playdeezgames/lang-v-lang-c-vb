#include "HandleEvents.h"
#include <SDL.h>
#include "Constants.h"
#include "CellMap.h"
static void HandleKeyDown(int* index, SDL_KeyCode sym)
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
	for (;;)
		if (!SDL_PollEvent(&event)) return 1;
		else if (event.type == SDL_QUIT) return 0;
		else if (event.type == SDL_KEYDOWN) HandleKeyDown(index, event.key.keysym.sym);
}
