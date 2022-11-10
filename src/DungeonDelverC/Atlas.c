#include "Atlas.h"
void InitAtlas(struct Atlas* atlas)
{
	for (int row = 0; row < ATLAS_ROWS; ++row) InitAtlasRow(atlas->rows + row);
}
