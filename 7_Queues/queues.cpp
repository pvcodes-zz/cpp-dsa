#include "queues.h"

Queue::Queue() : front{-1}, rear{-1} {}
Queue::Queue(int A[], int n) { this->A = A; }
