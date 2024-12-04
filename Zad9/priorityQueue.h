#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <memory>

template <typename T>
class PriorityQueue
{
private:
    struct Node
    {
        T data;
        std::unique_ptr<Node> next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    PriorityQueue() = default;

    PriorityQueue(const PriorityQueue &other)
    {
        if (other.head)
        {
            head = std::make_unique<Node>(other.head->data);
            Node *current = head.get();
            Node *otherCurrent = other.head->next.get();

            while (otherCurrent)
            {
                current->next = std::make_unique<Node>(otherCurrent->data);
                current = current->next.get();
                otherCurrent = otherCurrent->next.get();
            }
        }
    } // copy constructor

    PriorityQueue &operator=(const PriorityQueue &other)
    {
        if (this != &other)
        {
            head.reset();

            if (other.head)
            {
                head = std::make_unique<Node>(other.head->data);
                Node *current = head.get();
                Node *otherCurrent = other.head->next.get();

                while (otherCurrent)
                {
                    current->next = std::make_unique<Node>(otherCurrent->data);
                    current = current->next.get();
                    otherCurrent = otherCurrent->next.get();
                }
            }
        }
        return *this;
    } // Copy assignment operator, return *this

    void push(const T &value)
    {
        if (!head || value > head->data)
        {
            auto newNode = std::make_unique<Node>(value);
            newNode->next = std::move(head);
            head = std::move(newNode);
            return;
        }

        Node *current = head.get();
        while (current->next && value <= current->next->data)
        {
            current = current->next.get();
        }

        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
    }

    void pop()
    {
        if (head)
        {
            head = std::move(head->next);
        }
    }

    T top() const
    {
        if (!head)
        {
            throw std::out_of_range("Priority queue is empty");
        }
        return head->data;
    }

    bool empty() const
    {
        return !head;
    }

    void clear()
    {
        head.reset();
    }

    void display()
    {
        Node *current = head.get();

        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next.get();
        }

        std::cout << std::endl;
    }
};

#endif // PRIORITYQUEUE_H