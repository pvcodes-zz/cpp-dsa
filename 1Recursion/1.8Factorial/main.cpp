#include <iostream>

int factorial(int n) {
    if (n <= 1) return n;
    return n * factorial(n - 1);
}

int main() {
    std::cout << factorial(5) << std::endl;
    int a[5] = {1, 2, 3, 4, 5};
    std::cout << *(a + 2) << std::endl;
    int **p;
    p = new int *[3];
    for (int i = 0; i < 3; i++) p[i] = new int[4];
    std::cout << p << std::endl;
    std::cout << p+1 << std::endl;
    std::cout << p + 2 << std::endl;

    return 0;
}