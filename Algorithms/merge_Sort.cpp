#include <iostream>
using namespace std;

// this sorts, two half sorted array where index 0 to mid is sorted and mid+1 to high/last index is sorted
void merge(int A[], int l, int mid, int h) {
  int i = l, j = mid + 1, k = l;
  int B[100];
  while (i <= mid && j <= h) {
    if (A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }
  for (; i <= mid; i++)
    B[k++] = A[i];
  for (; j <= h; j++)
    B[k++] = A[j];
  for (i = l; i <= h; i++)
    A[i] = B[i];
}

//Iterative Merge Sort
void IterativeMergeSort(int A[], int n) {
  int p, l, h, mid, i;
  for (p = 2; p <= n; p = p * 2) {
    for (i = 0; i + p - 1 < n; i = i + p) {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2;  merge(A, l, mid, h);
    }
    if (n - i > p / 2) {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2;
      merge(A, l, mid, n - 1);
    }
  }
  if (p / 2 < n) {
    merge(A, 0, p / 2 - 1, n - 1);
  }
}


// Recursive Merge Sort
void RecursiveMergeSort(int A[], int low, int high) {
  if (low < high) {
    // Calculate mid point
    int mid = low + (high - low) / 2;

    // Sort sub-lists
    RecursiveMergeSort(A, low, mid);
    RecursiveMergeSort(A, mid + 1, high);

    // Merge sorted sub-lists
    merge(A, low, mid, high);
  }
}

int main() {

  int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
  int n = sizeof(A) / sizeof(A[0]);

  IterativeMergeSort(A, n);
  RecursiveMergeSort(A, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
  puts("");
  return 0;
}