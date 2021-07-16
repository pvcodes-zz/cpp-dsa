// https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/

#include <iostream>
using namespace std;

const int len = 10e6 + 1;

int A[len]{1};

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}

void solve() {
  int L, R;
  cin >> L >> R;
  cout << A[R] - A[L] << "\n";
}

int main() {
  A[0] = A[1] = 0;
  A[2] = 1;
  A[3] = 2;
  for (int i = 4; i <= len; i++) {
    if (isPrime(i)) {
      A[i] = A[i - 1] + 1;
    } else {
      A[i] = A[i - 1];
    }
  }

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}