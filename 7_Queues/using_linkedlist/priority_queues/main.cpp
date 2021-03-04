#include <iostream>

#include "priority_queue.h"

int main() {
    PriorityQueue prq;
    // prq.enqueue(2, 0);
    // prq.enqueue(12, 0);
    // prq.enqueue(4, 0);
    // prq.enqueue(5, 0);
    prq.enqueue(2, 2);
    prq.enqueue(6, 2);
    // prq.enqueue(7, 0);
    prq.enqueue(6, 1);
    prq.enqueue(8, 2);
    prq.enqueue(10, 1);
    prq.enqueue(2, 2);
    prq.display();

    prq.dequeue();
    prq.display();
    return 0;
}