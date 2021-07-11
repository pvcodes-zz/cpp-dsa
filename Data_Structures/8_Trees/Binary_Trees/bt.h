#ifndef BT_H
#define BT_H

#include <iostream>
#include <queue>

struct Node {
    Node *lchild;
    int data;
    Node *rchild;
};
class BinaryTree {
   protected:
    Node *Root;
    std::queue<Node *> Q;

   public:
    BinaryTree();
    ~BinaryTree();

    // Methods

    // display methods have 1 argument for preoder use 1, for inorder use 2, for postorder use 3 and
    // for levelorder use 4
    void display(int x);
    void preorder_display();
    void inorder_display();
    void postorder_display();
    void levelorder_display();
    // to get total nodes
    int total_nodes();
    // to get nodes with degree x=1 or 2
    int total_nodes(int x);
    int sum();
    int height();
};

#endif  // BT_H
