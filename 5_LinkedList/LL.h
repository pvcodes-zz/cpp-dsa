#ifndef LL_H
#define LL_H

struct Node {
    int data;
    Node *next;
};

// Class for singly linked list
class LinkedList {
   private:
    Node *Head;
    Node *Tail;

   public:
    LinkedList();
    LinkedList(int A[], int n);
    ~LinkedList();

    void add_node(int a);
    void display();
    void push_front(int a);
    void push_back(int a);
    void insert(int index, int a);
    int len();
    void remove(int index);
    void insert_in_sorted(int key);
    bool is_sorted();
    void remove_duplicates();
    void reverse();
    void concat(LinkedList *ll, bool a);
    void merge_sorted(LinkedList *ll);
    bool is_loop();
};

#endif  // LL_H
