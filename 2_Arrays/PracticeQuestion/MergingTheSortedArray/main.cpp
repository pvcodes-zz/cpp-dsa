#include <iostream>

int *Solution(int A[], int B[], int aLen, int bLen) {
    int *p = new int[aLen + bLen]();

    int i{0}, j{0}, k{0};
    while (i < aLen && j < bLen) {
        if (A[i] < B[j]) {
            p[k] = A[i];
            k++;
            i++;
        } else if (A[i] > B[j]) {
            p[k] = B[j];
            k++;
            j++;
        } else {  // if(A[i] == B[j])
            p[k] = A[i];
            p[k + 1] = B[j];
            k += 2;
            i++;
            j++;
        }
    }
    if (i == aLen)
        for (; j < bLen; j++, k++) p[k] = B[j];
    else if (j == bLen)
        for (; i < aLen; i++, k++) p[k] = A[i];
    return p;
}

int main() {
    int A[] = {1, 2, 3, 5, 8, 14};
    int B[] = {2, 7, 8, 10, 14};
    int a{6}, b{5};
    int *p = Solution(A, B, a, b);
    std::cout << p << std::endl;
    std::cout << "Elements are: ";
    for (int i = 0; i < a + b; i++) {
        std::cout << p[i] << " ";
    }
    return 0;
}