#ifndef APPLICATION_H
#define APPLICATION_H
#include "Globals.h"

struct Application;

struct Application* Application_Initialize(struct Globals*);
void Application_CleanUp(struct Application**);

void Application_Draw(struct Application*);
int Application_HandleCommand(struct Application*, char);

#endif
