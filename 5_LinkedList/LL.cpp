#include "LL.h"

#include <iostream>

LinkedList::LinkedList() : Head{NULL}, Tail{NULL} {}

LinkedList::LinkedList(int A[], int n) {
    Node *ptr, *t;
    int i = 0;
    Head = new Node;
    Head->data = A[0];
    Head->next = NULL;
    ptr = Head;
    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        ptr->next = t;
        ptr = t;
    }
    Tail = ptr;
}

LinkedList::~LinkedList() {
    Node *ptr = Head;
    while (ptr) {
        Head = Head->next;
        delete ptr;
        ptr = Head;
    }
}

void LinkedList::add_node(int a) {
    Node *n = new Node;
    n->data = a;
    n->next = NULL;
    if (Head == NULL) {
        Head = n;
        Tail = n;
    } else {
        Tail->next = n;
        Tail = Tail->next;
    }
}

void LinkedList::display() {
    Node *ptr = Head;
    while (ptr != NULL) {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    puts("/");
};

void LinkedList::push_front(int a) {
    Node *n = new Node;
    n->data = a;
    n->next = Head;
    Head = n;
}

void LinkedList::push_back(int a) {
    Node *n = new Node;
    n->data = a;
    n->next = NULL;

    Node *ptr = Head;

    while (ptr->next != NULL) ptr = ptr->next;

    ptr->next = n;
    Tail = n;
}

void LinkedList::insert(int index, int a) {
    if (index < 0 || index > len()) {
        std::cout << "Index out of bound" << std::endl;
        return;
    }

    if (index == 0) {
        push_front(a);
        return;
    } else if (index == len()) {
        push_back(a);
        return;
    }

    Node *n = new Node;
    n->data = a;

    Node *ptr = Head;
    for (int i = 1; i < index - 1; i++) {
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
}
int LinkedList::len() {
    Node *ptr = Head;
    int c{0};
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void LinkedList::insert_in_sorted(int key) {
    // This commented code is fine, while making notes I kinda use my logic and implemented it and
    // the code while understanding(what i learned from course), I commented that out xD

    // if (Head->data > key) {
    //     push_front(key);
    //     return;
    // }
    // Node *ptr = Head;
    // Node *tail_ptr = NULL;
    // while (ptr && ptr->data < key) {
    //     tail_ptr = ptr;
    //     ptr = ptr->next;
    // }
    // Node *n = new Node();
    // n->data = key;
    // n->next = tail_ptr->next;
    // tail_ptr->next = n;

    Node *ptr = Head;
    Node *tail_ptr = ptr;

    Node *n = new Node;
    n->data = key;
    if (ptr->data > key) {
        n->next = ptr;
        Head = n;
        return;
    }
    ptr = ptr->next;  // pointing to 2nd node so that tail_ptr can become its actual tail :)
    while (ptr) {
        if (ptr->data > key && tail_ptr->data < key) {
            n->next = ptr;
            tail_ptr->next = n;
            return;
        }
        if (ptr->next == NULL) {  // Means its ptr is at last node
            ptr->next = n;
            n->next = NULL;
            Tail = n;
            return;
        }
        tail_ptr = ptr;
        ptr = ptr->next;
    }
}

void LinkedList::remove(int index) {
    Node *ptr = Head;
    Node *tail_ptr = NULL;
    if (index == 1) {
        Head = Head->next;
        delete ptr;
    } else {
        for (int i = 0; (i < index - 1 && ptr); i++) {
            tail_ptr = ptr;
            ptr = ptr->next;
        }
        if (ptr) {
            tail_ptr->next = ptr->next;
            delete ptr;
        }
    }
}

bool LinkedList::is_sorted() {
    Node *ptr = Head;
    while (ptr) {
        if (ptr->next && (ptr->data > ptr->next->data)) {
            return 0;
        }
        ptr = ptr->next;
    }
    return 1;
}
void LinkedList::remove_duplicates() {
    Node *ptr = Head->next;
    Node *tail_ptr = Head;
    while (ptr) {
        if (tail_ptr->data == ptr->data) {
            tail_ptr->next = ptr->next;
            Node *tmp = ptr;
            ptr = ptr->next;
            delete tmp;
            continue;
            // delete ptr;
        }
        tail_ptr = ptr;
        ptr = ptr->next;
    }
}

void LinkedList::reverse() {
    // VIA Reversing links
    Node *ptr = Head;
    Node *tail_ptr = NULL;
    Node *tail_tail_ptr = NULL;  // Tail of tail_ptr

    while (ptr) {
        tail_tail_ptr = tail_ptr;  // These three steps
        tail_ptr = ptr;            // are for  sliding
        ptr = ptr->next;           // pointers

        tail_ptr->next = tail_tail_ptr;  // reversing links is done here
    }
    Head = tail_ptr;  // making the Head ptr to last node
}

void LinkedList::concat(LinkedList *ll, bool a) {
    Tail->next = ll->Head;
    Tail = ll->Tail;
    if (!a) ll->Head = NULL;
}

void LinkedList::merge_sorted(LinkedList *ll) {
    Node *new_first{NULL}, *new_last{NULL};

    // making the new ptr to point on smaller value to get started
    if (this->Head->data < ll->Head->data) {
        new_first = this->Head;
        new_last = this->Head;
        Head = Head->next;
        new_last->next = NULL;
    } else {
        new_first = ll->Head;
        new_last = ll->Head;
        ll->Head = ll->Head->next;
        new_last->next = NULL;
    }

    // checking and merging
    while (this->Head && ll->Head) {
        if (this->Head->data < ll->Head->data) {
            new_last->next = this->Head;
            new_last = this->Head;
            this->Head = this->Head->next;
            new_last->next = NULL;
        } else {
            new_last->next = ll->Head;
            new_last = ll->Head;
            ll->Head = ll->Head->next;
            new_last->next = NULL;
        }
    }
    // if any one of the list is finished the left one will be linked
    if (!(ll->Head)) {
        new_last->next = this->Head;
    } else {
        new_last->next = ll->Head;
    }

    // Making the new ptr's to original ptr
    this->Head = new_first;
    this->Tail = new_last;

    // removing ll's head and tail ptr;
    ll->Head = NULL;
    ll->Tail = NULL;
}

bool LinkedList::is_loop() {
    // if we are using two ptr for Head and Tail
    // if (Tail) return 0;
    // return 1;

    // If we dont have the Tail
    Node *ptr = Head;
    Node *ptr2 = Head;
    do {
        ptr = ptr->next;
        ptr2 = ptr2->next;

        ptr2 = (!ptr2) ? ptr2->next : NULL;
    } while (ptr && ptr2);
    if (ptr == ptr2) {
        return 1;
    }
    return 0;
}
