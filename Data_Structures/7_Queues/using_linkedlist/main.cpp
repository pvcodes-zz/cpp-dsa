#include <iostream>

#include "DEQueue.h"
#include "queues.h"

int main() {
    // Queue q;
    // // q.enqueue(11);
    // // q.enqueue(1);
    // // q.enqueue(7);
    // q.display();
    // q.dequeue();
    // q.display();

    DEQueue deq;
    deq.enqueue_rear(11);
    deq.enqueue_rear(8);
    deq.enqueue_front(9);
    deq.enqueue_rear(1);
    deq.enqueue_front(5);
    deq.enqueue_front(78);
    deq.display();

    deq.dequeue_rear();
    deq.display();

    return 0;
}