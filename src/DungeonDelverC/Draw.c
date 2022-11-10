#include "Draw.h"
#include "Entity.h"
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "Map.h"
void DrawBoardCell(struct Context* context, struct BoardCell* boardCell, int gridRow, int gridColumn)
{
	int index = (boardCell->terrain.terrain_id == 0) ? (0x00) : (0xdb);
	SDL_RenderCopy(context->renderer, context->texture, GetSrcRect(index), GetDstRect(gridRow * GRID_COLUMNS + gridColumn));
}
void DrawBoardRow(struct Context* context, struct BoardRow* boardRow, int gridRow)
{
	for (int gridCell = 0; gridCell < BOARD_COLUMNS; ++gridCell) DrawBoardCell(context, &boardRow->cells[gridCell], gridRow, gridCell);
}
void Draw(struct Context* context, struct World* world)
{
	SDL_RenderClear(context->renderer);
	for (int gridRow = 0; gridRow < BOARD_ROWS; ++gridRow) DrawBoardRow(context, &world->atlas.rows[world->atlas_row].boards[world->atlas_column].rows[gridRow],gridRow);
	SDL_RenderPresent(context->renderer);
}
