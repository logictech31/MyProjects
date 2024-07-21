#include <iostream>
#include "bst.hxx"
using namespace Trees;

int main (void) {
    BST t1;
    int i = 10, temp = 0;
    std::cout << "Enter 10 numbers: ";

    while (i--) {
        std::cin >> temp;
        t1.add_to_tree(temp);
    }

    t1.inorder_r_call();

    return 0;
}