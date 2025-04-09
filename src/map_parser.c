#include <stdio.h>
#include <string.h>
#include "raycasting.h"

/* Global map array definition */
int map[MAP_HEIGHT][MAP_WIDTH];

/*
 * loadMapFromFile - Parse a map file into the global map array.
 * @filePath: Path to the map file.
 *
 * Expects MAP_HEIGHT lines with at least MAP_WIDTH characters each.
 * '#' or '1' indicates a wall; any other character is an empty cell.
 * Return: 1 on success, 0 on error.
 */
int loadMapFromFile(const char *filePath)
{
	FILE *file;
	char line[256];
	int row, col;

	file = fopen(filePath, "r");
	if (!file)
	{
		printf("Error: Could not open map file '%s'\n", filePath);
		return (0);
	}
	row = 0;
	while (fgets(line, sizeof(line), file) && row < MAP_HEIGHT)
	{
		line[strcspn(line, "\r\n")] = '\0';
		if ((int)strlen(line) < MAP_WIDTH)
		{
			printf("Error: Line %d too short.\n", row + 1);
			fclose(file);
			return (0);
		}
		for (col = 0; col < MAP_WIDTH; col++)
			map[row][col] = (line[col] == '#' || line[col] == '1') ? 1 : 0;
		row++;
	}
	fclose(file);
	if (row < MAP_HEIGHT)
	{
		printf("Error: Map file has %d rows; expected %d.\n", row, MAP_HEIGHT);
		return (0);
	}
	return (1);
}
