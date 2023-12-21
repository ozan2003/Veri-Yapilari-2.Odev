/**
 * @file       ArrayListIterator.cpp
 * @brief      ArrayListIterator sınıfının metot gövdelerini içeren kaynak dosyası.
 */

#include "array/ArrayListIterator.hpp" // ArrayListIterator

// Default constructor.
ArrayListIterator::ArrayListIterator() = default;

// Constructor
ArrayListIterator::ArrayListIterator(pointer ptr)
    : m_ptr{ptr}
{
}

// operator++
ArrayListIterator& ArrayListIterator::operator++()
{
    ++m_ptr;      // Pre-increment.
    return *this; // Return the updated value.
}

// operator--
ArrayListIterator& ArrayListIterator::operator--()
{
    --m_ptr;      // Pre-decrement.
    return *this; // Return the updated value.
}

// operator*
ArrayListIterator::reference ArrayListIterator::operator*()
{
    return *m_ptr; // Return the value iterator points.
}

// operator->
ArrayListIterator::pointer ArrayListIterator::operator->()
{
    return m_ptr; // Return the pointer.
}

// operator==
bool operator==(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return it1.m_ptr == it2.m_ptr; // Compare the pointers.
}

// operator!=
bool operator!=(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return !(operator==(it1, it2)); // Negate the equality operator.
}

// operator+
ArrayListIterator operator+(const ArrayListIterator& it, ArrayListIterator::difference_type n)
{
    return ArrayListIterator(it.m_ptr + n); // Return a new iterator.
}

// operator-
ArrayListIterator::difference_type operator-(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return it1.m_ptr - it2.m_ptr; // Return the difference.
}

// operator+=
ArrayListIterator& operator+=(ArrayListIterator& it, ArrayListIterator::difference_type n)
{
    it.m_ptr += n; // Update the pointer.
    return it;     // Return the updated value.
}

// operator-=
ArrayListIterator& operator-=(ArrayListIterator& it, ArrayListIterator::difference_type n)
{
    it.m_ptr -= n; // Update the pointer.
    return it;     // Return the updated value.
}

// operator[]
ArrayListIterator::reference ArrayListIterator::operator[](ArrayListIterator::difference_type n)
{
    return *(m_ptr + n); // Return the value at the specified position.
}

// operator<
bool operator<(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return it1.m_ptr < it2.m_ptr; // Compare the pointers.
}

// operator>
bool operator>(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return operator<(it2, it1); // Return the negated value of operator<.
}

// operator<=
bool operator<=(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return !(operator>(it1, it2)); // Return the negated value of operator>.
}

// operator>=
bool operator>=(const ArrayListIterator& it1, const ArrayListIterator& it2)
{
    return !(operator<(it1, it2)); // Return the negated value of operator<.
}