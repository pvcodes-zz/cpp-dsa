#ifndef DCLL_H
#define DCLL_H

#include "DLL.h"

class DoublyCircluar_LinkedList {
   private:
    D_Node *Head;
    D_Node *Tail;

   public:
    DoublyCircluar_LinkedList();
    DoublyCircluar_LinkedList(int A[], int n);
    ~DoublyCircluar_LinkedList();

    void Display();
    int len();
    void push_front(int val);
    void push_back(int val);
    void pop_front();
    void pop_back();
    void Insert(int val, int index);
    void Delete(int index);
};
#endif  // DCLL_H