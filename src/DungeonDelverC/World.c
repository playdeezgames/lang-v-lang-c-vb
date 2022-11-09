#include "World.h"
#include "Constants.h"
#include "Entity.h"
void InitWorld(struct World* world)
{
	world->entity = GetEntity(ENTITY_DUDE);
	world->column = GRID_COLUMNS / 2;
	world->row = GRID_ROWS / 2;
}