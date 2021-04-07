#include <iostream>

int expo(int m, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return expo(m * m, n / 2);
    return expo(m * m, n / 2) * m;
}

int main() {
    std::cout << "The val of 15^14 is : " << expo(15, 20) << std::endl;
    return 0;
}