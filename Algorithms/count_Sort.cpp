#include <iostream>
using namespace std;

int max(int A[], int n) {
  int max = A[0];
  for (int i = 1; i < n; ++i) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  cout << max << endl;
  return max;
}

void countSort(int A[], int n) {
  int t = max(A, n);
  int *H  = new int[t + 1] {0};
  for (int i = 0; i < n; ++i) {
    H[A[i]]++;
  }
  int j = 0;
  for (int i = 0; i < t; ++i) {
    while (H[i] > 0) {
      A[j++] = i;
      H[i]--;
    }
  }
}

int main()	{
  //
  int A[] = {3, 2, 5, 7, 1, 1};
  countSort(A, 6);
  for (auto i : A) {
    cout << i << " ";
  }
  puts("");
  return 0;
}