// Evalute the min and max element of an array in single scan

#include <iostream>

void Solution(int A[], int l) {
    int min = A[0];
    int max = A[0];
    for (int i = 1; i < l; i++) {
        if (min > A[i])
            min = A[i];
        else if (max < A[i])
            max = A[i];
    }
    std::cout << "Min Element is: " << min << std::endl;
    std::cout << "Max Element is: " << max << std::endl;
}

int main() {
    int A[] = {1, 45, 7, 85, 15, 120, -1, 482, 0, -99};
    Solution(A, 10);  // 10 is the length of this array
    return 0;
}