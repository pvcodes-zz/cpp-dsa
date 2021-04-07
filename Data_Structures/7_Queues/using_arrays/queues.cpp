#include "queues.h"

#include <iostream>

Queue::Queue(int n) : front{0}, rear{0}, size{n}, A{nullptr} { A = new int[size]; }

Queue::~Queue() {
    // delete[] A;
    A = nullptr;
    front = rear = 0;
    size = 0;
}

void Queue::display() {
    int f = front + 1;
    int r = rear;
    while (f != r) {
        std::cout << A[f] << " <- ";
        f = (f + 1) % size;
    }
    std::cout << "/" << std::endl;
}

bool Queue::isEmpty() { return ((front == rear) ? 1 : 0); }

bool Queue::isFull() { return (((rear + 1) % size == front) ? 1 : 0); }

void Queue::enqueue(int x) {
    if (isFull()) {
        std::cout << "Queue Overflow" << std::endl;
    } else {
        rear = (rear + 1) % size;
        A[rear] = x;
    }
}

void Queue::dequeue() {
    if (isEmpty())
        std::cout << "Queue is Empty" << std::endl;
    else
        A[front++] = 0;
}

int Queue::first() { return A[front + 1]; }

int Queue::last() { return A[rear]; }