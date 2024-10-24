#include "arraylist.h"
#include <iostream>

int main()
{
    ArrayList<int> lista;

    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(8);
    lista.push_front(7);

    std::cout << "Lista po dodaniu elementow: ";
    lista.display();

    std::cout << "Czy lista jest pusta? " << (lista.empty() ? "Tak" : "Nie") << std::endl;
    std::cout << "Czy lista jest pelna? " << (lista.full() ? "Tak" : "Nie") << std::endl;
    std::cout << "Liczba elementow: " << lista.size() << std::endl;
    std::cout << "Maksymalna liczba elementow: " << lista.max_size() << std::endl;

    lista.sort();
    std::cout << "Lista po sortowaniu: ";
    lista.display();

    lista.reverse();
    std::cout << "Lista po odwroceniu: ";
    lista.display();

    lista.pop_front();
    std::cout << "Lista po usunieciu pierwszego elementu: ";
    lista.display();

    lista.pop_back();
    std::cout << "Lista po usunieciu ostatniego elementu: ";
    lista.display();

    lista.clear();
    std::cout << "Lista po czyszczeniu: ";
    lista.display();

    return 0;
}