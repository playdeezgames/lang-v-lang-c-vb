#include "DstRects.h"
#include "Constants.h"
static SDL_Rect dstRects[GRID_COUNT] = { 0 };
static void InitDstRect(int index, int column, int row)
{
	dstRects[index].x = column * CELL_WIDTH;
	dstRects[index].y = row * CELL_HEIGHT;
	dstRects[index].w = CELL_WIDTH;
	dstRects[index].h = CELL_HEIGHT;
}
void InitDstRects()
{
	for (int index = 0; index < GRID_COUNT; ++index) InitDstRect(index, index % GRID_COLUMNS, index / GRID_COLUMNS);
}
SDL_Rect* GetDstRect(int index)
{
	return dstRects + index;
}
