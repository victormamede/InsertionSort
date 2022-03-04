#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define MAX_VALUE 1000

Data *generateData()
{
  int length;
  printf("Enter the amount of numbers to create: ");
  scanf("%d", &length);

  int *values = calloc(length, sizeof(int));

  for (int i = 0; i < length; i++)
  {
    values[i] = rand() % MAX_VALUE;
  }

  Data *toReturn = malloc(sizeof(Data));
  toReturn->maxValue = MAX_VALUE;
  toReturn->length = length;
  toReturn->values = values;
  toReturn->lastSwappedIndex = -1;
  toReturn->currentIndex = -1;
  toReturn->swapsMade = 0;

  return toReturn;
}