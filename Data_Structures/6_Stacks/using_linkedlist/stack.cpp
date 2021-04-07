#include "stack.h"

#include <iostream>

Stack::Stack() : Top{nullptr}, Size{0} {}

Stack::Stack(int A[], int n) {
    Top = new Node;
    Top->data = A[0];
    Top->next = nullptr;
    for (int i = 1; i < n; i++) {
        push(A[i]);
    }
    Size = n;
}

Stack::~Stack() {
    if (Top) {
        Node *t = Top;
        Top = Top->next;
        while (Top) {
            delete t;
            t = Top;
            Top = Top->next;
        }
    }
}

// Methods

void Stack::push(int val) {
    if (Size == 0) {
        Top = new Node;
        Top->data = val;
        Top->next = nullptr;
    } else {
        Node *t = new Node;
        t->data = val;
        t->next = Top;
        Top = t;
    }
    Size++;
}

// ---------------------------------------------------------
// Auxillary function

void n_Display(Node *ptr) {
    if (ptr) {
        n_Display(ptr->next);
        std::cout << ptr->data << " <- ";
    }
    return;
}
// ---------------------------------------------------------

void Stack::display() {
    Node *ptr = Top;
    std::cout << "/ <- ";
    n_Display(ptr);
    puts("");
}

bool Stack::isEmpty() { return ((Size == 0) ? 1 : 0); }

void Stack::pop() {
    if (!(isEmpty())) {
        Node *t = Top;
        Top = Top->next;
        delete t;
        Size--;
    } else {
        std::cout << "Not yet Init" << std::endl;
    }
}

int Stack::peek(int index) {
    if (Top && index <= Size) {
        Node *ptr = Top;

        for (int i = 0; i < index - 1; i++) {
            ptr = ptr->next;
        }
        return (ptr->data);
    }
    std::cout << "Not yet init ";
    return -1;
}

int Stack::stack_top() {
    if (!Top) {
        std::cout << "Not yet init" << std::endl;
        return -1;
    }

    return (Top->data);
}

int Stack::get_Size() { return Size; }
