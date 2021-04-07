#ifndef BST_H
#define BST_H
#include "bt.h"

class BST : public BinaryTree {
   public:
    // Methods
    bool search(int key);
    void insert(int key);
    Node* delete_node(int key) { return (delete_node(Root, key)); }
    Node* delete_node(Node* p, int key);
    void createFromPreorder(int* pre, int n);
    int height();
};
#endif  // BST_H