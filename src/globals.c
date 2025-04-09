#include "raycasting.h"

/* Global variable definitions */
int map[MAP_HEIGHT][MAP_WIDTH];
float playerX = 3.5;
float playerY = 3.5;
float playerAngle = 1.0;
SDL_Texture *wallTexture = NULL;
int texWidth = 0;
int texHeight = 0;
