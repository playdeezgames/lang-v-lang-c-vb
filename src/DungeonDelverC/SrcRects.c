#include "SrcRects.h"
#include "Constants.h"
enum
{
	PATTERN_COLUMNS=16,
	PATTERN_ROWS = 16,
	PATTERN_COUNT = PATTERN_COLUMNS * PATTERN_ROWS
};
static SDL_Rect srcRects[PATTERN_COUNT] = { 0 };
static void Initialize()
{
	static int initialized = 0;
	if (initialized) return;
	int index = 0;
	int column;
	int row;
Loop:
	if (index == PATTERN_COUNT) goto Done;
	column = index % PATTERN_COLUMNS;
	row = index / PATTERN_ROWS;
	srcRects[index].x = column * CELL_WIDTH;
	srcRects[index].y = row * CELL_HEIGHT;
	srcRects[index].w = CELL_WIDTH;
	srcRects[index].h = CELL_HEIGHT;
	++index;
	goto Loop;
Done:
	initialized = 1;
}
SDL_Rect* GetSrcRect(int index)
{
	Initialize();
	return srcRects + index;
}
