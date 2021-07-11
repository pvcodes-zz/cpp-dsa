#ifndef QUEUES_H
#define QUEUES_H
class Queue {
   private:
    int *A;
    int front;
    int rear;
    int size;

   public:
    // By default the array size is 10
    Queue(int n);
    ~Queue();

    // Methods
    void display();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    void dequeue();
    int first();
    int last();
};
#endif  // QUEUES_H