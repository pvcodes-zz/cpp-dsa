#include <iostream>

#include "queue.h"

int main() {
    Queue sq;
    sq.enqueue(1);
    sq.enqueue(2);
    sq.enqueue(3);
    sq.enqueue(4);
    sq.enqueue(5);
    sq.display();
    sq.dequeue();
    sq.display();
    return 0;
}