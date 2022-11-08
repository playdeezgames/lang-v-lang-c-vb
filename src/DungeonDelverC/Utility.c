#include "Utility.h"
#include <SDL.h>
void* Utility_Allocate(int size)
{
	void* ptr = SDL_malloc(size);
	SDL_memset(ptr, 0, size);
	return ptr;
}
void Utility_free(void** ptr)
{
	if (ptr && *ptr)
	{
		SDL_free(*ptr);
		*ptr = 0;
	}
}
