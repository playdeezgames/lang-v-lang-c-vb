#include <SDL.h> //needed for sdl main purposes!
#include "Boilerplate.h"
#include "Application.h"
int main(int argc, char** argv)
{
	Boilerplate_Loop(
		Boilerplate_Initialize(
			Application_Initialize),
		Application_Draw,
		Application_Updater);
	Boilerplate_CleanUp(Application_CleanUp);
	return 0;
}
