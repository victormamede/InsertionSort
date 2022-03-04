#include "data.h"

void insertionSort(Data *data)
{
  if (data->currentIndex >= data->length)
  {
    data->currentIndex = -1;
    data->lastSwappedIndex = -1;
    return;
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
  }

  data->lastSwappedIndex = i;
  data->currentIndex++;
}