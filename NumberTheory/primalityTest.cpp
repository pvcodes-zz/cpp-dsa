#include <math.h>

#include <iostream>
using namespace std;

// Brute Force, with time complexity: O(n)
bool isPrimeBruteForce(int n) {
  if (n == 1) return 0;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return 0;
  return 1;
}

// CLAIM 1 : for any number 'N' the factor exist in pair for e.g:
// Factor of 12 are  = 1,2,3,4,6,12
// Pairs are: (1,12), (2,6), (3,4)

// CLAIM 2 : for every pair the one of the element lies below sqrt(N)

// Better Approach, with time complexity O(sqrt(n))
bool isPrimeBetterApproach(int n) {
  if (n == 1) return 0;
  int sqrtN = sqrt(n);
  for (int i = 2; i <= sqrtN; i++)
    if (n % i == 0) return 0;
  return 1;
}

int main() {
  cout << boolalpha << "using Brute Force, is 9 prime?  " << isPrimeBruteForce(9) << endl;
  cout << boolalpha << "using Better Approach, is 9 prime?  " << isPrimeBetterApproach(9) << endl;
  return 0;
}
