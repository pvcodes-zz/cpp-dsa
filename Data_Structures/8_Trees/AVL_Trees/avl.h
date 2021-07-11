#include <iostream>

using namespace std;

class Node {
   public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL {
   public:
    Node* root;

    AVL() { root = nullptr; }

    // Helper methods for inserting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);

    // Insert
    Node* rInsert(Node* p, int key);

    // Traversal
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    Node* getRoot() { return root; }
};