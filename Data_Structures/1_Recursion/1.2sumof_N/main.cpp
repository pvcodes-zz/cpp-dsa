// Summation terms from 0 to n
#include <iostream>

int sum_of_n_term(int n) { return n * (n - 1) / 2; }

int main() {
    int a;
    std::cin >> a;
    std::cout << sum_of_n_term(a) << std::endl;
    return 0;
}