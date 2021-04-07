#include <iostream>
using namespace std;
#include "bst.h"
#include "bt.h"

int main() {
    // BinaryTree bt;
    // bt.display(1);
    // bt.display(2);
    // bt.display(3);
    // bt.levelorder_display();
    // std::cout << bt.sum() << std::endl;
    // std::cout << bt.total_nodes() << std::endl;
    // std::cout << bt.total_nodes(1) << std::endl;
    // std::cout << bt.total_nodes(2) << std::endl;

    BST tree;
    // std::cout << std::boolalpha << tree.search(14) << std::endl;
    tree.insert(9);
    // tree.inorder_display();
    tree.insert(5);
    tree.insert(12);
    tree.insert(14);
    tree.insert(18);
    // tree.inorder_display();
    // tree.delete_node(5);
    tree.inorder_display();
    tree.delete_node(5);
    tree.inorder_display();
    cout << tree.height() << endl;
    return 0;
}