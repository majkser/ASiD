#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> queue;

    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    queue.push(2);
    queue.push(1);
    queue.push(3);
    queue.push(7);

    std::cout << "queue after push: ";
    queue.display();

    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;
    std::cout << "queue size: " << queue.size() << std::endl;
    Queue<int> copyOfQueue(queue);

    std::cout << "copy of queue: ";
    copyOfQueue.display();

    std::cout << "first element in queue: ";
    std::cout << queue.front() << std::endl;

    std::cout << "last element in queue: ";
    std::cout << queue.back() << std::endl;

    queue.pop();
    std::cout << "queue after pop: ";
    queue.display();

    std::cout << "clearing queue..." << std::endl;
    queue.clear();

    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}