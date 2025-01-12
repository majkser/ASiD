#ifndef RANDOMBINARYTREE_H
#define RANDOMBINARYTREE_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stack>

// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
struct BSTNode
{
    T value;
    BSTNode *left;
    BSTNode *right;

    BSTNode(const T &val) : value(val), left(nullptr), right(nullptr) {}
    ~BSTNode()
    {
        delete left;
        delete right;
    }
};

template <typename T>
class RandomBinaryTree
{
    BSTNode<T> *root;
    BSTNode<T> *insert(BSTNode<T> *node, const T &item);
    void display(BSTNode<T> *node, int level);
    T recurcive_calc_leaves(BSTNode<T> *node);
    T iterative_calc_leaves(BSTNode<T> *node);
    T recursive_calc_total(BSTNode<T> *node);
    T iterative_calc_total(BSTNode<T> *node);

public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { delete root; }  // trzeba wyczyścić (rekurencyjnie)
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
    void display() { display(root, 0); }

    T recurcive_calc_leaves() { return recurcive_calc_leaves(root); }
    T iterative_calc_leaves() { return iterative_calc_leaves(root); }
    T recursive_calc_total() { return recursive_calc_total(root); }
    T iterative_calc_total() { return iterative_calc_total(root); }
};

template <typename T>
BSTNode<T> *RandomBinaryTree<T>::insert(BSTNode<T> *node, const T &item)
{
    if (node == nullptr)
    {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2)
    { // można lepiej
        node->left = insert(node->left, item);
    }
    else
    {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzeń
}

template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level)
{
    if (node == nullptr)
        return;
    display(node->right, level + 1);
    std::cout << std::string(3 * level, ' ') << node->value << std::endl;
    display(node->left, level + 1);
}

template <typename T>
T RandomBinaryTree<T>::recurcive_calc_leaves(BSTNode<T> *node)
{
    if (!node)
    {
        return 0;
    }
    if (node->right == nullptr && node->left == nullptr)
    {
        return 1;
    }

    return recurcive_calc_leaves(node->left) + recurcive_calc_leaves(node->right);
}

template <typename T>
T RandomBinaryTree<T>::iterative_calc_leaves(BSTNode<T> *node)
{
    std::stack<BSTNode<T> *> stack;
    stack.push(root);
    T result = 0;
    while (!stack.empty())
    {
        node = stack.top();
        stack.pop();

        if (node->right == nullptr && node->left == nullptr)
        {
            result++;
        }
        else
        {
            if (node->right != nullptr)
            {
                stack.push(node->right);
            }
            if (node->left != nullptr)
            {
                stack.push(node->left);
            }
        }
    }
    return result;
}

template <typename T>
T RandomBinaryTree<T>::recursive_calc_total(BSTNode<T> *node)
{
    if (!node)
    {
        return 0;
    }
    else
    {
        return node->value + recursive_calc_total(node->left) + recursive_calc_total(node->right);
    }
}

template <typename T>
T RandomBinaryTree<T>::iterative_calc_total(BSTNode<T> *node)
{
    std::stack<BSTNode<T> *> stack;
    stack.push(root);
    T result = 0;
    while (!stack.empty())
    {
        node = stack.top();
        stack.pop();

        if (node)
        {
            result += node->value;
        }
        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
    }

    return result;
}

#endif