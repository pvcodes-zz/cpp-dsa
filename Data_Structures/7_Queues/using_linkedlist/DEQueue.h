#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "node.h"

class DEQueue {
   private:
    Node *front;
    Node *rear;

   public:
    DEQueue();
    ~DEQueue();

    // Methods
    void display();
    void enqueue_front(int x);
    void enqueue_rear(int x);
    void dequeue_front();
    void dequeue_rear();
};
#endif  // DEQUEUE_H