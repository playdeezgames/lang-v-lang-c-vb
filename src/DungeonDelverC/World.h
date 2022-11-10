#ifndef WORLD_H
#define WORLD_H
#include "Atlas.h"
struct World
{
	int atlas_column;
	int atlas_row;
	int board_column;
	int board_row;
	struct Atlas atlas;
};
void InitWorld(struct World*);
#endif
