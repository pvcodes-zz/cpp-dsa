#include "bt.h"

#include <iostream>
#include <queue>

// Auxilary Function init
int _sum(Node *p);
int _height(Node *p);
int _node_degree_1(Node *p);
int _node_degree_2(Node *p);
int _total_nodes(Node *p);
void _preorder_display(Node *p);
void _inorder_display(Node *p);
void _postorder_display(Node *p);
void _levelorder_display(Node *p);

BinaryTree::BinaryTree() {
    Node *t, *p;
    int x;
    std::cout << "Enter the root val: ";
    std::cin >> x;

    Root->data = x;
    Root->lchild = NULL;
    Root->rchild = NULL;
    Q.push(Root);

    while (!(Q.empty())) {
        p = Q.front();
        Q.pop();
        bool isL, isR;
        std::cout << "is the " << p->data << " node have left child (type : 0 or 1): ";
        std::cin >> isL;
        if (isL != 0 && isL != 1) {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        if (isL) {
            t = new Node;
            std::cout << "Enter the left child node val: ";
            std::cin >> x;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Q.push(t);
        }

        std::cout << "is the " << p->data << " node have right child (type : 0 or 1): ";
        std::cin >> isR;
        if (isR != 0 && isR != 1) {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        if (isR) {
            t = new Node;
            std::cout << "Enter the right child node val: ";
            std::cin >> x;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Q.push(t);
        }
    }
}

BinaryTree::~BinaryTree() {}

void BinaryTree::display(int x) {
    switch (x) {
        case 1:
            _preorder_display(Root);
            break;
        case 2:
            _inorder_display(Root);
            break;
        case 3:
            _postorder_display(Root);
            break;
        case 4:
            _levelorder_display(Root);
            break;
        default:
            break;
    }
    std::cout << std::endl;
}
void BinaryTree::preorder_display() {
    _preorder_display(Root);
    std::cout << std::endl;
}
void BinaryTree::inorder_display() {
    _inorder_display(Root);
    std::cout << std::endl;
}
void BinaryTree::postorder_display() {
    _postorder_display(Root);
    std::cout << std::endl;
}
void BinaryTree::levelorder_display() {
    _levelorder_display(Root);
    std::cout << std::endl;
}

int BinaryTree::total_nodes() { return (_total_nodes((Root))); }
int BinaryTree::total_nodes(int x) {
    if (x == 1)
        return (_node_degree_1(Root));
    else if (x == 2)
        return (_node_degree_2(Root));
    else
        return 0;
}

int BinaryTree::sum() { return (_sum(Root)); }
int BinaryTree::height() { return (_height(Root)); }

// --------------------------------------------------------------------------------------------
// Auxilary Function
// --------------------------------------------------------------------------------------------

int _height(Node *p) {
    int x, y;
    if (p) {
        x = _height(p->lchild);
        y = _height(p->rchild);
        if (x > y) {
            return x + 1;

        } else
            return y + 1;
    }
    return 0;
}

int _sum(Node *p) {
    int x, y;
    if (p) {
        x = _sum(p->lchild);
        y = _sum(p->rchild);
        return x + y + p->data;
    } else
        return 0;
}

int _node_degree_2(Node *p) {
    int x, y;
    if (p) {
        x = _node_degree_1(p->lchild);
        y = _node_degree_1(p->rchild);
        if (p->lchild && p->rchild) {
            return x + y + 1;
        }
        return 0;
    }
    return 0;
}
int _node_degree_1(Node *p) {
    int x, y;
    if (p) {
        x = _node_degree_1(p->lchild);
        y = _node_degree_1(p->rchild);
        if (p->lchild || p->rchild) {
            return x + y + 1;
        }
        return 0;
    }
    return 0;
}
int _total_nodes(Node *p) {
    int x, y;
    if (p) {
        x = _total_nodes((p->lchild));
        y = _total_nodes((p->rchild));
        return x + y + 1;
    } else
        return 0;
}
void _preorder_display(Node *p) {
    if (p) {
        std::cout << p->data << " ";
        _preorder_display(p->lchild);
        _preorder_display(p->rchild);
    }
}

void _inorder_display(Node *p) {
    if (p) {
        _inorder_display(p->lchild);
        std::cout << p->data << " ";
        _inorder_display(p->rchild);
    }
}

void _postorder_display(Node *p) {
    if (p) {
        _postorder_display(p->lchild);
        _postorder_display(p->rchild);
        std::cout << p->data << " ";
    }
}

void _levelorder_display(Node *p) {
    std::queue<Node *> Q;
    std::cout << p->data << std::endl;
    Q.push(p);

    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p->lchild) {
            std::cout << p->lchild->data << std::endl;
            Q.push(p->lchild);
        }
        if (p->rchild) {
            std::cout << p->rchild->data << std::endl;
            Q.push(p->rchild);
        }
    }
}
