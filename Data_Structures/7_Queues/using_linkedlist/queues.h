#ifndef QUEUES_H
#define QUEUES_H

#include "node.h"

class Queue {
   private:
    Node *front;
    Node *rear;

   public:
    Queue();
    ~Queue();

    // Methods
    void display();
    void enqueue(int x);
    void dequeue();
    int first();
    int last();
};
#endif  // QUEUES_H