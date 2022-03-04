#include <stdio.h>
#include "data.h"

void printData(Data *data)
{
  printf("[");
  for (int i = 0; i < data->length; i++)
  {
    printf("%d", data->values[i]);
    if (i < data->length - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}