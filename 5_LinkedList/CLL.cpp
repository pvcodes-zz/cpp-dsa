#include "CLL.h"

#include <iostream>
Circular_LinkedList::Circular_LinkedList() : Head{NULL} { std::cout << "NULL" << std::endl; }

Circular_LinkedList::Circular_LinkedList(int A[], int n) {
    Head = new Node;
    //
    Head->data = A[0];
    Head->next = NULL;
    Node *ptr = Head;
    Node *tmp;
    for (int i = 1; i < n; i++) {
        tmp = new Node;
        tmp->data = A[i];
        tmp->next = NULL;
        ptr->next = tmp;
        ptr = tmp;
    }
    ptr->next = Head;
}

Circular_LinkedList::~Circular_LinkedList() {}

void Circular_LinkedList::Display() {
    Node *ptr = Head;
    do {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    } while (ptr != Head);

    std::cout << "NULL" << std::endl;
}

// Index start from 1. i.e, if you want to imsert a node before Head then function must be
// Insert(value_of_the_Node,0)
void Circular_LinkedList::Insert(int x, int n) {
    if (n == 0) {
        push_front(x);
    } else {
        Node *tmp = new Node;
        tmp->data = x;
        Node *ptr = Head;
        for (int i = 1; i < n - 1; i++) {
            ptr = ptr->next;
        }
        tmp->next = ptr->next;
        ptr->next = tmp;
        tmp = nullptr;
    }
}

void Circular_LinkedList::push_front(int a) {
    Node *tmp, *ptr;
    ptr = Head->next;
    while (ptr->next != Head) {
        ptr = ptr->next;
    }
    tmp = new Node;
    tmp->data = a;
    tmp->next = Head;
    ptr->next = tmp;
    Head = tmp;
}

void Circular_LinkedList::pop_front() {
    Node *ptr = Head;
    Node *t = Head;
    t = t->next;
    while (ptr->next != Head) {
        ptr = ptr->next;
    }
    ptr->next = t;
    Head = t;
}

void Circular_LinkedList::Delete(int index) {
    if (index == 1) {
        pop_front();
    } else {
        Node *ptr, *tail_ptr{nullptr};
        ptr = Head->next;
        for (int i = 0; i < index - 2; i++) {
            tail_ptr = ptr;
            ptr = ptr->next;
            if (!(ptr->next == Head)) {
                std::cout << "INVALID INDEX" << std::endl;
                return;
            }
        }
        tail_ptr->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
    }
}