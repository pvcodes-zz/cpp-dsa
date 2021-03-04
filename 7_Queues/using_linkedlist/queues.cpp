#include "queues.h"

#include <iostream>

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

Queue::~Queue() {
    Node *t = front;
    while (front) {
        front = ((front->next) ? (front->next) : NULL);
        delete t;
        t = front;
    }
}

void Queue::display() {
    Node *t = front;

    while (t) {
        std::cout << t->data << " <- ";
        t = t->next;
    }
    std::cout << "/" << std::endl;
}

void Queue::enqueue(int x) {
    Node *t = new Node;
    if (t == NULL) std::cout << "Queue is full" << std::endl;  // if the heap storage is full
    t->data = x;
    t->next = NULL;

    if (front == NULL) {  // is queue is empty
        rear = front = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

void Queue::dequeue() {
    if (front == NULL) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node *t = front;
    front = front->next;
    delete t;
}

int Queue::first() { return (front->data); }
int Queue::last() { return (rear->data); }