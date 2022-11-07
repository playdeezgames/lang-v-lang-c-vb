#include "Globals.h"
#include "Boilerplate.h"
struct Globals* Boilerplate_GetGlobals()
{
	return 0;
}
int HandleKeyDown(SDL_KeyCode code, int(*updater)(char))
{
	switch (code)
	{
	case SDLK_INSERT:
	case SDLK_KP_0:
	case SDLK_0:
		return updater('0');
	case SDLK_END:
	case SDLK_KP_1:
	case SDLK_1:
		return updater('1');
	case SDLK_DOWN:
	case SDLK_KP_2:
	case SDLK_2:
		return updater('2');
	case SDLK_KP_3:
	case SDLK_3:
	case SDLK_PAGEDOWN:
		return updater('3');
	case SDLK_KP_4:
	case SDLK_LEFT:
	case SDLK_4:
		return updater('4');
	case SDLK_KP_5:
	case SDLK_5:
		return updater('5');
	case SDLK_KP_6:
	case SDLK_6:
	case SDLK_RIGHT:
		return updater('6');
	case SDLK_HOME:
	case SDLK_KP_7:
	case SDLK_7:
		return updater('7');
	case SDLK_UP:
	case SDLK_KP_8:
	case SDLK_8:
		return updater('8');
	case SDLK_KP_9:
	case SDLK_PAGEUP:
	case SDLK_9:
		return updater('9');
	case SDLK_KP_PERIOD:
	case SDLK_PERIOD:
	case SDLK_DELETE:
		return updater('.');
	default:
		return 1;
	}
}
void Boilerplate_Loop(struct Boilerplate* ptr, int running, void (*drawer)(), int(*updater)(char))
{
	SDL_Event event = { 0 };
	for (; running;)
	{
		SDL_RenderClear(Globals_GetRenderer(Boilerplate_GetGlobals()));
		drawer();
		SDL_RenderPresent(Globals_GetRenderer(Boilerplate_GetGlobals()));
		while(running && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = 0;
				break;
			case SDL_KEYDOWN:
				running = HandleKeyDown(event.key.keysym.sym, updater);
				break;
			}
		}
	}
}
int Boilerplate_Initialize(struct Boilerplate* ptr, void(*initializer)())
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
	{
		return 0;
	}
	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;
	int running = 0 == SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	Globals_SetRenderer(Boilerplate_GetGlobals(), renderer);
	Globals_SetWindow(Boilerplate_GetGlobals(), window);
	if (running)
	{
		initializer();
	}
	return running;
}
void Boilerplate_CleanUp(struct Boilerplate* ptr, void(*cleaner)())
{
	cleaner();
	if (Globals_GetRenderer(Boilerplate_GetGlobals()))
	{
		SDL_DestroyRenderer(Globals_GetRenderer(Boilerplate_GetGlobals()));
		Globals_SetRenderer(Boilerplate_GetGlobals(), 0);
	}
	if (Globals_GetWindow(Boilerplate_GetGlobals()))
	{
		SDL_DestroyWindow(Globals_GetWindow(Boilerplate_GetGlobals()));
		Globals_SetWindow(Boilerplate_GetGlobals(), 0);
	}
	SDL_Quit();
}
