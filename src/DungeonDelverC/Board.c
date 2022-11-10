#include "Board.h"
void InitBoard(struct Board* board)
{
	int row = 0;
RowLoop:
	if (row == BOARD_ROWS) return;
	InitBoardRow(board->rows + row);
	int column = 0;
ColumnLoop:
	if (column == BOARD_COLUMNS) goto EndColumnLoop;
	board->rows[row].cells[column].terrain.terrain_id = (column==0 || row==0 || column==BOARD_COLUMNS-1 || row==BOARD_ROWS-1) ? (1) : (0);
	++column;
	goto ColumnLoop;
EndColumnLoop:
	++row;
	goto RowLoop;
}