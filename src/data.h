#pragma once

typedef struct
{
  int *values;
  int length;
  int maxValue;
  int currentIndex;
  int lastSwappedIndex;
} Data;