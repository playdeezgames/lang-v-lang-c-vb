#include "Atlas.h"
void InitAtlas(struct Atlas* ptr)
{
	for (int row = 0; row < ATLAS_ROWS; ++row) InitAtlasRow(ptr->rows + row);
}
