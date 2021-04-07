#include "DCLL.h"

#include <iostream>

#include "DCLL.h"

DoublyCircluar_LinkedList::DoublyCircluar_LinkedList() : Head{nullptr}, Tail{nullptr} {
    Head->prev = Tail;
    Head->next = Tail;
}
DoublyCircluar_LinkedList::DoublyCircluar_LinkedList(int A[], int n) {
    Head = new D_Node;
    Head->data = A[0];
    Head->next = nullptr;
    D_Node *t, *ptr;
    ptr = Head;
    for (int i = 1; i < n; i++) {
        t = new D_Node;
        t->data = A[i];
        ptr->next = t;
        t->prev = ptr;
        ptr = t;
        ptr->next = Head;
    }
    Head->prev = ptr;
    Tail = ptr;
}
DoublyCircluar_LinkedList::~DoublyCircluar_LinkedList() {}

void DoublyCircluar_LinkedList::Display() {
    D_Node *ptr = Head;
    do {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    } while (ptr != Head);
    std::cout << "/" << std::endl;
}

int DoublyCircluar_LinkedList::len() {
    int c{0};
    D_Node *ptr = Head;
    do {
        c++;
        ptr = ptr->next;
    } while (ptr != Head);
    return c;
}

void DoublyCircluar_LinkedList::push_front(int val) {
    D_Node *t = new D_Node;
    t->data = val;
    t->prev = Head->prev;
    t->next = Head;
    Head->prev->next = t;
    Head->prev = t;
    // t = Head;
    Head = t;
}
void DoublyCircluar_LinkedList::push_back(int val) {
    D_Node *t = new D_Node;
    t->data = val;
    Head->prev->next = t;
    t->prev = Head->prev;
    t->next = Head;
    Head->prev = t;
    Tail = t;
}
void DoublyCircluar_LinkedList::pop_front() {
    Head->prev->next = Head->next;
    D_Node *t = Head;
    Head->next->prev = Head->prev;
    Head = Head->next;
    delete t;
}
void DoublyCircluar_LinkedList::pop_back() {
    Head->prev->prev->next = Head;
    D_Node *t = Head->prev;
    Head->prev = Head->prev->prev;
    delete t;
}
void DoublyCircluar_LinkedList::Insert(int val, int index) {
    if (index <= 1) {
        push_front(val);
    } else if (index >= (this->len())) {
        push_back(val);
    } else {
        D_Node *t{nullptr}, *ptr{nullptr};
        t = new D_Node;
        t->data = val;
        ptr = Head;

        for (int i = 0; i < index - 1; i++) ptr = ptr->next;

        t->prev = ptr->prev;
        t->next = ptr;
        ptr->prev->next = t;
        ptr->prev = t;
    }
}
void DoublyCircluar_LinkedList::Delete(int index) {
    if (index <= 1) {
        /* code */ pop_front();
    } else if (index >= (this->len())) {
        pop_back();
    } else {
        D_Node *ptr = Head;

        for (int i = 0; i < index - 1; i++) ptr = ptr->next;

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
}