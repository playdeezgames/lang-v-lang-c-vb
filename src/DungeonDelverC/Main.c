#include <SDL.h> //needed for sdl main purposes!
#include "Boilerplate.h"
#include "Application.h"
int main(int argc, char** argv)
{
	struct Boilerplate* ptr = 0;
	Boilerplate_Loop(
		ptr,
		Boilerplate_Initialize(
			ptr,
			Application_Initialize),
		Application_Draw,
		Application_Updater);
	Boilerplate_CleanUp(ptr, Application_CleanUp);
	return 0;
}
