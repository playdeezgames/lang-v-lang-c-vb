#ifndef CONSTANTS_H
#define CONSTANTS_H
enum {
	SCREEN_WIDTH = 1280,
	SCREEN_HEIGHT = 720,
	CELL_WIDTH = 16,
	CELL_HEIGHT = 16,
	LOGICAL_WIDTH = SCREEN_WIDTH / 2,
	LOGICAL_HEIGHT = SCREEN_HEIGHT / 2,
	GRID_COLUMNS = LOGICAL_WIDTH / CELL_WIDTH,
	GRID_ROWS = LOGICAL_HEIGHT / CELL_HEIGHT,
	GRID_COUNT = GRID_COLUMNS * GRID_ROWS
};
#endif