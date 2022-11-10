#include "Board.h"
void InitBoard(struct Board* board)
{
	for (int row = 0; row < BOARD_ROWS; ++row) InitBoardRow(board->rows + row);
}