#include <SDL.h>
enum 
{
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720
};
int HandleCommand(char command)
{
	return '.'!=command;
}
int HandleKeyDown(SDL_KeyCode code)
{
	switch (code)
	{
	case SDLK_INSERT:
	case SDLK_KP_0:
	case SDLK_0:
		HandleCommand('0');
		break;
	case SDLK_END:
	case SDLK_KP_1:
	case SDLK_1:
		HandleCommand('1');
		break;
	case SDLK_DOWN:
	case SDLK_KP_2:
	case SDLK_2:
		HandleCommand('2');
		break;
	case SDLK_KP_3:
	case SDLK_3:
	case SDLK_PAGEDOWN:
		HandleCommand('3');
		break;
	case SDLK_KP_4:
	case SDLK_LEFT:
	case SDLK_4:
		HandleCommand('4');
		break;
	case SDLK_KP_5:
	case SDLK_5:
		HandleCommand('5');
		break;
	case SDLK_KP_6:
	case SDLK_6:
	case SDLK_RIGHT:
		HandleCommand('6');
		break;
	case SDLK_HOME:
	case SDLK_KP_7:
	case SDLK_7:
		HandleCommand('7');
		break;
	case SDLK_UP:
	case SDLK_KP_8:
	case SDLK_8:
		HandleCommand('8');
		break;
	case SDLK_KP_9:
	case SDLK_PAGEUP:
	case SDLK_9:
		HandleCommand('9');
		break;
	case SDLK_KP_PERIOD:
	case SDLK_PERIOD:
	case SDLK_DELETE:
		HandleCommand('.');
		break;
	default:
		return 1;
	}
}
int main(int argc, char** argv)
{
	if (0 == SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Window* window = 0;
		SDL_Renderer* renderer = 0;
		if (0 == SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer))
		{
			//initialize application
			SDL_Event event = { 0 };
			int running = 1;
			for (;running;)
			{
				SDL_RenderClear(renderer);
				//draw to renderer
				SDL_RenderPresent(renderer);
				if (1 == SDL_WaitEvent(&event))
				{
					switch (event.type)
					{
					case SDL_QUIT:
						running = 0;
						break;
					case SDL_KEYDOWN:
						running = HandleKeyDown(event.key.keysym.sym);
						break;
					}
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
