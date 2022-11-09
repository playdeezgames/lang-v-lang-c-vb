#include "Constants.h"
static int cellMap[GRID_COUNT] = { 0 };
void InitCellMap()
{
	int index = 0;
	int column;
	int row;
Loop:
	if (index == GRID_COUNT) return;
	column = index % GRID_COLUMNS;
	row = index / GRID_COLUMNS;
	cellMap[index]= (column == 0 || column == GRID_COLUMNS - 1 || row == 0 || row == GRID_ROWS - 1) ? (1) : (0);
	++index;
	goto Loop;
}

void SetCellMap(int column, int row, int cellType)
{
	cellMap[column + row * GRID_COLUMNS] = cellType;
}

int GetCellMap(int column, int row)
{
	return cellMap[column + row * GRID_COLUMNS];
}
