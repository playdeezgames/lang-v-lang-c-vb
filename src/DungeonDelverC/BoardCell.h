#ifndef BOARDCELL_H
#define BOARDCELL_H
#include "Terrain.h"
struct BoardCell
{
	struct Terrain terrain;
};
void InitBoardCell(struct BoardCell*);
#endif
