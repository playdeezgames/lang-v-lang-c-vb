#ifndef TERRAIN_H
#define TERRAIN_H
#include <SDL.h>
enum
{
	TERRAIN_EMPTY,
	TERRAIN_WALL,
	TERRAIN_COUNT
};
struct TerrainDescriptor
{
	int character;
	SDL_Color color;
};
struct Terrain
{
	int terrain_id;
};
void InitTerrain(struct Terrain*);
struct TerrainDescriptor* GetTerrainDescriptor(int);
#endif