#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;
};

class Stack {
   private:
    Node* Top;
    int Size;

   public:
    Stack();
    Stack(int A[], int n);
    ~Stack();

    // Methods
    void push(int val);
    void display();
    bool isEmpty();
    void pop();
    int peek(int index);
    int stack_top();
    int get_Size();
};
#endif  // STACK_H