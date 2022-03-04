#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "data.h"
#include "draw.h"
#include "generateData.h"
#include "insertionSort.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 480

int main(int argc, char *args[])
{
  Data *data = generateData();

  srand(time(NULL));
  SDL_Window *window = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return -1;
  }

  window = SDL_CreateWindow("SDL Insertion Sort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return -1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  RenderProps renderProps;
  renderProps.renderer = renderer;
  renderProps.height = SCREEN_HEIGHT;
  renderProps.width = SCREEN_WIDTH;

  SDL_bool quit = SDL_FALSE;
  SDL_Event e;

  while (!quit)
  {
    while (SDL_PollEvent(&e) != 0)
    {
      // User requests quit
      if (e.type == SDL_QUIT)
      {
        quit = SDL_TRUE;
      }

      if (e.type == SDL_KEYUP)
      {
        switch (e.key.keysym.sym)
        {
        case SDLK_SPACE:
          insertionSort(data);
          break;
        default:
          break;
        }
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    draw(&renderProps, data);

    SDL_RenderPresent(renderer);
  }

  free(data->values);
  free(data);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}