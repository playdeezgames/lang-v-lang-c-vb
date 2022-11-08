#include "Globals.h"
#include "Boilerplate.h"
#include "Application.h"
struct Boilerplate
{
	int running;
	struct Globals* globals;
	struct Application* application;
};
struct Globals* Boilerplate_GetGlobals(struct Boilerplate* ptr)
{
	return ptr->globals;
}
struct Application* Boilerplate_GetApplication(struct Boilerplate* ptr)
{
	return ptr->application;
}
static char Boilerplate_GetCommand(SDL_KeyCode code)
{
	switch (code)
	{
	case SDLK_INSERT:
	case SDLK_KP_0:
	case SDLK_0:
		return '0';
	case SDLK_END:
	case SDLK_KP_1:
	case SDLK_1:
		return '1';
	case SDLK_DOWN:
	case SDLK_KP_2:
	case SDLK_2:
		return '2';
	case SDLK_KP_3:
	case SDLK_3:
	case SDLK_PAGEDOWN:
		return '3';
	case SDLK_KP_4:
	case SDLK_LEFT:
	case SDLK_4:
		return '4';
	case SDLK_KP_5:
	case SDLK_5:
		return '5';
	case SDLK_KP_6:
	case SDLK_6:
	case SDLK_RIGHT:
		return '6';
	case SDLK_HOME:
	case SDLK_KP_7:
	case SDLK_7:
		return '7';
	case SDLK_UP:
	case SDLK_KP_8:
	case SDLK_8:
		return '8';
	case SDLK_KP_9:
	case SDLK_PAGEUP:
	case SDLK_9:
		return '9';
	case SDLK_KP_PERIOD:
	case SDLK_PERIOD:
	case SDLK_DELETE:
		return '.';
	default:
		return 0;
	}
}
void Boilerplate_Loop(struct Boilerplate* ptr)
{
	SDL_Event event = { 0 };
	for (;ptr->running;)
	{
		SDL_RenderClear(Globals_GetRenderer(Boilerplate_GetGlobals(ptr)));
		Application_Draw(Boilerplate_GetApplication(ptr));
		SDL_RenderPresent(Globals_GetRenderer(Boilerplate_GetGlobals(ptr)));
		while(ptr->running && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				ptr->running = 0;
				break;
			case SDL_KEYDOWN:
				ptr->running = Application_HandleCommand(ptr->application, Boilerplate_GetCommand(event.key.keysym.sym));
				break;
			}
		}
	}
}
struct Boilerplate* Boilerplate_Initialize()
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
	{
		return 0;
	}
	struct Boilerplate* ptr = SDL_malloc(sizeof(struct Boilerplate));
	SDL_memset(ptr, 0, sizeof(struct Boilerplate));
	ptr->globals = Globals_Initialize();

	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;
	int running = 0 == SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	Globals_SetRenderer(ptr->globals, renderer);
	Globals_SetWindow(ptr->globals, window);
	ptr->application = Application_Initialize(ptr->globals);
	ptr->running = 1;
	return ptr;
}
void Boilerplate_CleanUp(struct Boilerplate** ptr)
{
	Application_CleanUp(&(*ptr)->application);
	if (Globals_GetRenderer(Boilerplate_GetGlobals(*ptr)))
	{
		SDL_DestroyRenderer(Globals_GetRenderer(Boilerplate_GetGlobals(*ptr)));
		Globals_SetRenderer(Boilerplate_GetGlobals(*ptr), 0);
	}
	if (Globals_GetWindow(Boilerplate_GetGlobals(*ptr)))
	{
		SDL_DestroyWindow(Globals_GetWindow(Boilerplate_GetGlobals(*ptr)));
		Globals_SetWindow(Boilerplate_GetGlobals(*ptr), 0);
	}
	Globals_CleanUp(&(*ptr)->globals);
	SDL_Quit();
}
