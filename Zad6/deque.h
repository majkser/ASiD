#define DEQUE_H

#include <iostream>
#include <cassert>
#include <list>

template <typename T>
class Deque
{
private:
    std::list<T> MyDeque;

public:
    Deque() = default;

    Deque(const Deque &other)
    {
        MyDeque = other.MyDeque;
    } // copy constructor

    Deque(const Deque &other)
    {
        MyDeque = other.MyDeque;
        return *this;
    } // copy assignment operator, return *this

    bool empty() const
    {
        return MyDeque.empty();
    }

    // dont forget about assert
};
