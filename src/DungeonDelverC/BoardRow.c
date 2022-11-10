#include "BoardRow.h"
void InitBoardRow(struct BoardRow* row)
{
	for (int column = 0; column < BOARD_COLUMNS; ++column) InitBoardCell(row->cells + column);
}
