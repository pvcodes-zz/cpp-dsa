#include "DLL.h"

#include <iostream>

Doubly_LinkedList::Doubly_LinkedList() : Head{NULL}, Tail{NULL} {}
Doubly_LinkedList::Doubly_LinkedList(int A[], int n) {
    D_Node *t, *ptr;
    Head = new D_Node;
    Head->data = A[0];
    Head->prev = NULL;
    Head->next = NULL;
    ptr = Head;

    for (int i = 1; i < n; i++) {
        t = new D_Node;
        t->data = A[i];
        ptr->next = t;
        t->prev = ptr;
        ptr = t;
    }
    Tail = ptr;
}
Doubly_LinkedList::~Doubly_LinkedList() {}

void Doubly_LinkedList::Display() {
    D_Node *ptr = Head;

    std::cout << "/ -> ";
    while (ptr) {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "/" << std::endl;
}

int Doubly_LinkedList::len() {
    D_Node *ptr = Head;
    int c{0};
    while (ptr) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void Doubly_LinkedList::Insert(int val, int index) {
    if (index <= 1) {
        push_front(val);
    } else {
        D_Node *ptr = Head;
        D_Node *tail_ptr{nullptr};
        for (int i = 0; i < index - 1; i++) {
            tail_ptr = ptr;
            ptr = ptr->next;
        }

        D_Node *t = new D_Node;
        t->data = val;
        tail_ptr->next = t;
        t->next = ptr;
        t->prev = tail_ptr;

        ptr->prev = t;
    }
}

void Doubly_LinkedList::push_front(int val) {
    D_Node *t = new D_Node;
    t->data = val;
    t->prev = NULL;
    t->next = Head;
    Head->prev = t;
    Head = t;
}

void Doubly_LinkedList::push_back(int val) {
    D_Node *t = new D_Node;
    t->data = val;
    t->next = NULL;
    Tail->next = t;
    t->prev = Tail;
    Tail = t;
}
void Doubly_LinkedList::pop_back() {
    D_Node *ptr = Head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    Tail = ptr->prev;
    delete ptr;
}

void Doubly_LinkedList::Delete(int index) {
    if (index <= 1) {
        D_Node *ptr = Head;
        Head = Head->next;
        Head->prev = NULL;
        delete ptr;
    } else if (index == this->len()) {
        pop_back();
    } else {
        D_Node *ptr = Head;
        D_Node *tail_ptr = nullptr;
        D_Node *tmp{nullptr};
        for (int i = 0; i < index - 1; i++) {
            tail_ptr = ptr;
            ptr = ptr->next;
        }
        tail_ptr->next = ptr->next;
        ptr->next->prev = tail_ptr;
        delete ptr;
    }
}

void Doubly_LinkedList::Reverse() {
    D_Node *ptr = Head;
    D_Node *t{nullptr};
    while (ptr) {
        t = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = t;
        ptr = ptr->prev;  // moving ahead
        if (!(ptr->next)) {
            ptr->next = ptr->prev;
            ptr->prev = NULL;

            D_Node *t1 = Head;
            Head = ptr;
            Tail = t1;
            break;
        }
    }
}
