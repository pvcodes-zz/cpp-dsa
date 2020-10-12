#include <iostream>

// For memoization for the values of series else it will be taking order on 2^n
// time complexity
static int arr[100];

int fib(int n) {
    if ((n <= 1)) {
        arr[n] = n;
        return n;
    } else {
        if (arr[n - 1] == -1) arr[n - 1] = fib(n - 1);
        if (arr[n - 2] == -1) arr[n - 2] = fib(n - 2);
        return (fib(n - 1) + fib(n - 2));
    }
}

int main() {
    for (auto &i : arr) i = -1;
    std::cout << fib(5) << std::endl;
    return 0;
}