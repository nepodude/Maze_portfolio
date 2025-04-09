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

/* Function prototypes */

/*
 * loadMapFromFile - Parse the map file into the global map array.
 * @filePath: Path to the map file.
 * Return: 1 on success, 0 on failure.
 */
int loadMapFromFile(const char *filePath);

/*
 * loadWallTexture - Load the wall texture from a BMP file.
 * @renderer: Pointer to the SDL renderer.
 */
void loadWallTexture(SDL_Renderer *renderer);

/*
 * renderScene - Render the scene using raycasting.
 * @renderer: Pointer to the SDL renderer.
 */
void renderScene(SDL_Renderer *renderer);

#endif /* RAYCASTING_H */
