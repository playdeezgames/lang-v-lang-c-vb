#include "Draw.h"
#include "Entity.h"
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "CellMap.h"
void DrawCell(struct Context* context, struct Entity* entity, int cell)
{
	SDL_SetTextureColorMod(context->texture, entity->color.r, entity->color.g, entity->color.b);
	SDL_RenderCopy(context->renderer, context->texture, GetSrcRect(entity->character), GetDstRect(cell));
}
void DrawCells(struct Context* context)
{
	for (int cell = 0; cell < GRID_COUNT; ++cell) DrawCell(context, GetEntity(GetCellMap(cell % GRID_COLUMNS, cell / GRID_COLUMNS)), cell);
}
void DrawScreen(struct Context* context)
{
	SDL_RenderClear(context->renderer);
	DrawCells(context);
	SDL_RenderPresent(context->renderer);
}
void BeforeDraw(struct World* world)
{
	GetEntity(ENTITY_DUDE)->old_entity = GetCellMap(world->index % GRID_COLUMNS, world->index / GRID_COLUMNS);
	SetCellMap(world->index % GRID_COLUMNS, world->index / GRID_COLUMNS, ENTITY_DUDE);
}
void AfterDraw(struct World* world)
{
	SetCellMap(world->index % GRID_COLUMNS, world->index / GRID_COLUMNS, GetEntity(ENTITY_DUDE)->old_entity);
}
void Draw(struct Context* context, struct World* world)
{
	BeforeDraw(world);
	DrawScreen(context);
	AfterDraw(world);
}
