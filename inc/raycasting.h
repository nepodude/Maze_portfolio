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

/* Global variable declarations */
extern int map[MAP_HEIGHT][MAP_WIDTH];
extern float playerX;
extern float playerY;
extern float playerAngle;
extern SDL_Texture *wallTexture;
extern int texWidth;
extern int texHeight;

/* Function prototypes */
int loadMapFromFile(const char *filePath);
void loadWallTexture(SDL_Renderer *renderer);
void renderScene(SDL_Renderer *renderer);
void renderCeiling(SDL_Renderer *renderer);
void renderFloor(SDL_Renderer *renderer);
void processRay(int i, SDL_Rect *srcRect, SDL_Rect *destRect);
void renderWalls(SDL_Renderer *renderer);

#endif /* RAYCASTING_H */
