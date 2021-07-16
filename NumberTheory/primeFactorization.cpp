#include <iostream>
using namespace std;

bool isPrime(int N) {
  for (int i = 2; i * i <= N; i++) {
    if (!(N % i)) {
      return false;
    }
  }
  return true;
}

void primeFactorBruteForce(int N) {
  for (int i = 2; i <= N; i++) {
    int cnt = 0;
    if (N % i == 0) {  // i.e, if n % i is 0
      while (N % i == 0) {
        cnt++;
        N /= i;
      }
      cout << i << "^" << cnt << " * ";
    }
  }
}

// CLAIM: All factor of a number lies below the sqrt of that number

void primeFactor(int N) {
  if (isPrime(N)) {
    cout << "1 * " << N << "\n";
  }
  for (int i = 2; i * i <= N; i++) {
    int cnt = 0;
    if (N % i == 0) {  // i.e, if n % i is 0
      while (N % i == 0) {
        cnt++;
        N /= i;
      }
      cout << i << "^" << cnt << " * ";
    }
  }
}

// Using seive it's time complexity would be O(log(N))
const int len = 10e6 + 1;
int seiveArr[len];
void seive() {
  for (auto &&i : seiveArr) i = -1;
  for (int i = 2; i < len; i++) {
    if (seiveArr[i] == -1) {
      for (int j = i; j <= len; j += i) {
        if (seiveArr[j] == -1) seiveArr[j] = i;
      }
    }
  }
}

void primeFactorUsingSeive(int N) {
  while (seiveArr[N] != 1) {
    cout << seiveArr[N] << " * ";
    N /= seiveArr[N];
  }
}

int main() {
  primeFactorBruteForce(100);
  cout << "\n";
  // primeFactor(100);
  primeFactorUsingSeive(100);
  return 0;
}