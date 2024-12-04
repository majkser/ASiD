#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

template <typename T>
class PriorityQueue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue()
    {
        clear();
    }

    PriorityQueue(const PriorityQueue &other) : head(nullptr)
    {
        if (other.head)
        {
            head = new Node(other.head->data);
            Node *current = head;
            Node *otherCurrent = other.head->next;

            while (otherCurrent)
            {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    PriorityQueue &operator=(const PriorityQueue &other)
    {
        if (this != &other)
        {
            clear();
            if (other.head)
            {
                head = new Node(other.head->data);
                Node *current = head;
                Node *otherCurrent = other.head->next;

                while (otherCurrent)
                {
                    current->next = new Node(otherCurrent->data);
                    current = current->next;
                    otherCurrent = otherCurrent->next;
                }
            }
        }
        return *this;
    }

    void push(const T &value)
    {
        if (!head || value > head->data)
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next && value <= current->next->data)
        {
            current = current->next;
        }
        Node *newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }

    void pop()
    {
        if (!head)
        {
            throw std::runtime_error("Priority queue is empty");
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    T top() const
    {
        if (!head)
        {
            throw std::runtime_error("Priority queue is empty");
        }
        return head->data;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() const
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif