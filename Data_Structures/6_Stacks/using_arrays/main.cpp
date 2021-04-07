#include <iostream>

#include "stack.h"

int main() {
    //
    int B[] = {1, 2, 3, 4, 5, 6};
    Stack stk(B, 6);
    // stk.display();
    std::cout << stk.isFull() << std::endl;
    std::cout << stk.isEmpty() << std::endl;
    stk.pop();
    stk.push(12);
    stk.display();
    return 0;
}