#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
enum {
	ENTITY_EMPTY,
	ENTITY_WALL,
	ENTITY_DUDE,
	ENTITY_COUNT
};
struct Entity
{
	unsigned char character;
	SDL_Color color;
	struct Entity* (*leave_behind)();
};
struct Entity* GetEntity(int);
int GetEntityId(struct Entity*);
#endif