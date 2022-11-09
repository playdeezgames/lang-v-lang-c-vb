#include "Constants.h"
#include "Entity.h"
#include "Map.h"
static struct Entity* cellMap[GRID_COUNT] = { 0 };
static void InitCell(int index, int column, int row)
{
	cellMap[index] =
		(column == GRID_COLUMNS/2 && row == GRID_ROWS/2) ? GetEntity(ENTITY_DUDE) :
		(column == 0 || column == GRID_COLUMNS - 1 || row == 0 || row == GRID_ROWS - 1) ? GetEntity(ENTITY_WALL) :
		GetEntity(ENTITY_EMPTY);
}
void InitMap()
{
	for (int index = 0; index < GRID_COUNT; ++index) InitCell(index, index % GRID_COLUMNS, index / GRID_COLUMNS);
}
void SetMapEntity(int column, int row, struct Entity* cellType)
{
	cellMap[column + row * GRID_COLUMNS] = cellType;
}
struct Entity* GetMapEntity(int column, int row)
{
	return cellMap[column + row * GRID_COLUMNS];
}
