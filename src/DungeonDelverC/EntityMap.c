#include "Constants.h"
#include "Entity.h"
static struct Entity* cellMap[GRID_COUNT] = { 0 };
void InitMap()
{
	int index = 0;
	int column;
	int row;
Loop:
	if (index == GRID_COUNT) return;
	column = index % GRID_COLUMNS;
	row = index / GRID_COLUMNS;
	cellMap[index]= (column == 0 || column == GRID_COLUMNS - 1 || row == 0 || row == GRID_ROWS - 1) ? (GetEntity(ENTITY_WALL)) : (GetEntity(ENTITY_EMPTY));
	++index;
	goto Loop;
}
void SetMapEntity(int column, int row, struct Entity* cellType)
{
	cellMap[column + row * GRID_COLUMNS] = cellType;
}
struct Entity* GetMapEntity(int column, int row)
{
	return cellMap[column + row * GRID_COLUMNS];
}
