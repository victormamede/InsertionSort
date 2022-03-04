#include <stdbool.h>
#include "data.h"

bool insertionSort(Data *data)
{
  if (data->currentIndex >= data->length)
  {
    data->lastSwappedIndex = -1;
    return true;
  }

  int i;
  for (i = data->currentIndex; i > 0; i--)
  {
    if (data->values[i] > data->values[i - 1])
    {
      break;
    }

    int tmp = data->values[i - 1];
    data->values[i - 1] = data->values[i];
    data->values[i] = tmp;
    data->swapsMade++;
  }

  data->lastSwappedIndex = i;
  data->currentIndex++;
  return false;
}