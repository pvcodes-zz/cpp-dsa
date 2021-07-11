#include "bst.h"

#include <iostream>
#include <stack>

int heightTree(Node *p);
Node *_in_pre(Node *p);
Node *_in_suc(Node *p);

bool BST::search(int key) {
    Node *ptr = Root;
    while (ptr) {
        if (ptr->data > key) {
            ptr = ptr->lchild;
        } else if (ptr->data > key) {
            ptr = ptr->rchild;
        } else {
            return 1;
        }
    }
    return 0;
}

void BST::insert(int key) {
    Node *ptr = Root;
    Node *tail_ptr = NULL;

    while (ptr) {
        tail_ptr = ptr;
        if (ptr->data > key) {
            ptr = ptr->lchild;
        } else if (ptr->data < key) {
            ptr = ptr->rchild;
        } else {  // ptr->data == key
            std::cout << "Key value already present" << std::endl;
            return;
        }
    }

    ptr = new Node;
    ptr->data = key;
    ptr->lchild = ptr->rchild = NULL;
    if (tail_ptr->data > key) {
        tail_ptr->lchild = ptr;
    } else {
        tail_ptr->rchild = ptr;
    }
}

Node *BST::delete_node(Node *p, int key) {
    if (!p) {
        return NULL;
    }
    if (!p->lchild && !p->rchild) {  // if p has no child
        if (p == Root) {
            Root = NULL;
        }
        delete p;
        return NULL;
    }

    Node *q;
    if (key < p->data) {
        p->lchild = delete_node(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = delete_node(p->rchild, key);
    } else {
        if (heightTree(p->lchild) > heightTree(p->rchild)) {
            q = _in_pre(p->lchild);
            p->data = q->data;
            p->lchild = delete_node(p->lchild, q->data);
        } else {
            q = _in_suc(p->rchild);
            p->data = q->data;
            p->rchild = delete_node(p->rchild, q->data);
        }
    }
    return NULL;
}

int BST::height() { return heightTree(Root); }

//-----------------------------------------------------------------------------------
int heightTree(Node *p) {
    if (!p) {
        return 0;
    }
    int lh, rh;
    lh = heightTree(p->lchild);
    rh = heightTree(p->rchild);
    return (lh > rh) ? lh + 1 : rh + 1;
}

Node *_in_pre(Node *p) {
    p = p->lchild;
    while (p) {
        p = p->rchild;
    }
    return p;
}

Node *_in_suc(Node *p) {
    p = p->rchild;
    while (p) {
        p = p->lchild;
    }
    return p;
}

void BST::createFromPreorder(int *pre, int n) {
    // Create Root node
    int i = 0;
    Root = new Node;
    Root->data = pre[i++];
    Root->lchild = nullptr;
    Root->rchild = nullptr;

    // Iterative steps
    Node *t;
    Node *p = Root;
    std::stack<Node *> stk;

    while (i < n) {
        // Left child case
        if (pre[i] < p->data) {
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        } else {
            // Right child cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data) {
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}