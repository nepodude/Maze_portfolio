#include <SDL2/SDL.h>
#include <math.h>
#include "raycasting.h"

/*
 * processRay - Process a single ray to compute source and destination
 * rectangles for texture mapping.
 * @i: The current column index (ray).
 * @srcRect: Pointer to the SDL_Rect for the texture source.
 * @destRect: Pointer to the SDL_Rect for the destination on screen.
 */
void processRay(int i, SDL_Rect *srcRect, SDL_Rect *destRect)
{
	int mapX, mapY, textureX;
	float rayAngle, rayX, rayY;
	float deltaX, deltaY;
	float distance, correctedDistance, wallHeight;
	float hitOffsetX, hitOffsetY, distToVertical, distToHorizontal;

	rayAngle = (playerAngle - (FOV / 2.0) * (M_PI / 180.0))
		   + (i * (FOV / SCREEN_WIDTH) * (M_PI / 180.0));
	rayX = playerX;
	rayY = playerY;
	deltaX = cos(rayAngle) * 0.001;
	deltaY = sin(rayAngle) * 0.001;
	while (1)
	{
		mapX = (int)rayX;
		mapY = (int)rayY;
		if (map[mapY][mapX] == 1)
			break;
		rayX += deltaX;
		rayY += deltaY;
	}
	distance = sqrtf((rayX - playerX) * (rayX - playerX) +
			 (rayY - playerY) * (rayY - playerY));
	correctedDistance = distance * cos(rayAngle - playerAngle);
	wallHeight = (1.0 / correctedDistance) * 300;
	if (wallHeight > SCREEN_HEIGHT)
		wallHeight = SCREEN_HEIGHT;
	mapX = (int)rayX;
	mapY = (int)rayY;
	hitOffsetX = rayX - mapX;
	hitOffsetY = rayY - mapY;
	distToVertical = fmin(hitOffsetX, 1.0 - hitOffsetX);
	distToHorizontal = fmin(hitOffsetY, 1.0 - hitOffsetY);
	if (distToVertical < distToHorizontal)
		textureX = (int)(hitOffsetX * texWidth);
	else
		textureX = (int)(hitOffsetY * texWidth);
	srcRect->x = textureX;
	srcRect->y = 0;
	srcRect->w = 1;
	srcRect->h = texHeight;
	destRect->x = i;
	destRect->y = (SCREEN_HEIGHT / 2) - ((int)wallHeight / 2);
	destRect->w = 1;
	destRect->h = (int)wallHeight;
	if (distToVertical < distToHorizontal)
		SDL_SetTextureColorMod(wallTexture, 255, 255, 255);
	else
		SDL_SetTextureColorMod(wallTexture, 130, 130, 130);
}

/*
 * renderWalls - Render the walls by processing each ray.
 * @renderer: Pointer to the SDL renderer.
 */
void renderWalls(SDL_Renderer *renderer)
{
	int i;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	for (i = 0; i < NUM_RAYS; i++)
	{
		processRay(i, &srcRect, &destRect);
		SDL_RenderCopy(renderer, wallTexture, &srcRect, &destRect);
	}
}
