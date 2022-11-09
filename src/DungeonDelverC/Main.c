#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "CellMap.h"
#include "Context.h"
#include "Entity.h"
#include "Draw.h"
#include "HandleEvents.h"
int Init(struct Context* context)
{
	if (InitContext(context)) return 0;
	InitSrcRects();
	InitDstRects();
	InitCellMap();
	return 1;
}
int main(int argc, char** argv)
{
	struct Context context = { 0 };
	int index = GRID_COLUMNS/2 + (GRID_ROWS/2) * GRID_COLUMNS;
	if (Init(&context)) 
		do Draw(&context, index); 
		while (HandleEvents(&index));
	CleanUpContext(&context);
	return 0;
}
