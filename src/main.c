#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"
#include "generateData.h"
#include "insertionSort.h"

int main(int argc, char *args[])
{
  srand(time(NULL));
  Data *data = generateData();

  printf("Unordered list: ");
  printData(data);

  while (true)
  {
    if (insertionSort(data))
    {
      break;
    }
  }
  printf("Finished sorting with %d swaps\n", data->swapsMade);
  printf("Ordered list: ");
  printData(data);

  free(data->values);
  free(data);

  return 0;
}