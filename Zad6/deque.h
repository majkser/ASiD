#ifndef DEQUE_H
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

    Deque &operator=(const Deque &other)
    {
        if (this != &other)
        {
            MyDeque = other.MyDeque;
        }
        return *this;
    } // copy assignment operator, return *this

    Deque(Deque &&other)
    {
        MyDeque = std::move(other.MyDeque);
    } // move constructor

    Deque &operator=(Deque &&other)
    {
        if (this != &other)
        {
            MyDeque = std::move(other.MyDeque);
        }
        return *this;
    } // move assignment operator, return *this

    bool empty() const
    {
        return MyDeque.empty();
    }

    std::size_t size() const
    {
        return MyDeque.size();
    }

    void push_front(const T &item)
    {
        MyDeque.push_front(item);
        assert(!MyDeque.empty() && "Deque should not be empty after push_front");
    }

    void push_front(T &&item)
    {
        MyDeque.push_front(std::move(item));
        assert(!MyDeque.empty() && "Deque should not be empty after push_front");
    }

    void push_back(const T &item)
    {
        MyDeque.push_back(item);
        assert(!MyDeque.empty() && "Deque should not be empty after push_back");
    }

    void push_back(T &&item)
    {
        MyDeque.push_back(std::move(item));
        assert(!MyDeque.empty() && "Deque should not be empty after push_back");
    }

    T &front()
    {
        assert(!MyDeque.empty() && "Cannot access front of an empty deque");
        return MyDeque.front();
    }

    T &back()
    {
        assert(!MyDeque.empty() && "Cannot access back of an empty deque");
        return MyDeque.back();
    }

    void pop_front()
    {
        assert(!MyDeque.empty() && "Cannot pop_front from an empty deque");
        MyDeque.pop_front();
    }

    void pop_back()
    {
        assert(!MyDeque.empty() && "Cannot pop_back from an empty deque");
        MyDeque.pop_back();
    }

    void clear()
    {
        MyDeque.clear();
    }

    void display()
    {
        for (auto i : MyDeque)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void display_reversed()
    {
        for (auto i = MyDeque.rbegin(); i != MyDeque.rend(); i++)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }
};

#endif // DEQUE_H