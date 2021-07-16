// https://www.spoj.com/problems/TDKPRIME/

// Seive of Eratos means to pre-compute all the prime numbers in given range
// using the statement "if 'i' is prime then for sure it's multiple are not prime"

#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
  if (n == 1) return 0;
  int sqrtN = sqrt(n);
  for (int i = 2; i <= sqrtN; i++)
    if (n % i == 0) return 0;
  return 1;
}

// init with val 1
vector<bool> seiveArr(90000001, true);
vector<int> primeNums;

void solve() {
  int k;
  cin >> k;
  cout << primeNums[k - 1] << "\n";
}

int main() {
  int sqrt90000001 = sqrt(90000001);
  seiveArr[0] = seiveArr[1] = 0;
  for (int i = 2; i < sqrt90000001; i++) {
    if (isPrime(i)) {
      for (int j = 2; j < (90000001 / i); j++) {
        seiveArr[i * j] = 0;
      }
    }
  }
  for (int i = 0; i < 90000001; i++) {
    if (seiveArr[i]) {
      primeNums.push_back(i);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    solve();
  }

  return 0;
}