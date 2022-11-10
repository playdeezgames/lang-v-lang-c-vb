#include "BoardCell.h"
void InitBoardCell(struct BoardCell* cell)
{
	InitTerrain(&(cell->terrain));
}