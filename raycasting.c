#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>

/* Screen and map constants */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define FOV 60.0
#define NUM_RAYS SCREEN_WIDTH

/* Global variables */
/* Global map array to be filled by the parser */
extern int map[MAP_HEIGHT][MAP_WIDTH];
/* Global player position and orientation */
extern float playerX;
extern float playerY;
extern float playerAngle;
/* Global wall texture pointer and texture dimensions */
extern SDL_Texture *wallTexture;
extern int texWidth;
extern int texHeight;

/* Function prototypes */

/* map_parser.c */
int loadMapFromFile(const char *filePath);

/* texture_loader.c */
void loadWallTexture(SDL_Renderer *renderer);

/* render_ceiling.c */
void renderCeiling(SDL_Renderer *renderer);

/* render_floor.c */
void renderFloor(SDL_Renderer *renderer);

/* render_walls.c */
void processRay(int i, SDL_Rect *srcRect, SDL_Rect *destRect);
void renderWalls(SDL_Renderer *renderer);

/* render_scene.c */
void renderScene(SDL_Renderer *renderer);

#endif /* RAYCASTING_H */
