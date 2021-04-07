#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct Node {
    int data;
    Node *next;
};

class PriorityQueue {
   private:
    Node *front[3];  // array of front ptr
    Node *rear[3];   // array of rear ptr

   public:
    PriorityQueue();
    ~PriorityQueue();

    // Methods
    void display();
    // x belongs to value and p belong to priority of x
    void enqueue(int x, int p);
    void dequeue();
};

#endif  // PRIORITY_QUEUE_H