#ifndef BOARDROW_H
#define BOARDROW_H
#include "BoardCell.h"
enum
{
	BOARD_COLUMNS = 22
};
struct BoardRow
{
	struct BoardCell cells[BOARD_COLUMNS];
};
void InitBoardRow(struct BoardRow*);
#endif