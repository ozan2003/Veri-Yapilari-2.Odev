/**
 * @file       ArrayList.cpp
 * @brief      ArrayList sınıfının metot gövdelerini içeren kaynak dosyası.
 */

#include "array/ArrayList.hpp" // ArrayList

void ArrayList::reserve()
{
    m_capacity *= GROWTH_FACTOR;

    // If the array is empty.
    if (m_capacity == 0)
    {
        m_capacity = 2; // Give it an initial capacity.
    }

    Pair* temp = new Pair[m_capacity]; // Allocate new array in the heap.

    for (int i{}; i < m_size; ++i)
    {
        temp[i] = m_list_array[i]; // Copy all items of original array.
    }

    delete[] m_list_array; // Get rid of the original array.
    m_list_array = temp;   // "temp" is our new array now.
}

// Default constructor.
ArrayList::ArrayList() = default;

// Constructor.
ArrayList::ArrayList(const int size)
    : m_capacity{size * GROWTH_FACTOR},
      m_size{size},
      m_list_array{new Pair[m_capacity]{}} // ArrayList elements are zero initialized by default.
{
}

// Copy constructor.
ArrayList::ArrayList(const ArrayList& other)
    : m_capacity{other.m_capacity}, m_size{other.m_size}, m_list_array{new Pair[other.m_capacity]{}}
{
    for (int i{}; i < m_size; ++i)
    {
        m_list_array[i] = other.m_list_array[i];
    }
}

// Destructor.
ArrayList::~ArrayList()
{
    delete[] m_list_array;
}

// Assignment operator.
ArrayList& ArrayList::operator=(const ArrayList& other)
{
    // Check for self-assignment.
    if (this != &other)
    {
        // Deallocate the existing array.
        delete[] m_list_array;

        // Copy the capacity and size.
        m_capacity = other.m_capacity;
        m_size     = other.m_size;

        // Allocate a new array.
        m_list_array = new Pair[m_capacity];

        // Copy the elements from the other ArrayList.
        for (int i{}; i < m_size; ++i)
        {
            m_list_array[i] = other.m_list_array[i];
        }
    }
    return *this;
}

// Clear the array.
void ArrayList::clear()
{
    delete[] m_list_array; // Remove the array.
    // m_size = 0;                         // Reset the size.

    m_list_array = new Pair[m_capacity]{}; // Recreate array with zeroes.
}

// Insert "item" at given position.
void ArrayList::insert(const int pos, const Pair& item)
{
    if (m_size == m_capacity)
    {
        reserve();
    }
    assert(0 <= pos && pos < m_size && "Out of range.\n");

    for (int s{m_size}; pos < s; --s) // Shift elements up...
    {
        m_list_array[s] = m_list_array[s - 1]; // ...to make room.
    }
    /// DEMONSTRATION
    // ┌────┬────┬────┬────┬────┬────┬────┐
    // │i[0]│i[1]│i[2]│i[3]│i[4]│i[5]│i[6]│	   // INDEXES
    // ├────┼────┼────┼────┼────┼────┼────┤
    // │10  │20  │30  │40  │50  │60  │    │	   // ITEMS
    // ├────┼────┼────┼────┼────┼────┼────┤
    // │    │10  │20  │30  │40  │50  │60  │	   // SHIFT ELEMENTS UP
    // ├────┼────┼────┼────┼────┼────┼────┤
    // │item│10  │20  │30  │40  │50  │60  │	   // INSERT "item"
    // └────┴────┴────┴────┴────┴────┴────┘
    //
    m_list_array[pos] = item;

    m_size++; // Increment list size.
}

// Append "item".
void ArrayList::append(const Pair& item)
{
    // If the array is full, reserve more space.
    if (m_size == m_capacity)
    {
        reserve();
    }
    // assert(m_size < m_capacity && "List capacity exceeded.\n");

    // Append the item to the end of the array.
    m_list_array[m_size++] = item;
}

// Remove and return the current element.
void ArrayList::remove(const int pos)
{
    // assert(0 <= pos && pos < m_size && "No element.\n");

    // m_size - 1, because we're dealing with array indexes.
    for (int i{pos}; i < m_size - 1; ++i)
    {
        m_list_array[i] = m_list_array[i + 1]; // Shift elements down.
    }
    /// DEMONSTRATION
    // ┌────┬────┬────┬────┬────┬────┬────┐
    // │i[0]│i[1]│i[2]│i[3]│i[4]│i[5]│i[6]│     // INDEXES
    // ├────┼────┼────┼────┼────┼────┼────┤
    // │10  │item│20  │30  │40  │50  │60  │     // ITEMS
    // ├────┼────┼────┼────┼────┼────┼────┤
    // │10  │20  │30  │40  │50  │60  │... │     // SHIFT ELEMENTS DOWN
    // └────┴────┴────┴────┴────┴────┴────┘
    //
    m_size--; // Decrement size.
}

// Return list size.
int ArrayList::size() const
{
    return m_size;
}

bool ArrayList::empty() const
{
    return size() == 0;
}

// Return the current element.
Pair& ArrayList::operator[](const int pos)
{
    assert(!empty() && "No current element.\n");
    return m_list_array[pos];
}

// Return the current element.
const Pair& ArrayList::operator[](const int pos) const
{
    assert(!empty() && "No current element.\n");
    return m_list_array[pos];
}

// begin() function.
ArrayListIterator ArrayList::begin()
{
    return ArrayListIterator(m_list_array); // m_list_array -> &m_list_array[0]
}

// end() function.
ArrayListIterator ArrayList::end()
{
    // m_list_array + m_size points to the element after the last element.
    return ArrayListIterator(m_list_array + m_size);
}
