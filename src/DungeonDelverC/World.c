#include "World.h"
#include "Constants.h"
void InitWorld(struct World* world)
{
	InitAtlas(&(world->atlas));
}