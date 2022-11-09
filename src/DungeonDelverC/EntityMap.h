#ifndef ENTITYMAP_H
#define ENTITYMAP_H
#include "Entity.h"
void InitEntityMap();
void SetEntityMap(int, int, struct Entity*);
struct Entity* GetEntityMap(int, int);
#endif
