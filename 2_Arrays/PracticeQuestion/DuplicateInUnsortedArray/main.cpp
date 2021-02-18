// Find the duplicate in an Unsorted Array

#include <iostream>

int Max(int A[], int l) {
    int m = A[0];
    for (int i = 1; i < l; i++) {
        if (m < A[i]) m = A[i];
    }
    return m;
}

void solution(int A[], int l) {
    int n = Max(A, l) + 1;
    int *H = new int[n]();

    for (int i = 0; i < l; i++) {
        H[A[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (H[i] > 1) {
            std::cout << i << " is reapting " << H[i] << " times" << std::endl;
        } else {
        }
    }
    delete[] H;
}
int main() {
    int TestCase[] = {1, 2, 1, 1, 5, 8, 7, 8};
    int l = sizeof(TestCase) / sizeof(TestCase[0]);
    solution(TestCase, l);

    return 0;
}