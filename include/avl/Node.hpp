/**
 * @file       Node.hpp
 * @brief      AVL ağacı düğümünü tutan sınıf.
 */

#ifndef NODE_HPP
#define NODE_HPP

// An AVL Tree node holding an int.
struct Node
{
    int   data{};
    Node* leftchild{nullptr};
    Node* rightchild{nullptr};
    /*
     *  Height of the node is the longest path down to a leaf.
     *  Height = max(height(leftchild), height(rightchild)) + 1
     */
    int height{};

    Node();

    Node(const int dat, Node* left = nullptr, Node* right = nullptr);

    // Check whether node has childs.
    bool isleaf() const;
};
#endif // NODE_HPP
