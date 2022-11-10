#ifndef ATLASROW_H
#define ATLASROW_H
#include "Board.h"
enum
{
	ATLAS_COLUMNS = 8
};
struct AtlasRow
{
	struct Board boards[ATLAS_COLUMNS];
};
void InitAtlasRow(struct AtlasRow*);
#endif
