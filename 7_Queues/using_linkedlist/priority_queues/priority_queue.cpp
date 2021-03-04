#include "priority_queue.h"

#include <iostream>

PriorityQueue::PriorityQueue() { front[0] = front[1] = front[2] = NULL; }

PriorityQueue::~PriorityQueue() {}

void PriorityQueue::enqueue(int x, int p) {
    if (p > 3) {
        std::cout << "Priority exceeded" << std::endl;
        return;
    }

    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if (front[p] == NULL) {
        front[p] = rear[p] = t;
    } else {
        rear[p]->next = t;
        rear[p] = t;
    }
}

void PriorityQueue::display() {
    for (int i = 0; i < 3; i++) {
        Node *t = front[i];
        std::cout << "Q[" << i + 1 << "] : ";
        while (t) {
            std::cout << t->data << " <- ";
            t = t->next;
        }
        std::cout << "/" << std::endl;
    }
}

void PriorityQueue::dequeue() {
    int i = 0;
    if (!(front[0])) {
        if (!(front[1])) {
            i = 2;
        } else {
            i = 1;
        }
    }

    Node *t = front[i];
    front[i] = front[i]->next;
    delete t;
}