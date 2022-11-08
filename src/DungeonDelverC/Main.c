#include <SDL.h>
#include <stdio.h>
enum {
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720,
	LOGICAL_WIDTH = 640,
	LOGICAL_HEIGHT = 360
};
int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		fprintf(stderr,"%s", SDL_GetError());
		return -1;
	}
	else
	{
		SDL_Window* window = 0;
		SDL_Renderer* renderer = 0;
		if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer))
		{
			//TODO: what about the state of window and renderer?
			fprintf(stderr, "%s", SDL_GetError());
			return -1;
		}
		else
		{
			SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
			SDL_Event event = {0};
			int running = 1;
			do {
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
				if (SDL_PollEvent(&event))
				{
					running = event.type != SDL_QUIT;
				}
			} while (running);
		}
		if (renderer)
		{
			SDL_DestroyRenderer(renderer);
			renderer = 0;
		}
		if (window)
		{
			SDL_DestroyWindow(window);
			window = 0;
		}
		SDL_Quit();
	}
	return 0;
}
