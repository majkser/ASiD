#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(12);
    tree.insert(13);
    tree.insert(10);
    tree.insert(5);

    tree.display();
}