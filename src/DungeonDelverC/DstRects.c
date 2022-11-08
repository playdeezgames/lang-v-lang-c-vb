#include "DstRects.h"
#include "Constants.h"
static SDL_Rect dstRects[GRID_COUNT] = { 0 };
static void Initialize()
{
	static int initialized = 0;
	if (initialized) return;
	int index = 0;
	int column;
	int row;
Loop:
	if (index == GRID_COUNT) goto Done;
	row = index / GRID_COLUMNS;
	column = index % GRID_COLUMNS;
	dstRects[index].x = column * CELL_WIDTH;
	dstRects[index].y = row * CELL_HEIGHT;
	dstRects[index].w = CELL_WIDTH;
	dstRects[index].h = CELL_HEIGHT;
	++index;
	goto Loop;
Done:
	initialized = 1;
}
SDL_Rect* GetDstRect(int index)
{
	Initialize();
	return dstRects + index;
}
