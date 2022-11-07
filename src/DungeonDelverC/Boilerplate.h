#ifndef BOILERPLATE_H
#define BOILERPLATE_H
#include <SDL.h>
struct Boilerplate;
void Boilerplate_CleanUp(struct Boilerplate*, void(*)());
int Boilerplate_Initialize(struct Boilerplate*, void(*)());
void Boilerplate_Loop(struct Boilerplate*, int, void (*)(), int(*)(char));
#endif
