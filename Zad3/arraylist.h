// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert>  // assert()
#include <algorithm>

template <typename T>
class ArrayList
{
    T *tab;
    std::size_t msize; // najwieksza mozliwa liczba elementow
    std::size_t last;  // pierwsza wolna pozycja
public:
    ArrayList(std::size_t s = 10) : msize(s), last(0)
    {
        assert(s > 0);
        tab = new T[s];
        assert(tab != nullptr);

    } // default constructor
    ~ArrayList() { delete[] tab; } // destruktor

    ArrayList(const ArrayList &other) : msize(other.msize), last(other.last)
    {
        tab = new T[msize];
        assert(tab != nullptr);
        for (std::size_t i = 0; i < last; ++i)
        {
            tab[i] = other.tab[i];
        }
    } // copy constructor
    // usage:   ArrayList<int> list2(list1);

    ArrayList &operator=(const ArrayList &other)
    {
        if (this != &other)
        {
            delete[] tab;
            msize = other.msize;
            last = other.last;
            tab = new T[msize];
            assert(tab != nullptr);
            for (std::size_t i = 0; i < last; ++i)
            {
                tab[i] = other.tab[i];
            }
        }
    }; // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const
    {
        return last == 0;
    } // checks if the container has no elements

    bool full() const
    {
        return last == msize;
    } // checks if the container is full

    std::size_t size() const
    {
        return last;
    } // liczba elementow na liscie

    std::size_t max_size() const
    {
        return msize;
    } // najwieksza mozliwa liczba elementow

    void push_front(const T &item)
    {
        if (full())
        {
            std::cerr << "Lista jest pelna!" << std::endl;
        }
        else
        {
            for (std::size_t i = last; i > 0; --i)
            {
                tab[i] = tab[i - 1];
            }
            tab[0] = item;
            last++;
        }
    } // dodanie na poczatek

    void push_back(const T &item)
    {
        if (full())
        {
            std::cerr << "Lista jes pelna!" << std::endl;
        }
        else
        {
            tab[last++] = item;
        }
    } // dodanie na koniec

    T &front()
    {
        if (empty())
        {
            throw std::underflow_error("Lista jest pusta!");
        }
        return tab[0];
    } // zwraca poczatek, nie usuwa, error dla pustej listy
    T &back()
    {
        if (empty())
        {
            throw std::underflow_error("Lista jest pusta!");
        }
        return tab[last - 1];
    }; // zwraca koniec, nie usuwa, error dla pustej listy
    void pop_front()
    {
        if (empty())
        {
            throw std::underflow_error("Lista jest pusta!");
        }
        for (std::size_t i = 0; i < last - 1; ++i)
        {
            tab[i] = tab[i + 1];
        }
        last--;
    } // usuwa poczatek, error dla pustej listy
    void pop_back()
    {
        if (empty())
        {
            throw std::underflow_error("Lista jest pusta!");
        }
        else
        {
            last--;
        }
    } // usuwa koniec, error dla pustej listy
    void clear()
    {
        for (std::size_t i = 0; i < last; ++i)
        {
            tab[i] = T();
        }
        last = 0;
    } // czyszczenie listy z elementow
    void display()
    {
        std::cout << "[";
        for (std::size_t i = 0; i < last; ++i)
        {
            std::cout << tab[i];
            if (i < last - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } // lepiej zdefiniowac operator<<
    void reverse()
    {
        for (std::size_t i = 0; i < last / 2; ++i)
        {
            std::swap(tab[i], tab[last - i - 1]);
        }
    } // odwracanie kolejnosci
    void sort()
    {
        std::sort(tab, tab + last);
    } // sortowanie listy
};

#endif

// EOF