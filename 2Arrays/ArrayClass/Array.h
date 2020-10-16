#ifndef ARRAY_H
#define ARRAY_H

class Array {
   private:
    int *p;
    int size;
    int length;
    void swap(int &a, int &b);

   public:
    Array();
    Array(int sz);
    ~Array();

    // Methods
    void Add();
    void Display();
    int Sum();
    int Max();
    int Min();
    int Avg();
    bool isSorted();
    void Insert(int index, int value);
    int getLength();
    int getSize();
    int *getPtrAddr();
    int BinarySearch(int value);
    void Reverse();
    void Append(int value);
    void LeftShift();
    void LeftRotate();
    void RightShift();
    void RightRotate();
    Array* Merge(Array A);
};
#endif  // ARRAY_H
