#ifndef CELLTYPE_H
#define CELLTYPE_H
#include <SDL.h>
enum {
	CELLTYPE_EMPTY,
	CELLTYPE_WALL,
	CELLTYPE_DUDE,
	CELLTYPE_COUNT
};
struct CellType
{
	unsigned char character;
	SDL_Color color;
};
struct CellType* GetCellType(int);
#endif