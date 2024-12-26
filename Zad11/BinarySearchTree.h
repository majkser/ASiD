#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <cassert>

template <typename T>
struct BSTNode
{
    // the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    // BSTNode *parent;   // używane w pewnych zastosowaniach
    //  kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    // konstruktor zwykły
    BSTNode(const T &item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode()
    {
        delete left;
        delete right;
    } // destruktor rekurencyjny
    // UWAGA Jeżeli w BSTNode będzie domyślny destruktor postaci
    // ~BSTNode() = default;
    // to wtedy destruktor drzewa i metoda clear() muszą zwolnić pamięć
    // wszystkich węzłów.
};

template <typename T>
class BinarySearchTree
{
    BSTNode<T> *root;
    BSTNode<T> *insert(BSTNode<T> *node, const T &item);
    BSTNode<T> *search(BSTNode<T> *node, const T &item) const;
    void display(BSTNode<T> *node, int level);
    T *find_min(BSTNode<T> *node);
    T *find_max(BSTNode<T> *node);

public:
    BinarySearchTree() : root(nullptr) {} // konstruktor domyślny
    ~BinarySearchTree() { delete root; }  // trzeba wyczyścić
    void clear()
    {
        delete root;
        root = nullptr;
    }
    bool empty() const { return root == nullptr; }
    T &top()
    {
        assert(root != nullptr);
        return root->value;
    } // podgląd korzenia
    void insert(const T &item) { root = insert(root, item); }
    void remove(const T &item); // usuwanie przez złączanie
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T *search(const T &item) const
    {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T *iter_search(const T &item) const
    { // wg libavl
        for (auto node = root; node != nullptr;)
        {
            if (item == node->value)
            {
                return &(node->value);
            }
            else if (item < node->value)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return nullptr;
    }
    void display() { display(root, 0); }
    T *find_min() { return find_min(root); };
    T *find_max() { return find_max(root); };
};

template <typename T>
BSTNode<T> *BinarySearchTree<T>::insert(BSTNode<T> *node, const T &item)
{
    if (node == nullptr)
    {
        return new BSTNode<T>(item);
    }
    if (item < node->value)
    {
        node->left = insert(node->left, item);
    }
    else
    {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzeń
}

template <typename T>
BSTNode<T> *BinarySearchTree<T>::search(BSTNode<T> *node, const T &item) const
{
    if (node == nullptr || node->value == item)
    {
        return node;
    }
    else if (item < node->value)
    {
        return search(node->left, item);
    }
    else
    {
        return search(node->right, item);
    }
}

template <typename T>
void BinarySearchTree<T>::display(BSTNode<T> *node, int level)
{
    if (node == nullptr)
        return;
    display(node->right, level + 1);
    std::cout << std::string(3 * level, ' ') << node->value << std::endl;
    display(node->left, level + 1);
}

template <typename T>
T *BinarySearchTree<T>::find_min(BSTNode<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    };

    while (node->left != nullptr)
    {
        node = node->left;
    }

    return &(node->value);
}

template <typename T>
T *BinarySearchTree<T>::find_max(BSTNode<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    };

    while (node->right != nullptr)
    {
        node = node->right;
    }

    return &(node->value);
}

#endif