#ifndef WORLD_H
#define WORLD_H
#include "Entity.h"
struct World
{
	struct Entity* entity;
	int column;
	int row;
};
void InitWorld(struct World*);
#endif
