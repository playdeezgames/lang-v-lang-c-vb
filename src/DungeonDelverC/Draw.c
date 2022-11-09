#include "Draw.h"
#include "Entity.h"
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "Map.h"
void DrawCell(struct Context* context, struct Entity* entity, int cell)
{
	SDL_SetTextureColorMod(context->texture, entity->color.r, entity->color.g, entity->color.b);
	SDL_RenderCopy(context->renderer, context->texture, GetSrcRect(entity->character), GetDstRect(cell));
}
void DrawCells(struct Context* context)
{
	for (int cell = 0; cell < GRID_COUNT; ++cell) DrawCell(context, GetMapEntity(cell % GRID_COLUMNS, cell / GRID_COLUMNS), cell);
}
void DrawScreen(struct Context* context)
{
	SDL_RenderClear(context->renderer);
	DrawCells(context);
	SDL_RenderPresent(context->renderer);
}
void BeforeDraw(struct World* world)
{
}
void AfterDraw(struct World* world)
{
}
void Draw(struct Context* context, struct World* world)
{
	BeforeDraw(world);
	DrawScreen(context);
	AfterDraw(world);
}
