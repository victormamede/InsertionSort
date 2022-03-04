#pragma once

typedef struct
{
  int *values;
  int length;
  int maxValue;
  int swapsMade;
  int currentIndex;
  int lastSwappedIndex;
} Data;

void printData(Data *data);