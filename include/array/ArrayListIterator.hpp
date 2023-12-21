/**
 * @file       ArrayListIterator.hpp
 * @brief      C++ standart kütüphane algoritmalarının verimli kullanımı için yazılmış bir İteratör sınıfı.
 */

#ifndef ARRAYLISTITERATOR_HPP
#define ARRAYLISTITERATOR_HPP

#include "pair/Pair.hpp" // Pair

#include <cstddef>  // std::ptrdiff_t
#include <iterator> // std::random_access_iterator_tag

// This class is used in order to be compliant with the STL algorithms.
class ArrayListIterator
{
public:
    // std::random_access_iterator_tag since we're using array, which is a random access container.
    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = Pair;
    using pointer           = Pair*;
    using reference         = Pair&;

    // Default constructor.
    ArrayListIterator();

    // Constructor with pointer.
    ArrayListIterator(pointer ptr);

    // To move one position forward. (Pre-increment)
    ArrayListIterator& operator++();

    // To move one position backward. (Pre-decrement)
    ArrayListIterator& operator--();

    // To get the value at the current iterator position.
    reference operator*();

    // To point at the current iterator position.
    pointer operator->();

    // To compare iterators for equality.
    friend bool operator==(const ArrayListIterator& it1, const ArrayListIterator& it2);

    // To compare iterators for inequality.
    friend bool operator!=(const ArrayListIterator& it1, const ArrayListIterator& it2);

    // To move the iterator forward by a certain amount.
    friend ArrayListIterator operator+(const ArrayListIterator& it, difference_type n);

    // To get the distance between two iterators.
    friend difference_type operator-(const ArrayListIterator& it1, const ArrayListIterator& it2);

    // To move the iterator forward by a certain amount.
    friend ArrayListIterator& operator+=(ArrayListIterator& it, ArrayListIterator::difference_type n);

    // To move the iterator backward by a certain amount.
    friend ArrayListIterator& operator-=(ArrayListIterator& it, ArrayListIterator::difference_type n);

    // To get the value at a certain position.
    reference operator[](ArrayListIterator::difference_type n);

    // To compare the iterators.
    friend bool operator<(const ArrayListIterator& it1, const ArrayListIterator& it2);
    friend bool operator>(const ArrayListIterator& it1, const ArrayListIterator& it2);
    friend bool operator<=(const ArrayListIterator& it1, const ArrayListIterator& it2);
    friend bool operator>=(const ArrayListIterator& it1, const ArrayListIterator& it2);

private:
    pointer m_ptr{nullptr};
};

#endif // ARRAYLISTITERATOR_HPP