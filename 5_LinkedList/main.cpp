#include <iostream>

#include "CLL.h"
#include "DCLL.h"
#include "DLL.h"
#include "LL.h"

// Doubly Circluar Linked list

int main() {
    int A[] = {1, 4, 5, 8, 9};
    DoublyCircluar_LinkedList CL(A, 5);
    CL.Insert(12, 12345);
    CL.Display();
    CL.Delete(65);
    CL.Display();
    // CL.Display();
    // CL.Delete(-7);
    // CL.Display();
    // CL.pop_front();
    // CL.Display();

    return 0;
}
