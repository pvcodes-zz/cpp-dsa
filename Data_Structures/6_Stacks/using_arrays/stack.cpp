#include "stack.h"

#include <iostream>

Stack::Stack() : Top{-1}, Size{0} { A = new int[10]; }
Stack::Stack(int A[], int n) {
    this->A = new int[n];
    this->A = A;
    this->Size = n;
    this->Top = n - 1;
}
Stack::~Stack() {}

void Stack::display() {
    for (int i = Size - 1; i >= 0; i--) {
        std::cout << this->A[i] << std::endl;
    }
}
bool Stack::isEmpty() { return ((this->Top == -1) ? 1 : 0); }
bool Stack::isFull() { return ((this->Top == this->Size - 1) ? 1 : 0); }
void Stack::push(int val) {
    if (isFull()) {
        std::cout << "Stack Overflow" << std::endl;
    } else {
        this->A[++Top] = val;
    }
}
void Stack::pop() {
    if (isEmpty()) {
        /* code */ std::cout << "STack Underflow" << std::endl;
    } else {
        A[Top] = 0;
        Top--;
    }
}
int Stack::peek(int index) { return (A[Top - index]); }
int Stack::stack_top() { return A[Top]; }