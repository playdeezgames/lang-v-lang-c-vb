#ifndef BOILERPLATE_H
#define BOILERPLATE_H
void Boilerplate_CleanUp(void(*)());
int Boilerplate_Initialize(void(*)());
void Boilerplate_Loop(int, void (*)(), int(*)(char));
#endif
