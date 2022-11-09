#include "Entity.h"
struct Entity* LeaveEmptyBehind()
{
	return GetEntity(ENTITY_EMPTY);
}
static struct Entity entities[] =
{
	{0x00,{0x00,0x00,0x00,0xFF},0},
	{0xDB,{0x00,0x00,0xFF,0xFF},0},
	{0x02,{0xAA,0xAA,0xAA,0xFF},LeaveEmptyBehind}
};
struct Entity* GetEntity(int index)
{
	return entities + index;
}
int GetEntityId(struct Entity* entity)
{
	int result = (int)(entity - (entities + 0));
	return result;
}