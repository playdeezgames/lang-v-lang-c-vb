#ifndef TERRAIN_H
#define TERRAIN_H
enum
{
	TERRAIN_EMPTY,
	TERRAIN_WALL,
	TERRAIN_COUNT
};
struct Terrain
{
	int terrain_id;
};
void InitTerrain(struct Terrain*);
#endif