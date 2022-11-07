#include <SDL.h>
enum 
{
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720
};
int main(int argc, char** argv)
{
	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;
	if (0 == SDL_Init(SDL_INIT_EVERYTHING))
	{
		if (0 == SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer))
		{
			SDL_Event event = { 0 };
			for (;;)
			{
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
				SDL_WaitEvent(&event);
				if (SDL_QUIT == event.type)
				{
					break;
				}
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
		}
		SDL_Quit();
	}
	return 0;
}
