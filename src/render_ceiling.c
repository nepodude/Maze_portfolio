#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * renderCeiling - Render the ceiling area.
 * @renderer: Pointer to the SDL renderer.
 */
void renderCeiling(SDL_Renderer *renderer)
{
	SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_SetRenderDrawColor(renderer, 70, 160, 242, 255);
	SDL_RenderFillRect(renderer, &rect);
}
