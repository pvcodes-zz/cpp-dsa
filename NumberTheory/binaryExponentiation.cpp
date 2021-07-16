#include <iostream>
using namespace std;

// Time Complexity is O(N)
int powerBruteForce(int N, int base) {
  int res{1};
  for (int i = 0; i < base; i++) {
    res *= N;
  }
  return res;
}

// Exponentiation by squaring, it's time complexity is O(log(N))
int power(int N, int base) {
  int res = 1;
  while (base) {   // i.e., while N is not zero
    if (base & 1)  // if N is odd
      res *= N, base--;
    else
      N *= N, base /= 2;
  }
  return res;
}

int main() {
  cout << power(7, 3) << "\n";
  return 0;
}