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
	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;
	SDL_Event event = { 0 };

	if (SDL_Init(SDL_INIT_EVERYTHING)) goto PreinitializationFailure;

	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer)) goto PostInitializationFailure;

Draw:
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

HandleEvents:
	if (!SDL_PollEvent(&event)) goto Draw;

	if (event.type == SDL_QUIT) goto DestroyRenderer;

	goto Draw;

DestroyRenderer:
	if (!renderer) goto DestroyWindow;
	SDL_DestroyRenderer(renderer);

DestroyWindow:
	if (!window) goto CleanUpSDL;
	SDL_DestroyWindow(window);

CleanUpSDL:
	SDL_Quit();
	return 0;

PostInitializationFailure:
	SDL_Quit();

PreinitializationFailure:
	fprintf("%s", SDL_GetError());
	return -1;
}
