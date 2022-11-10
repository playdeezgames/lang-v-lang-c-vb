#ifndef BOARD_H
#define BOARD_H
#include "BoardRow.h"
enum
{
	BOARD_ROWS = 22
};
struct Board
{
	struct BoardRow rows[BOARD_ROWS];
};
void InitBoard(struct Board*);
#endif