// Q: given a interval [L,R], print all the prime number btw the interval
// (inclusive)
#include <iostream>
using namespace std;

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}

int main() {
  //
  int l, r;
  cin >> l >> r;

  for (; l <= r; l++) {
    if (isPrime(l)) cout << l << " ";
  }

  return 0;
}