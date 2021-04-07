#include <iostream>

#include "CLL.h"
#include "DCLL.h"
#include "DLL.h"
#include "LL.h"

// Doubly Circluar Linked list
D_Node *reverse_dd(D_Node *head) {
    //
    D_Node *ptr = head;
    D_Node *tail_ptr = NULL;
    D_Node *tail_tail_ptr = NULL;  // Tail of tail_ptr

    while (ptr) {
        tail_tail_ptr = tail_ptr;  // These three steps
        tail_ptr = ptr;            // are for  sliding
        ptr = ptr->next;           // pointers

        tail_ptr->next = tail_tail_ptr;  // reversing links is done here
        tail_ptr->prev = ptr;
    }
    tail_ptr->prev = NULL;
    return tail_ptr;
}

void dis(D_Node *ptr) {
    while (ptr) {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main() {
    int A[] = {1, 4, 5, 8, 9};
    Doubly_LinkedList CL(A, 5);
    D_Node *ptr = CL.get_head();
    dis(ptr);

    ptr = reverse_dd(ptr);
    dis(ptr);

    // CL.Display();
    // CL.Delete(-7);
    // CL.Display();
    // CL.pop_front();
    // CL.Display();

    return 0;
}
