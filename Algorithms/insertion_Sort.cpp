#include <iostream>
using namespace std;

void insertionSort(int A[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int x = A[i];
    while (j > -1 && A[j] > x) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
}

int main()	{
  // Code Here
  int A[] = {8, 5, 7, 3, 2};
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");

  insertionSort(A, 5);
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");


  return 0;
}