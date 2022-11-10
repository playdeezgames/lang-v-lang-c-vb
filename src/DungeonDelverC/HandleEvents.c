#include "HandleEvents.h"
#include <SDL.h>
#include "Constants.h"
static void HandleKeyDown(struct World* world, char command)
{
}
static char ToCommand(SDL_KeyCode sym)
{
	return
		(sym == SDLK_LEFT) ? ('4') :
		(sym == SDLK_RIGHT) ? ('6') :
		(sym == SDLK_UP) ? ('8') :
		(sym == SDLK_DOWN) ? ('2') :
		(0);
}
int HandleEvents(struct World* world)
{
	static SDL_Event event = { 0 };
	for (;;)
		if (!SDL_PollEvent(&event)) return 1;
		else if (event.type == SDL_QUIT) return 0;
		else if (event.type == SDL_KEYDOWN) HandleKeyDown(world, ToCommand(event.key.keysym.sym));
}
