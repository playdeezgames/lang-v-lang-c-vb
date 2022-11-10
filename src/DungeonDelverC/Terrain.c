#include "Terrain.h"
void InitTerrain(struct Terrain* terrain)
{
	terrain->terrain_id = TERRAIN_EMPTY;
}
static struct TerrainDescriptor descriptors[TERRAIN_COUNT] =
{
	{0x00,{0x00,0x00,0x00,0xFF}},//TERRAIN_EMPTY
	{0xDB,{0x00,0x00,0xFF,0xFF}}//TERRAIN_WALL
};
struct TerrainDescriptor* GetTerrainDescriptor(int terrain_id)
{
	return descriptors + terrain_id;
}
