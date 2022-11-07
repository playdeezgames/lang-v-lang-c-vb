#include <SDL.h>
SDL_Window* g_window = 0;
SDL_Renderer* g_renderer = 0;
enum
{
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720
};
int GetScreenWidth()
{
	return SCREEN_WIDTH;
}
int GetScreenHeight()
{
	return SCREEN_HEIGHT;
}
