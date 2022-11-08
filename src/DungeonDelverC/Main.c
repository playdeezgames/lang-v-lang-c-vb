#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
enum {
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720,
	CELL_WIDTH = 16,
	CELL_HEIGHT = 16,

	LOGICAL_WIDTH = SCREEN_WIDTH / 2,
	LOGICAL_HEIGHT = SCREEN_HEIGHT / 2,
	GRID_COLUMNS = LOGICAL_WIDTH/ CELL_WIDTH,
	GRID_ROWS = LOGICAL_HEIGHT/CELL_HEIGHT,
	GRID_COUNT = GRID_COLUMNS * GRID_ROWS
};
enum {
	CELLTYPE_EMPTY,
	CELLTYPE_WALL,
	CELLTYPE_DUDE
};
extern SDL_Rect srcRects[];
extern SDL_Rect dstRects[];
extern unsigned char map[];
struct Cell
{
	unsigned char character;
	SDL_Color color;
};
struct Cell cellTypes[] =
{
	{0x00,{0x00,0x00,0x00,0xFF}},
	{0xDB,{0x00,0x00,0xFF,0xFF}},
	{0x02,{0xAA,0xAA,0xAA,0xFF}},
};
int main(int argc, char** argv)
{
	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;
	SDL_Event event = { 0 };
	SDL_Texture* texture = 0;
	unsigned char old;
	int index = GRID_COLUMNS/2 + (GRID_ROWS/2) * GRID_COLUMNS;
	int nextIndex = 0;
	int delta = 0;
	int cell = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING)) goto PreinitializationFailure;
	IMG_Init(IMG_INIT_PNG);
	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer)) goto PostInitializationFailure;
	SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
	texture = IMG_LoadTexture(renderer, "romfont8x8.png");

StartDraw:
	old = map[index];
	map[index] = CELLTYPE_DUDE;
	SDL_RenderClear(renderer);
	cell = 0;
StartRenderCell:
	if (GRID_COUNT == cell) goto EndRenderCell;
	SDL_SetTextureColorMod(texture, cellTypes[map[cell]].color.r, cellTypes[map[cell]].color.g, cellTypes[map[cell]].color.b);
	SDL_RenderCopy(renderer, texture, &srcRects[cellTypes[map[cell]].character], &dstRects[cell]);
	++cell;
	goto StartRenderCell;
EndRenderCell:
	SDL_RenderPresent(renderer);
	map[index] = old;

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

	index = (0 == map[nextIndex]) ? (nextIndex) : (index);
PostKeyDownEvent:


	goto StartEventLoop;
EndEventLoop:

	if (!texture) goto PostDestroyTexture;
	SDL_DestroyTexture(texture);
PostDestroyTexture:

	if (!renderer) goto PostDestroyRenderer;
	SDL_DestroyRenderer(renderer);
PostDestroyRenderer:

	if (!window) goto PostDestroyWindow;
	SDL_DestroyWindow(window);
PostDestroyWindow:

	IMG_Quit();
	SDL_Quit();
	return 0;

PostInitializationFailure:
	SDL_Quit();

PreinitializationFailure:
	fprintf(stderr, "%s", SDL_GetError());
	return -1;
}
