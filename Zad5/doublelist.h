// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert>  // assert()

template <typename T>
struct DoubleNode
{
    // the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T &item, DoubleNode *nptr = nullptr, DoubleNode *pptr = nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {}                             // destruktor
};

template <typename T>
class DoubleList
{
    DoubleNode<T> *head, *tail;

public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList()
    {
        clear();
    } // tu trzeba wyczyscic wezly

    DoubleList(const DoubleList &other)
    {
        head = tail = nullptr;

        DoubleNode<T> *current = other.head;
        while (current != nullptr)
        {
            push_back(current->value);
            current = current->next;
        }

    } // copy constructor
    // usage:   DoubleList<int> list2(list1);

    DoubleList(DoubleList &&other); // move constructor NIEOBOWIAZKOWE
    // usage:   DoubleList<int> list2(std::move(list1));

    DoubleList &operator=(const DoubleList &other)
    {
        head = tail = nullptr;

        if (this == &other)
        {
            return *this;
        }

        clear();

        DoubleNode<T> *current = other.head;
        while (current != nullptr)
        {
            push_back(current->value);
            current = current->next;
        }

        return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;

    DoubleList &operator=(DoubleList &&other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const { return head == nullptr; }

    std::size_t size() const
    {

        std::size_t counter = 0;

        DoubleNode<T> *current = head;

        while (current != nullptr)
        {
            counter++;
            current = current->next;
        }

        return counter;
    } // O(n) bo trzeba policzyc

    void push_front(const T &item)
    {
        DoubleNode<T> *newNode = new DoubleNode<T>(item, head, nullptr);

        if (!empty())
        {
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    } // O(1)

    // void push_front(T &&item); // O(1) NIEOBOWIAZKOWE

    void push_back(const T &item)
    {
        DoubleNode<T> *newNode = new DoubleNode<T>(item, nullptr, tail);

        if (!empty())
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    } // O(1)

    // void push_back(T &&item); // O(1) NIEOBOWIAZKOWE

    T &front() const
    {
        return head->value;
    } // zwraca poczatek, nie usuwa

    T &back() const
    {
        return tail->value;
    } // zwraca koniec, nie usuwa

    void pop_front()
    {
        DoubleNode<T> *current = head;

        if (!empty())
        {
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete current;
        }

    } // usuwa poczatek O(1)

    void pop_back()
    {
        DoubleNode<T> *current = tail;

        if (!empty())
        {
            tail = tail->prev;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }

            delete current;
        }

    } // usuwa koniec O(1)

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    } // czyszczenie listy z elementow O(n)

    void display()
    {
        DoubleNode<T> *current = head;

        while (current != nullptr)
        {
            std::cout << current->value << " ";

            current = current->next;
        }
    } // O(n)

    void display_reversed()
    {
        DoubleNode<T> *current = tail;

        while (current != nullptr)
        {
            std::cout << current->value << " ";

            current = current->prev;
        }

    } // O(n)

    // Operacje z indeksami. NIEOBOWIAZKOWE
    /*T &operator[](std::size_t pos);             // podstawienie L[pos]=item, odczyt L[pos]
    const T &operator[](std::size_t pos) const; // dostep do obiektu const
    void erase(std::size_t pos);
    int index(const T &item);                    // jaki index na liscie (-1 gdy nie ma) O(n)
    void insert(std::size_t pos, const T &item); // inserts item before pos,
    void insert(std::size_t pos, T &&item);*/
    // inserts item before pos,
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
};

#endif

// EOF