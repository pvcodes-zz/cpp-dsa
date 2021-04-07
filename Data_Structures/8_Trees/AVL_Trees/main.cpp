#include <iostream>

#include "avl.h"

int main() {
    // LR Rotation
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);

    tlr.Inorder();
    cout << endl;
    cout << tlr.root->data << endl;

    // RL Rotation
    AVL trl;
    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);

    trl.Inorder();
    cout << endl;
    cout << trl.root->data << endl;

    return 0;
}