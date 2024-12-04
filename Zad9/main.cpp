#include "priorityQueue.h"
#include <iostream>
#include <cassert>

int main()
{
    PriorityQueue<int> pq;
    std::cout << "Empty queue: ";
    pq.display();
    assert(pq.empty() && "Queue should be empty initially");

    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(5);
    std::cout << "After pushing: ";
    pq.display();

    std::cout << "Testing copy constructor:\n";
    PriorityQueue<int> pq2(pq);
    std::cout << "Original queue: ";
    pq.display();
    std::cout << "Copied queue: ";
    pq2.display();

    PriorityQueue<int> pq3;
    pq3 = pq;
    std::cout << "Original queue: ";
    pq.display();
    std::cout << "Assigned queue: ";
    pq3.display();

    std::cout << "Top element: " << pq.top() << std::endl;
    pq.pop();
    std::cout << "After pop: ";
    pq.display();
    std::cout << "New top element: " << pq.top() << std::endl;

    std::cout << "Testing clear operation:\n";
    pq.clear();
    std::cout << "Is queue empty? " << (pq.empty() ? "Yes" : "No") << std::endl;

    return 0;
}