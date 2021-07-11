#include <iostream>
using namespace std;

#define SIZE 10

//using linear probing
class Hashing {
 private:
  int H[SIZE] {0};
 public:
  Hashing(int A[], int n) {
    for (int i = 0; i < n; ++i) {
      Insert(A[i]);
    }
  }

  int hash(int key) {
    return key % SIZE;
  }

  int probe(int index) {
    int i = 1;
    while (H[index + i] != 0)i++;
    return index;
  }


  void Insert(int key) {
    int h_index = hash(key);

    if (H[h_index] != 0) {
      h_index = probe(h_index);
    }
    H[h_index] = key;
  }


  void Display() {
    for (int i = 0; i < SIZE; ++i) {
      if (H[i] != 0)
        cout << H[i] << " ";
    }
  }
};

int main()	{
  int B[] = {43, 65, 70, 12};
  Hashing A(B, 4);
  A.Display();
  cout << "index of 70: " << A.hash(70);
  return 0;
}