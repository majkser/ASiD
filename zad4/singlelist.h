// singlelist.h

#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert>  // assert()

template <typename T>
struct SingleNode
{
    // the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T &item, SingleNode *ptr = nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList
{
    SingleNode<T> *head, *tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList()
    {
        clear();
    } // tu trzeba wyczyscic wezly

    SingleList(const SingleList &other) : head(nullptr), tail(nullptr)
    {
        SingleNode<T> *current = other.head;
        while (current != nullptr)
        {
            push_back(current->value);
            current = current->next;
        }
    } // copy constructor
    // usage:   SingleList<int> list2(list1);

    SingleList(SingleList &&other) : head(other.head), tail(other.tail)
    {
        head.other = nullptr;
        tail.other = nullptr;
    } // move constructor NIEOBOWIAZKOWE
    // usage:   SingleList<int> list2(std::move(list1));

    SingleList &operator=(const SingleList &other)
    {
        if (this == &other)
        {
            return *this;
        }

        clear();

        SingleNode<T> *current = other.head;
        while (current != nullptr)
        {
            push_back(current->value);
            current = current->next;
        }
        return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;

    SingleList &operator=(SingleList &&other)
    {
        if (this == &other)
        {
            return *this;
        }

        clear();

        head = other.head;
        tail = other.tail;

        other.head = nullptr;
        other.tail = nullptr;

        return *this;

    } // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const
    {
        return head == nullptr;
    }

    std::size_t size() const
    {
        std::size_t counter = 0;

        SingleNode<T> *current = head;
        while (current != nullptr)
        {
            counter++;
            current = current->next;
        }

        return counter;
    } // O(n) bo trzeba policzyc

    void push_front(const T &item)
    {
        SingleNode<T> *newNode = new SingleNode<T>(item, head);

        head = newNode;

        if (tail == nullptr)
        {
            tail = newNode;
        }
    } // O(1), L.push_front(item)

    void push_front(T &&item)
    {
        SingleNode<T> *newNode = new SingleNode<T>(std::move(item), head);

        head = newNode;

        if (tail == nullptr)
        {
            tail = newNode;
        }
    } // O(1), L.push_front(std::move(item)) NIEOBOWIAZKOWE

    void push_back(const T &item)
    {
        SingleNode<T> *newNode = new SingleNode<T>(item, nullptr);

        if (tail != nullptr)
        {
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }

        tail = newNode;
    } // O(1), L.push_back(item)

    void push_back(T &&item)
    {
        SingleNode<T> *newNode = new SingleNode<T>(std::move(item), nullptr);

        if (tail != nullptr)
        {
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }

        tail = newNode;
    } // O(1), L.push_back(std::move(item)) NIEOBOWIAZKOWE

    T &front() const
    {
        assert(head != nullptr && "Lista jest pusta");
        return head->value;
    } // zwraca poczatek, nie usuwa

    T &back() const
    {
        assert(tail != nullptr && "Lista jest pusta");
        return tail->value;
    } // zwraca koniec, nie usuwa

    void pop_front()
    {
        SingleNode<T> *temp = head;
        head = head->next;

        delete temp;

        if (head == nullptr)
        {
            tail = nullptr;
        }

    } // usuwa poczatek O(1)

    void pop_back()
    {
        SingleNode<T> *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }

        delete tail;

        tail = current;
        tail->next = nullptr;

    } // usuwa koniec O(n)

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    } // czyszczenie listy z elementow O(n)

    void display()
    {
        SingleNode<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
    } // O(n)
    void reverse()
    {
        SingleNode<T> *current = head;
        SingleNode<T> *prev = nullptr;
        SingleNode<T> *next = nullptr;

        tail = head;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    } // O(n)
};

#endif