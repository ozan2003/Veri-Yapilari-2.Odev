/**
 * @file       AVLTree.hpp
 * @brief      AVL ağacı veri yapısını tutan sınıf.
 */

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Node.hpp"        // Node
#include "stack/Stack.hpp" // Stack
#include "to_ascii.hpp"    // to_ascii

#include <algorithm> // std::max
#include <iostream>  // std::cout

class AVLTree
{
private:
    Node* m_root{nullptr};
    int   m_count{};

    // Helper functions.
    int height(Node* node);

    int   balance_factor(Node* node);
    Node* rotate_right(Node* y);
    Node* rotate_left(Node* x);
    Node* balance(Node* root);

    Node* insert_helper(Node* root, const int item);
    Node* remove_helper(Node* root, const int item);
    void  print_helper(Node* root) const;
    void  clear_helper(Node* root);
    int   find_helper(Node* root, const int item) const;
    void  insert_leaves_to_helper(Node* root, Stack& st);
    void  sum_helper(Node* root, int& accumulator) const;

    Node* min(Node* root);

public:
    AVLTree();

    ~AVLTree();

    void clear();

    Node* insert(const int item);

    int remove(const int item);

    int find(const int item) const;

    int size() const;

    bool empty() const;

    void print() const;

    void insert_leaves_to(Stack& st);

    int sum() const;
};
#endif // AVLTREE_HPP
