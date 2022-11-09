#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "CellMap.h"
#include "Context.h"
#include "CellType.h"
void DrawCell(struct Context* context, struct CellType* cellType, int cell)
{
	SDL_SetTextureColorMod(context->texture, cellType->color.r, cellType->color.g, cellType->color.b);
	SDL_RenderCopy(context->renderer, context->texture, GetSrcRect(cellType->character), GetDstRect(cell));
}
void DrawCells(struct Context* context)
{
	for (int cell = 0; cell < GRID_COUNT; ++cell) DrawCell(context, GetCellType(GetCellMap(cell % GRID_COLUMNS, cell / GRID_COLUMNS)), cell);
}
void DrawScreen(struct Context* context)
{
	SDL_RenderClear(context->renderer);
	DrawCells(context);
	SDL_RenderPresent(context->renderer);
}
int main(int argc, char** argv)
{
	struct Context context = { 0 };
	SDL_Event event = { 0 };
	int old;
	int index = GRID_COLUMNS/2 + (GRID_ROWS/2) * GRID_COLUMNS;
	int nextIndex = 0;
	int delta = 0;
	int cell = 0;

	if (InitContext(&context)) goto CleanUp;
	InitSrcRects();
	InitDstRects();
	InitCellMap();

StartDraw:
	old = GetCellMap(index % GRID_COLUMNS, index/GRID_COLUMNS);
	SetCellMap(index % GRID_COLUMNS, index / GRID_COLUMNS, CELLTYPE_DUDE);

	DrawScreen(&context);

	SetCellMap(index % GRID_COLUMNS, index / GRID_COLUMNS, old);

StartEventLoop:
	if (!SDL_PollEvent(&event)) goto StartDraw;

	if (event.type == SDL_QUIT) goto EndEventLoop;
	
	if (event.type != SDL_KEYDOWN) goto PostKeyDownEvent;
	delta = 
		(SDLK_LEFT == event.key.keysym.sym) ? (-1) :
		(SDLK_RIGHT == event.key.keysym.sym) ? (1) :
		(SDLK_UP == event.key.keysym.sym) ? (-GRID_COLUMNS) :
		(SDLK_DOWN == event.key.keysym.sym) ? (GRID_COLUMNS) :
		(0);
	nextIndex = (index + delta) % (GRID_COUNT);
	
	index = (0 == GetCellMap(nextIndex % GRID_COLUMNS, nextIndex / GRID_COLUMNS)) ? (nextIndex) : (index);
PostKeyDownEvent:

	goto StartEventLoop;
EndEventLoop:

CleanUp:
	CleanUpContext(&context);
	return 0;
}
