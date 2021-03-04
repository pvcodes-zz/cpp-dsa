#include <iostream>

#include "queues.h"

int main() {
    //
    int A[] = {3, 6, 23};
    // Queue Q(A, 3, 3);
    Queue Q(4);
    Q.enqueue(11);
    Q.enqueue(12);
    Q.enqueue(2);
    Q.display();
    Q.dequeue();
    Q.display();
    Q.enqueue(8);
    Q.display();
    // Q.enqueue(1);
    // Q.dequeue();
    // Q.display();
    std::cout << Q.first() << std::endl;
    // Q.dequeue();
    //   Q.display();
    return 0;
}