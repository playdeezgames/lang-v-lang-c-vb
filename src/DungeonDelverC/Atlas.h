#ifndef ATLAS_H
#define ATLAS_H
#include "AtlasRow.h"
enum
{
	ATLAS_ROWS = 8
};
struct Atlas
{
	struct AtlasRow rows[ATLAS_ROWS];
};
void InitAtlas(struct Atlas*);
#endif