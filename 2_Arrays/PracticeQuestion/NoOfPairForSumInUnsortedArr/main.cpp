// Find the possible pair whose sum is equal to the value get by input in an Unsorted Array
#include <iostream>

int Max(int A[], int l) {
    int m = A[0];
    for (int i = 1; i < l; i++) {
        if (m < A[i]) m = A[i];
    }
    return m;
}
void Solution(int A[], int l, int s) {
    int *H = new int[Max(A, l) + 1]();
    for (int i = 0; i < l; i++) {
        if (H[s - A[i]] > 0) {
            std::cout << "Required pair is: " << A[i] << " and " << s - A[i] << std::endl;
            H[A[i]]++;

        } else {
            H[A[i]]++;
        }
    }
}

int main() {
    int A[] = {10, 1, 5, 9, 7, 0};
    int l = 6;   // Length of Array
    int s = 10;  // Suppose we have taken it from user via cin
    Solution(A, l, s);

    return 0;
}