#include <SDL.h>
int Updater(char command);
void Initialize();
void Draw();
void CleanUp();
void Boilerplate_CleanUp(void(*)());
int Boilerplate_Initialize(void(*)());
void Boilerplate_Loop(int, void (*)(), int(*)(char));
int main(int argc, char** argv)
{
	Boilerplate_Loop(
		Boilerplate_Initialize(
			Initialize), 
		Draw, 
		Updater);
	Boilerplate_CleanUp(CleanUp);
	return 0;
}
