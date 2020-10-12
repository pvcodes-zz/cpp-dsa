#include <iostream>
// Taylor Series for e^x
// e^x = 1 + x + (x^2 / 2!) + (x^3 / 3!) + .... + (x^n / n!)
// As n increase the value e^x is more accurate

double taylorSeries(int x, int n) {
    // Here x is the power of 'e'
    // And n tells upto how much precison you want

    // Recursive Version via Horner's Rule
    static double s{0};
    if (n == 0) return s;
    s = 1 + (s * x / n);
    return taylorSeries(x, n - 1);

    // Iterative Version
    // static double s{0};
    // for(int i=n; i>0; i--){
    //     s = 1 + s*(x/i);
    // }
    // return s;
}

int main() {
    std::cout << taylorSeries(4, 15) << std::endl;
    return 0;
}