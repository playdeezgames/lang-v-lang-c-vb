#ifndef ENTITYMAP_H
#define ENTITYMAP_H
#include "Entity.h"
void InitMap();
void SetMapEntity(int, int, struct Entity*);
struct Entity* GetMapEntity(int, int);
#endif
