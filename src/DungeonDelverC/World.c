#include "World.h"
#include "Constants.h"
void InitWorld(struct World* world)
{
	world->index = GRID_COLUMNS / 2 + (GRID_ROWS / 2) * GRID_COLUMNS;
}