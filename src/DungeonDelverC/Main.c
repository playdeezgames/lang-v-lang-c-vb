#include <SDL.h> //needed for sdl main purposes!
#include "Boilerplate.h"
int main(int argc, char** argv)
{
	struct Boilerplate* ptr = Boilerplate_Initialize();
	Boilerplate_Loop(ptr);
	Boilerplate_CleanUp(&ptr);
	return 0;
}
