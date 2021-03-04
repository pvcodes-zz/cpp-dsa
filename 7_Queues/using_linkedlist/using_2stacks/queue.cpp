#include "queue.h"

#include <iostream>
#include <stack>

Queue::Queue() {}
Queue::~Queue() {}

void Queue::enqueue(int x) { s1.push(x); }
void Queue::dequeue() {
    if (s2.empty()) {
        while (!(s1.empty())) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}

// Auxillary function
void stack_display(std::stack<int> s, bool isTopToBottom) {
    if (s.empty()) return;
    int x = s.top();
    if (isTopToBottom) {
        std::cout << x << " ";
        s.pop();
        stack_display(s, isTopToBottom);
    } else {
        s.pop();
        stack_display(s, isTopToBottom);
        std::cout << x << " ";
    }

    s.push(x);
}

void Queue::display() {
    stack_display(s2, 1);
    stack_display(s1, 0);
    puts("");
    //
}
