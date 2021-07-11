#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void bubbleSort(int A[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
      }
    }
  }
}


//If at any time the list become sorted it will break from the outer loop
void bubbleSortImproved(int A[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    int isAlreadySorted = true; 			//
    for (int k = 0; k < n - i - 1; ++k) {
      if (A[k] > A[k + 1]) {
        swap(A[k], A[k + 1]);
        isAlreadySorted = false;
      }
    }
    if (isAlreadySorted) return; 			//
  }
}

int main() {
  int A[] = {8, 5, 7, 3, 2};
  int n = 5;
  for ( auto && i : A) {
    cout << i << " ";
  }
  puts("");
  bubbleSort(A, n);
  for ( auto && i : A) {
    cout << i << " ";
  }
  // puts("");
  return 0;
}

