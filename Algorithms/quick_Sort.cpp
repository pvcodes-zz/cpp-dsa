#include <iostream>
using namespace std;


void quickSort(int *array, int low, int high) {
  int i = low;
  int j = high;
  int pivot = array[(i + j) / 2];
  int temp;

  while (i <= j) {
    while (array[i] < pivot)
      i++;
    while (array[j] > pivot)
      j--;
    if (i <= j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }
  if (j > low)
    quickSort(array, low, j);
  if (i < high)
    quickSort(array, i, high);
}

int main()	{
  int A[] = {8, 5, 7, 3, 2};
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");

  quickSort(A, 0, 5);
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");
  return 0;
}