/**
 * @file       Stack.cpp
 * @brief      Stack sınıfının metot gövdelerini içeren kaynak dosyası.
 */

#include "stack/Stack.hpp"

// Resize the stack if it's full.
void Stack::resize()
{
    m_capacity *= RESIZE_FACTOR; // Increase the capacity.

    if (m_capacity == 0) // If the capacity is zero.
    {
        m_capacity = DEFAULT_CAPACITY; // Give it an initial capacity.
    }

    int* temp = new int[m_capacity]; // Create a new stack with the given capacity.

    // Copy the items from the old stack to the new stack.
    for (int i{}; i < m_size; ++i)
    {
        temp[i] = m_storage[i];
    }

    delete[] m_storage; // Delete the old stack.
    m_storage = temp;   // Point to the new stack.
}

// Default constructor.
Stack::Stack() = default;

// Constructor with given size.
Stack::Stack(const int size)
    : m_size{size}, m_capacity{size * RESIZE_FACTOR}, m_storage{new int[m_capacity]{}}
{
}

// Destructor.
Stack::~Stack()
{
    delete[] m_storage; // Delete the array holding the stack.
}

// Copy constructor.
Stack::Stack(const Stack& other)
    : m_size{other.m_size}, m_capacity{other.m_capacity}, m_storage{new int[m_capacity]{}}
{
    // Copy the items from the other stack to this stack.
    for (int i{}; i < m_size; ++i)
    {
        m_storage[i] = other.m_storage[i];
    }
}

// Copy assignment operator.
Stack& Stack::operator=(const Stack& other)
{
    if (this != &other) // Check for self-assignment.
    {
        delete[] m_storage; // Delete the old stack.

        m_size     = other.m_size;        // Copy the size.
        m_capacity = other.m_capacity;    // Copy the capacity.
        m_storage  = new int[m_capacity]; // Create a new stack with the given capacity.

        // Copy the items from the other stack to this stack.
        for (int i{}; i < m_size; ++i)
        {
            m_storage[i] = other.m_storage[i];
        }
    }
    return *this; // Return this stack.
}

// Add item to the top of the stack.
void Stack::push(const int item)
{
    // If the stack is full, resize it.
    if (m_size >= m_capacity)
    {
        resize();
    }
    m_storage[m_size++] = item; // Add item to the top of the stack.
}

// Remove item from the top of the stack.
int Stack::pop()
{
    int item = m_storage[--m_size]; // Remove item from the top of the stack.

    return item; // Return the item.
}

// Check if the stack is empty.
bool Stack::empty() const
{
    return m_size == 0;
}

// Return the size of the stack.
int Stack::size() const
{
    return m_size;
}

// Return the top item of the stack.
int Stack::top() const
{
    return m_storage[m_size - 1];
}
