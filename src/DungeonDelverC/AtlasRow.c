#include "AtlasRow.h"
void InitAtlasRow(struct AtlasRow* row)
{
	for (int column = 0; column < ATLAS_COLUMNS; ++column) InitBoard(row->boards + column);
}