#include "deque.h"
#include <iostream>

int main()
{
    Deque<int> deque;

    std::cout << "Deque size: " << deque.size() << std::endl;
    std::cout << "Is deque empty? " << (deque.empty() ? "Yes" : "No") << std::endl;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    std::cout << "After push_back: ";
    deque.display();

    std::cout << "Is deque empty? " << (deque.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Deque size: " << deque.size() << std::endl;

    deque.push_front(4);
    deque.push_front(5);
    deque.push_front(6);

    std::cout << "After push_front: ";
    deque.display();

    std::cout << "Deque size: " << deque.size() << std::endl;

    deque.pop_back();
    deque.pop_front();

    std::cout << "After pop_back and pop_front: ";
    deque.display();

    std::cout << "Top element: " << deque.front() << std::endl;
    std::cout << "Back element: " << deque.back() << std::endl;

    std::cout << "Reversed deque: ";

    deque.display_reversed();

    Deque<int> deque2 = deque;

    std::cout << "Deque: ";
    deque.display();

    std::cout << "Copied deque to deque2: ";
    deque2.display();

    deque.clear();
    std::cout << "Clearing deque" << std::endl;
    std::cout << "Is deque empty? " << (deque.empty() ? "Yes" : "No") << std::endl;

    return 0;
}