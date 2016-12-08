#include "Sort.h"

void Sort::insertSort(double arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    int j = i;
    while (j > 0 && arr[j] < arr[j -1]) // keep swapping until in correct position
    {
      double temp = arr[j];
      arr[j] = arr[j -1];
      arr[j - 1] = temp;
      j--;
    }
  }
}

void Sort::quickSort(double arr[], int first, int last)
{
  int i = first;
  int j = last;
  int pivot = arr[(first + last) / 2];

  while (i <= j) // partition
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      double temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }

  // recursion
  if (first < j)
    quickSort(arr, first, j);
  if (i < last)
    quickSort(arr, i, last);
}

void Sort::bubbleSort(double arr[], int size)
{
  int n = size;
  while(n != 0)
  {
    int newn = 0;
    for (int i = 1; i < size; ++i)
    {
      if (arr[i - 1] > arr[i])
      {
        double temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        newn = i;
      }
    }
    n = newn;
  }
}
