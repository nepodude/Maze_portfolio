#include <stdio.h>
#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * loadWallTexture - Load the wall texture from "wall.bmp".
 * @renderer: Pointer to the SDL renderer.
 *
 * Tries to load "wall.bmp". If not found, creates a fallback 64x64 grey texture.
 */
void loadWallTexture(SDL_Renderer *renderer)
{
	SDL_Surface *surface;

	surface = SDL_LoadBMP("wall.bmp");
	if (!surface)
	{
		printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		printf("wall.bmp not found. Generating fallback texture.\n");
		texWidth = 64;
		texHeight = 64;
		surface = SDL_CreateRGBSurface(0, texWidth, texHeight, 32,
			0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
		if (!surface)
		{
			printf("SDL_CreateRGBSurface Error: %s\n", SDL_GetError());
			return;
		}
		SDL_FillRect(surface, NULL,
			SDL_MapRGBA(surface->format, 150, 150, 150, 255));
	}
	else
	{
		texWidth = surface->w;
		texHeight = surface->h;
	}
	wallTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}
