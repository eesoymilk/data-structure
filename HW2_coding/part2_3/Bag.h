#ifndef BAG_H
#define BAG_H

#include <iostream>

// Bag template class
template <class T>
class Bag
{
public:
    Bag(int bagCapacity = 10);
    ~Bag() { delete[] array; }

    virtual int Size() = 0;
    virtual bool IsEmpty() const = 0;

    virtual void Push(const T &item) = 0;
    virtual T Pop() = 0;

protected:
    T *array;
    int capacity, top = -1;
};

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
    if (capacity < 1) throw "Bag Capacity must be > 0";
    array = new T[capacity];
    std::fill(array, array + capacity, 0);
}

// Stack template class
template <class T>
class Stack : public Bag<T>
{
    using Bag<T>::array;
    using Bag<T>::capacity;
    using Bag<T>::top;

public:
    Stack(int stackCapacity = 10) : Bag<T>{stackCapacity} {}
    ~Stack() {}

    // virtual
    int Size() { return top + 1; }
    inline bool IsEmpty() const { return top == -1; }
    void Push(const T &item);
    T Pop();
};

// Queue templat class
template <class T>
class Queue : public Bag<T>
{
    using Bag<T>::array;
    using Bag<T>::capacity;

private:
    int front = 0, rear = 0;

public:
    Queue(int queueCapacity = 10) : Bag<T>{queueCapacity} {}
    ~Queue() {}
    int Size();
    inline bool IsEmpty() const { return front == rear; }
    void Push(const T &item);
    T Pop();
};

template <class T>
int Queue<T>::Size()
{
    int size = rear - front;
    return size > 0 ? size : size + capacity;
}

template <class T>
void Queue<T>::Push(const T &x)
{
    std::cout << "Pushing from quque...\n";
    if ((rear + 1) % capacity == front) {
        int new_capacity = capacity * 2;
        T *new_queue = new T[new_capacity];
        std::fill(new_queue, new_queue + new_capacity, 0);
        int start = (front + 1) % capacity;
        if (start < 2)
            std::copy(array + start, array + start + capacity - 1, new_queue);
        else {
            std::copy(array + start, array + capacity, new_queue);
            std::copy(array, array + rear + 1, new_queue + capacity - start);
        }
        front = new_capacity - 1;
        rear = capacity - 2;
        capacity = new_capacity;
        delete[] array;
        array = new_queue;
    }
    rear = (rear + 1) % capacity;
    array[rear] = x;
}

template <class T>
T Queue<T>::Pop()
{
    if (IsEmpty()) throw "Queue is empty. Cannot delete.";
    front = (front + 1) % capacity;
    return array[front];
}

#endif
