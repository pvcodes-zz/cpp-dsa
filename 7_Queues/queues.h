#ifndef QUEUES_H
#define QUEUES_H
class Queue {
   private:
    int *A;
    int front;
    int rear;

   public:
    Queue();
    Queue(int A[], int n);
    ~Queue();

    // Methods
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int first();
    int last();
};
#endif  // QUEUES_H