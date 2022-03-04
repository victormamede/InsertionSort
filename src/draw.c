#include <SDL2/SDL.h>
#include "data.h"
#include "draw.h"

void drawValue(const RenderProps *renderProps, const Data *data, int index)
{
  float width = (float)renderProps->width / data->length;
  float scalingFunc = (float)renderProps->height / data->maxValue;

  int currentHeight = data->values[index] * scalingFunc;

  SDL_Rect rect;
  rect.x = width * index;
  rect.y = renderProps->height - currentHeight;
  rect.w = width;
  rect.h = currentHeight;

  if (index == data->currentIndex)
  {
    SDL_SetRenderDrawColor(renderProps->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  }
  else if (index == data->lastSwappedIndex)
  {
    SDL_SetRenderDrawColor(renderProps->renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
  }
  else
  {
    SDL_SetRenderDrawColor(renderProps->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  }
  SDL_RenderFillRect(renderProps->renderer, &rect);
  SDL_SetRenderDrawColor(renderProps->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawRect(renderProps->renderer, &rect);
}

void draw(const RenderProps *renderProps, const Data *data)
{

  for (int i = 0; i < data->length; i++)
  {
    drawValue(renderProps, data, i);
  }
}