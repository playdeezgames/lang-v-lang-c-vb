#include "Globals.h"
#include "Boilerplate.h"
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
void Boilerplate_Loop(int running, void (*drawer)(SDL_Renderer*), int(*updater)(char))
{
	SDL_Event event = { 0 };
	for (; running;)
	{
		SDL_RenderClear(g_renderer);
		drawer(g_renderer);
		SDL_RenderPresent(g_renderer);
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
int Boilerplate_Initialize(void(*initializer)())
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
	{
		return 0;
	}
	int running = 0 == SDL_CreateWindowAndRenderer(GetScreenWidth(), GetScreenHeight(), 0, &g_window, &g_renderer);
	if (running)
	{
		initializer();
	}
	return running;
}
void Boilerplate_CleanUp(void(*cleaner)())
{
	cleaner();
	if (g_renderer)
	{
		SDL_DestroyRenderer(g_renderer);
		g_renderer = 0;
	}
	if (g_window)
	{
		SDL_DestroyWindow(g_window);
		g_window = 0;
	}
	SDL_Quit();
}
