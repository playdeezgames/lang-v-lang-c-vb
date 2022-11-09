#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "CellMap.h"
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
struct CellType cellTypes[] =
{
	{0x00,{0x00,0x00,0x00,0xFF}},
	{0xDB,{0x00,0x00,0xFF,0xFF}},
	{0x02,{0xAA,0xAA,0xAA,0xFF}},
};
struct Context
{
	int sdl;
	int img;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};
int main(int argc, char** argv)
{
	struct Context context = { 0 };
	SDL_Renderer* renderer = 0;
	SDL_Event event = { 0 };
	SDL_Texture* texture = 0;
	unsigned char old;
	int index = GRID_COLUMNS/2 + (GRID_ROWS/2) * GRID_COLUMNS;
	int nextIndex = 0;
	int delta = 0;
	int cell = 0;
	struct CellType* cellType = 0;
	int initialized_sdl = 0;
	int initialized_img = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING)) goto CleanUp; else initialized_sdl = 1;
	IMG_Init(IMG_INIT_PNG), initialized_img = 1;
	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &context.window, &renderer)) goto CleanUp;
	SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
	texture = IMG_LoadTexture(renderer, "romfont8x8.png");
	InitSrcRects();
	InitDstRects();
	InitCellMap();


StartDraw:
	old = GetCellMap(index % GRID_COLUMNS, index/GRID_COLUMNS);
	SetCellMap(index % GRID_COLUMNS, index / GRID_COLUMNS, CELLTYPE_DUDE);
	SDL_RenderClear(renderer);
	cell = 0;
StartRenderCell:
	if (GRID_COUNT == cell) goto EndRenderCell;
	cellType = cellTypes + GetCellMap(cell % GRID_COLUMNS, cell / GRID_COLUMNS);
	SDL_SetTextureColorMod(texture, cellType->color.r, cellType->color.g, cellType->color.b);
	SDL_RenderCopy(renderer, texture, GetSrcRect(cellType->character), GetDstRect(cell));
	++cell;
	goto StartRenderCell;
EndRenderCell:
	SDL_RenderPresent(renderer);
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
	if (texture) SDL_DestroyTexture(texture), texture = 0;
	if (renderer) SDL_DestroyRenderer(renderer), renderer = 0;
	if (context.window) SDL_DestroyWindow(context.window), context.window = 0;
	if (initialized_img) IMG_Quit(), initialized_img = 0;
	if (initialized_sdl) SDL_Quit(), initialized_sdl = 0;
	return 0;
}
