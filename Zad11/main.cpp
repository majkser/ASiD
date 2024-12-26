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
    tree.insert(38);

    tree.display();

    std::cout << "najmniejsza wartosc wynosi: " << *tree.find_min() << " i znajduje sie pod adresem: " << tree.find_min() << std::endl;
    std::cout << "najwieksza wartosc wynosi: " << *tree.find_max() << " i znajduje sie pod adresem: " << tree.find_min() << std::endl;
}