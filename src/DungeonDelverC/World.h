#ifndef WORLD_H
#define WORLD_H
#include "Entity.h"
enum
{
	ATLAS_COLUMNS = 8,
	ATLAS_ROWS = 8,
	BOARD_COLUMNS = 21,
	BOARD_ROWS = 21
};
struct Terrain
{
	int terrain_id;
};
struct BoardCell
{
	struct Terrain terrain;
};
struct BoardRow
{
	struct BoardCell cells[BOARD_COLUMNS];
};
struct Board
{
	struct BoardRow rows[BOARD_ROWS];
};
struct AtlasRow
{
	struct Board boards[ATLAS_COLUMNS];
};
struct Atlas
{
	struct AtlasRow rows[ATLAS_ROWS];
};
struct World
{
	struct Entity* entity;
	int column;
	int row;
	struct Atlas atlas;
};
void InitWorld(struct World*);
#endif
