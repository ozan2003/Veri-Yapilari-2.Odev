/**
 * @file       ArrayList.hpp
 * @brief      Dinamik dizi veri yapısını tutan sınıf.
 */

// An array-based approach of list.
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include "array/ArrayListIterator.hpp" // ArrayListIterator
#include "pair/Pair.hpp"               // Pair

#include <cassert> // assert

const int GROWTH_FACTOR = 2;

// A dynamic array holding a pair comprised of an AVL Tree and a Stack.
class ArrayList
{
private:
    int   m_capacity{};   // Maximum size of list.
    int   m_size{};       // Current number of list elements.
    Pair* m_list_array{}; // Array holding a Pair comprised of an AVLTree and a Stack.

    void reserve();

public:
    // Default constructor.
    ArrayList();

    // Constructor with size.
    ArrayList(const int size);

    // Copy constructor.
    ArrayList(const ArrayList& other);

    // Destructor.
    ~ArrayList();

    // Copy assignment operator.
    ArrayList& operator=(const ArrayList& other);

    // Return an iterator pointing to the first element.
    ArrayListIterator begin();

    // Return an iterator pointing to the past-the-end element.
    ArrayListIterator end();

    // Replace every value with zero.
    void clear();

    // Insert "item" at given position.
    void insert(const int pos, const Pair& item);

    // Append "item".
    void append(const Pair& item);

    // Remove and return the current element.
    void remove(const int pos);

    // Return list size.
    int size() const;

    // Check if the list is empty.
    bool empty() const;

    // Return the element at position "pos".
    Pair& operator[](const int pos);

    // Return the element at position "pos" for const objects.
    const Pair& operator[](const int pos) const;
};
#endif // ARRAYLIST_HPP
