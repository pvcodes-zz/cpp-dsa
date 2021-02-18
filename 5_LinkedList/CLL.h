#ifndef CLL_H
#define CLL_H
#include "LL.h"  //including for only for to get struct of Node

// Class for Circular linked list
class Circular_LinkedList {
   private:
    Node *Head;

   public:
    Circular_LinkedList();
    Circular_LinkedList(int A[], int n);
    ~Circular_LinkedList();

    // Metḥods
    void Display();
    void Insert(int x, int n);
    void push_front(int a);
    void pop_front();
    void Delete(int index);
};

#endif  // CLL_H