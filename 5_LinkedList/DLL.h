#ifndef DLL_H
#define DLL_H
struct D_Node {
    D_Node *prev;
    int data;
    D_Node *next;
};
class Doubly_LinkedList {
   private:
    D_Node *Head;
    D_Node *Tail;

   public:
    Doubly_LinkedList();
    Doubly_LinkedList(int A[], int n);
    ~Doubly_LinkedList();

    void Display();
    int len();
    void Insert(int val, int index);
    void push_front(int val);
    void push_back(int val);
    void pop_back();
    void Delete(int index);  // take care of last index and first index
    void Reverse();
};
#endif  // DLL_H