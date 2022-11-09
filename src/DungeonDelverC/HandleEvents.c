#include "HandleEvents.h"
#include <SDL.h>
#include "Constants.h"
#include "CellMap.h"
static void HandleKeyDown(struct World* world, char command)
{
	//movement
	int nextColumn = world->column + (('4' == command) ? (-1) : ('6' == command) ? (1) : (0));
	int nextRow = world->row + (('8' == command) ? (-1) : ('2' == command) ? (1) : (0));
	//collision
	int entityId = GetCellMap(nextColumn, nextRow);
	if (0 != entityId) return;
	world->column = nextColumn;
	world->row = nextRow;
}
static char ToCommand(SDL_KeyCode sym)
{
	return
		(sym == SDLK_LEFT) ? ('4') :
		(sym == SDLK_RIGHT) ? ('6') :
		(sym == SDLK_UP) ? ('8') :
		(sym == SDLK_DOWN) ? ('2') :
		(0);
}
int HandleEvents(struct World* world)
{
	static SDL_Event event = { 0 };
	for (;;)
		if (!SDL_PollEvent(&event)) return 1;
		else if (event.type == SDL_QUIT) return 0;
		else if (event.type == SDL_KEYDOWN) HandleKeyDown(world, ToCommand(event.key.keysym.sym));
}
