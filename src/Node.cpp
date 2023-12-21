/**
 * @file       Node.cpp
 * @brief      AVL ağacı düğümünü tutan sınıfın metot gövdelerini içeren kaynak dosyası.
 */

#include "avl/Node.hpp" // Node

Node::Node() = default;

Node::Node(const int dat, Node* left, Node* right)
    : data{dat}, leftchild{left}, rightchild{right}
{
}

// Check whether node has childs.
bool Node::isleaf() const
{
    return !(leftchild && rightchild);
}
