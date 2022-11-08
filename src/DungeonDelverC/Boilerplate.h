#ifndef BOILERPLATE_H
#define BOILERPLATE_H
#include <SDL.h>
struct Boilerplate;

struct Boilerplate* Boilerplate_Initialize();
void Boilerplate_CleanUp(struct Boilerplate**);

void Boilerplate_Loop(struct Boilerplate*);

#endif
