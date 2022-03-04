#include "data.h"

typedef struct
{
  int width;
  int height;
  SDL_Renderer *renderer;
} RenderProps;

void draw(const RenderProps *renderProps, const Data *data);