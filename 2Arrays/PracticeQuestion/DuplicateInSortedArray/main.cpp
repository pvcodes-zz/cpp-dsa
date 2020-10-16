// Find the number of duplicate in an sorted Array

#include <iostream>

void Solution(int A[], int l) {
    int R[l] = {0};
    int x{0};
    for (int i = 0; i < l; i++) {
        if (A[i] == A[i + 1]) {
            std::cout << A[i] << " is repeating" << std::endl;
        }
    }
}

int main() {
    int A[] = {1, 2, 2, 3, 4, 8};
    Solution(A, 6);
    return 0;
}