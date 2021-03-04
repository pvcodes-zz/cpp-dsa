#include "DEQueue.h"

#include <iostream>

DEQueue::DEQueue() : front{NULL}, rear{NULL} {}
DEQueue::~DEQueue() {
    Node *t = front;
    while (front) {
        front = ((front->next) ? (front->next) : NULL);
        delete t;
        t = front;
    }
}

void DEQueue::display() {
    Node *t = front;
    while (t) {
        std::cout << t->data << " <- ";
        t = t->next;
    }
    std::cout << "/" << std::endl;
}

void DEQueue::enqueue_front(int x) {
    Node *t = new Node;
    t->data = x;
    if (front == NULL) {
        rear = front = t;
        t->next = NULL;
    }
    t->next = front;
    front = t;
}

void DEQueue::enqueue_rear(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if (front == NULL) {
        rear = front = t;
    }
    rear->next = t;
    rear = t;
}

void DEQueue::dequeue_front() {
    Node *t = front;
    front = front->next;
    delete t;
}

void DEQueue::dequeue_rear() {
    Node *t = front;
    while (t->next->next) {  // by doing this 't' will stop at previous node of rare's node
        t = t->next;
    }
    delete rear;
    t->next = NULL;
    rear = t;
}