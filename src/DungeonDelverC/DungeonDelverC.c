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
			//initialize application
			SDL_Event event = { 0 };
			for (;;)
			{
				SDL_RenderClear(renderer);
				//draw to renderer
				SDL_RenderPresent(renderer);
				if (1 == SDL_WaitEvent(&event))
				{
					if (SDL_QUIT == event.type)
					{
						break;
					}
					//handle event
				}
			}
			//clean up application
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
