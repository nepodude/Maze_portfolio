#include "raycasting.h"
#include <SDL2/SDL.h>

/*
 * renderScene - Render the complete scene.
 * @renderer: Pointer to the SDL renderer.
 *
 * Calls the ceiling, floor, and wall rendering functions.
 */
void renderScene(SDL_Renderer *renderer)
{
	renderCeiling(renderer);
	renderFloor(renderer);
	renderWalls(renderer);
}
