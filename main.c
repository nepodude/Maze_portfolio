#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "raycasting.h"

/*
 * main - Entry point of the raycasting program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Expects one argument: the path to the map file.
 * Initializes SDL, loads the map and texture, then enters the main loop.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	int running;
	const float moveSpeed = 0.05f;

	if (argc < 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!loadMapFromFile(argv[1]))
	{
		printf("Error loading map from file.\n");
		return (1);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return (1);
	}
	window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		SDL_DestroyWindow(window);
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	loadWallTexture(renderer);
	if (!wallTexture)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}
	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_RIGHT)
					playerAngle += 0.05;
				else if (event.key.keysym.sym == SDLK_LEFT)
					playerAngle -= 0.05;
				else if (event.key.keysym.sym == SDLK_w)
				{
					/* Separate collision check for sliding */
					float moveX = cos(playerAngle) * moveSpeed;
					float moveY = sin(playerAngle) * moveSpeed;
					if (map[(int)playerY][(int)(playerX + moveX)] == 0)
						playerX += moveX;
					if (map[(int)(playerY + moveY)][(int)playerX] == 0)
						playerY += moveY;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					float moveX = -cos(playerAngle) * moveSpeed;
					float moveY = -sin(playerAngle) * moveSpeed;
					if (map[(int)playerY][(int)(playerX + moveX)] == 0)
						playerX += moveX;
					if (map[(int)(playerY + moveY)][(int)playerX] == 0)
						playerY += moveY;
				}
				else if (event.key.keysym.sym == SDLK_a)
				{
					float moveX = cos(playerAngle - M_PI_2) * moveSpeed;
					float moveY = sin(playerAngle - M_PI_2) * moveSpeed;
					if (map[(int)playerY][(int)(playerX + moveX)] == 0)
						playerX += moveX;
					if (map[(int)(playerY + moveY)][(int)playerX] == 0)
						playerY += moveY;
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					float moveX = cos(playerAngle + M_PI_2) * moveSpeed;
					float moveY = sin(playerAngle + M_PI_2) * moveSpeed;
					if (map[(int)playerY][(int)(playerX + moveX)] == 0)
						playerX += moveX;
					if (map[(int)(playerY + moveY)][(int)playerX] == 0)
						playerY += moveY;
				}
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		renderScene(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(wallTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
