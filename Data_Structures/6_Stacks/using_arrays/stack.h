#ifndef STACK_H
#define STACK_H

class Stack {
   private:
    int Top;
    int *A;
    int Size;

   public:
    Stack();
    Stack(int A[], int n);
    ~Stack();

    // Methods
    void display();
    bool isEmpty();
    bool isFull();
    void push(int val);
    void pop();
    int peek(int index);
    int stack_top();
};
#endif  // STACK_H