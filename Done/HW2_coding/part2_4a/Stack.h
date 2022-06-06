#ifndef STACK_H
#define STACK_H

#include <iostream>

// Stack Template Class
template <class T>
class Stack
{
private:
    T *stack;
    int top = -1, capacity;

public:
    // Create an empty stack whose initial capacity is stackCapacity.
    Stack(int stackCapacity = 1);

    // If the number of elements in the stack is 0, return true,
    // else return false.
    inline bool IsEmpty() const { return top == -1; }

    // Insert item at the rear of the stack.
    void Push(const T &item);

    // Delete the front element of the stack
    void Pop();

    // Return the element at the Top of the stack.
    T &Top() const;

    //
    inline int Size() { return top + 1; }

    //
    inline int Capacity() { return capacity; }
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
    if (capacity < 1) throw "Stack Capacity must be > 0";
    stack = new T[capacity];
    // std::fill(stack, stack + capacity, 0);
}

template <class T>
void Stack<T>::Push(const T &x)
{
    if (top + 1 == capacity) {
        int new_capacity = capacity * 2;
        T *new_stack = new T[new_capacity];
        // std::fill(new_stack, new_stack + new_capacity, 0);
        std::copy(stack, stack + capacity, new_stack);
        capacity = new_capacity;
        delete[] stack;
        stack = new_stack;
    }
    stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty()) throw "Stack is empty. Cannot delete.";
    top--;
}

template <class T>
inline T &Stack<T>::Top() const
{
    if (IsEmpty()) throw "Stack is empty. No top element.";
    return stack[top];
}

#endif
