#ifndef WORLD_H
#define WORLD_H
struct World
{
	int entityId;
	int column;
	int row;
};
void InitWorld(struct World*);
#endif
