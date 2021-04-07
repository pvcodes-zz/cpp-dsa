#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void selectionSort(int A[], int n) {
  for (int i = 0; i < n-1; ++i) {
    int j, k;
    j = k = i;
    while (j < n) {
      if (A[j] < A[k]) {
        k = j;
      }
      j++;
    }
    swap(A[k], A[i]);
  }
}

int main()	{
  int A[] = {8, 5, 7, 3, 2};
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");

  selectionSort(A, 5);
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");

  return 0;
}