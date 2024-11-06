#include "doublelist.h"
#include <iostream>

int main()
{
    DoubleList<int> list;

    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "After push_back: ";
    list.display();
    std::cout << std::endl;

    list.push_front(4);
    list.push_front(5);
    std::cout << "After push_front: ";
    list.display();
    std::cout << std::endl;

    list.pop_back();
    std::cout << "After pop_back: ";
    list.display();
    std::cout << std::endl;

    list.pop_front();
    std::cout << "After pop_front: ";
    list.display();
    std::cout << std::endl;

    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    if (!list.empty())
    {
        std::cout << "Front element: " << list.front() << std::endl;
        std::cout << "Back element: " << list.back() << std::endl;
    }

    std::cout << "Current list: ";
    list.display();
    std::cout << std::endl;
    std::cout << "Current list reversed: ";
    list.display_reversed();
    std::cout << std::endl;

    std::cout << "Size of the list: " << list.size() << std::endl;

    std::cout << "Clearing the list " << std::endl;

    list.clear();
    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

    return 0;
}