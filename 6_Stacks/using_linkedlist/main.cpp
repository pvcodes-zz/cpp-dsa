#include <iostream>

#include "stack.h"
int main() {
    //
    int A[] = {10, 15, 8, 3};
    Stack stk;
    stk.display();
    stk.push(11);
    std::cout << stk.get_Size() << std::endl;
    stk.display();
    // stk.pop();
    std::cout << std::boolalpha << stk.isEmpty() << std::endl;
    std::cout << stk.peek(2) << std::endl;
    std::cout << stk.stack_top() << std::endl;
    std::cout << stk.get_Size() << std::endl;
    return 0;
}