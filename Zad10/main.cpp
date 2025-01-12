#include <iostream>
#include <ctime>
#include "RandomBinaryTree.h"

int main()
{
    std::srand(std::time(nullptr));
    RandomBinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);
    tree.insert(1);
    tree.insert(6);

    tree.display();

    std::cout << std::endl
              << "liczba lisci w drzewie obliczona rekurencyjnie: " << tree.recurcive_calc_leaves();

    std::cout << std::endl
              << "liczba lisci w drzewie obliczona iteracyjnie: " << tree.iterative_calc_leaves();

    std::cout << std::endl
              << "suma obliczona rekurencyjnie: " << tree.recursive_calc_total();
    std::cout << std::endl
              << "suma obliczona iteracyjnie: " << tree.iterative_calc_total() << std::endl;
    std::cout << "wysokosc obliczona rekurencyjnie: " << tree.recursive_calc_height() << std::endl;
    std::cout << "wysokosc obliczona iteracyjnie: " << tree.iterative_calc_height() << std::endl;
    std::cout << "ilosc wezlow obliczona iteracyjnie: " << tree.iterative_calc_nodes() << std::endl;
    std::cout << "ilosc wezlow obliczona rekurencyjnie: " << tree.recursive_calc_nodes() << std::endl;

    return 0;
}