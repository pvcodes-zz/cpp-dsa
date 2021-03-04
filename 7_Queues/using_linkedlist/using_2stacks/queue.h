#ifndef QUEUE_H
#define QUEUE_H
#include <stack>
class Queue {
   private:
    std::stack<int> s1;
    std::stack<int> s2;

   public:
    Queue();
    ~Queue();
    void display();
    void enqueue(int x);
    void dequeue();
};
#endif  // QUEUE_H