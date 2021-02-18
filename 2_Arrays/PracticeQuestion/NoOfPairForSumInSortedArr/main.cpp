// Find the possible pair whose sum is equal to the value get by input in an Sorted Array

#include <iostream>

void Solution(int A[], int len, int s) {
    int l = 0;
    int h = len - 1;
    while (l < h) {
        if (A[l] + A[h] == s) {
            std::cout << "Required pair is: " << A[l] << " and " << A[h] << std::endl;
            l++;
            h--;
        } else if (A[l] + A[h] < s) {
            l++;
        } else {  // if A[l] + A[h] >s
            h--;
        }
    }
}

int main() {
    int A[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    Solution(A, 10, 13);  // here 10 is len of array and 13 is the required sum 
    return 0;
}