// https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/

#include <iostream>
using namespace std;

const int len = 10e6 + 1;

int seiveArr[len];
int primePrimeArr[len];

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
  cout << primePrimeArr[R] - primePrimeArr[L - 1] << "\n";
}

int main() {
  seiveArr[0] = seiveArr[1] = 0;
  for (int i = 2; i < len; i++) seiveArr[i] = 1;

  for (int i = 2; i * i <= len; i++)
    if (isPrime(i))
      for (int j = 2; i < len / j; j++) seiveArr[i * j] = 0;

  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (seiveArr[i]) cnt++;
    primePrimeArr[i] = seiveArr[cnt] ? 1 : 0;
  }

  for (int i = 1; i < len; i++) {
    /* code */
    primePrimeArr[i] += primePrimeArr[i - 1];
  }

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}