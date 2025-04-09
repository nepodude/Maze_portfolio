#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * renderFloor - Render the floor area.
 * @renderer: Pointer to the SDL renderer.
 */
void renderFloor(SDL_Renderer *renderer)
{
	SDL_Rect rect = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_SetRenderDrawColor(renderer, 33, 107, 1, 255);
	SDL_RenderFillRect(renderer, &rect);
}
