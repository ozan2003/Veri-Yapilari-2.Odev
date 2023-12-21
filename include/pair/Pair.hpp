/**
 * @file       Pair.hpp
 * @brief      Ağaç ve Stack veri yapılarını tutan özel bir veri yapısı.
 */

#ifndef PAIR_HPP
#define PAIR_HPP

#include "avl/AVLTree.hpp" // AVLTree
#include "stack/Stack.hpp" // Stack

// A custom type holding both an AVL Tree and a Stack, for convenience.
struct Pair
{
    AVLTree tree{};
    Stack   stack{};
    int     index{}; // Store to preserve the index in array.
};
#endif // PAIR_HPP