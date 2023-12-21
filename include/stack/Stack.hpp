/**
 * @file       Stack.hpp
 * @brief      Stack veri yapısını tutan sınıf şablonu.
 */

#ifndef STACK_HPP
#define STACK_HPP

constexpr int DEFAULT_CAPACITY{1}; // Default capacity of the stack.
constexpr int RESIZE_FACTOR{2};    // Resize factor of the stack.

class Stack
{
    int  m_size{DEFAULT_CAPACITY};           // Size of the stack.
    int  m_capacity{m_size * RESIZE_FACTOR}; // Capacity of the stack.
    int* m_storage{new int[m_capacity]};     // Pointer to the stack.

    void resize(); // Resize the stack if it's full.

public:
    // Default constructor.
    Stack();

    // Constructor with given size.
    Stack(const int size);

    // Destructor.
    ~Stack();

    // Copy constructor.
    Stack(const Stack& other);

    // Copy assignment operator.
    Stack& operator=(const Stack& other);

    // Add item to the top of the stack.
    void push(const int item);

    // Remove item from the top of the stack.
    int pop();

    // Check if the stack is empty.
    bool empty() const;

    // Return the size of the stack.
    int size() const;

    int top() const;
};

#endif // STACK_HPP