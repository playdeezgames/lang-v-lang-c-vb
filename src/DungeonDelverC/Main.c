#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Constants.h"
#include "SrcRects.h"
#include "DstRects.h"
#include "Map.h"
#include "Context.h"
#include "Entity.h"
#include "Draw.h"
#include "HandleEvents.h"
#include "World.h"

static struct Context context = { 0 };
static struct World world = { 0 };
int Init()
{
	if (InitContext(&context)) return 0;
	InitSrcRects();
	InitDstRects();
	InitMap();
	InitWorld(&world);
	SetDrawContext(&context);
	SetDrawWorld(&world);
	return 1;
}
int main(int argc, char** argv)
{
	if (Init()) 
		do Draw(); 
		while (HandleEvents(&world));
	CleanUpContext(&context);
	//TODO: clean up world when that is needful
	return 0;
}
