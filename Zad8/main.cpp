#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> queue;

    queue.push(2);
    queue.push(1);
    queue.push(3);
    queue.push(7);

    queue.display();

    Queue<int> copyOfQueue(queue);

    copyOfQueue.display();

    std::cout << queue.front();

    return 0;
}