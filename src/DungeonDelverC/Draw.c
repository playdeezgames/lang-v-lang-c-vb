#include "Draw.h"
#include "Entity.h"
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "Map.h"
static struct Context* drawContext = 0;
static struct World* drawWorld = 0;
void SetDrawContext(struct Context* context)
{
	drawContext = context;
}
void SetDrawWorld(struct World* world)
{
	drawWorld = world;
}
void DrawBoardCell(int gridRow, int gridColumn)
{
	int terrain_id = drawWorld->atlas.rows[drawWorld->atlas_row].boards[drawWorld->atlas_column].rows[gridRow].cells[gridColumn].terrain.terrain_id;
	struct TerrainDescriptor* terrain_descriptor = GetTerrainDescriptor(terrain_id);
	SDL_SetTextureColorMod(drawContext->texture, terrain_descriptor->color.r, terrain_descriptor->color.g, terrain_descriptor->color.b);
	SDL_RenderCopy(drawContext->renderer, drawContext->texture, GetSrcRect(terrain_descriptor->character), GetDstRect(gridRow * GRID_COLUMNS + gridColumn));
}
void DrawBoardRow(int gridRow)
{
	for (int gridCell = 0; gridCell < BOARD_COLUMNS; ++gridCell) DrawBoardCell(gridRow, gridCell);
}
void Draw()
{
	SDL_RenderClear(drawContext->renderer);
	for (int gridRow = 0; gridRow < BOARD_ROWS; ++gridRow) DrawBoardRow(gridRow);
	SDL_RenderPresent(drawContext->renderer);
}
