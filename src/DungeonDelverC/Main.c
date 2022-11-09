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
#include "World.h"
int Init(struct Context* context, struct World* world)
{
	if (InitContext(context)) return 0;
	InitSrcRects();
	InitDstRects();
	InitCellMap();
	InitWorld(world);
	return 1;
}
int main(int argc, char** argv)
{
	struct Context context = { 0 };
	struct World world = { 0 };
	if (Init(&context, &world)) 
		do Draw(&context, &world); 
		while (HandleEvents(&world));
	CleanUpContext(&context);
	//TODO: clean up world when that is needful
	return 0;
}
