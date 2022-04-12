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
    virtual void Pop() = 0;
    void PrintRaw()
    {
        std::cout << ">>> ";
        for (size_t i = 0; i < capacity; i++) std::cout << array[i] << ' ';
        std::cout << '\n';
    }

protected:
    T *array;
    int capacity;
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
private:
    using Bag<T>::array;
    using Bag<T>::capacity;
    int top = -1;

public:
    Stack(int stackCapacity = 10) : Bag<T>{stackCapacity} {}
    ~Stack() {}

    // virtual
    int Size() { return top + 1; }
    inline bool IsEmpty() const { return top == -1; }
    void Push(const T &item);
    void Pop();

    // stack method
    T &Top() const;
};

template <class T>
void Stack<T>::Push(const T &x)
{
    if (top + 1 == capacity) {
        int new_capacity = capacity * 2;
        T *new_stack = new T[new_capacity];
        std::fill(new_stack, new_stack + new_capacity, 0);
        std::copy(array, array + capacity, new_stack);
        capacity = new_capacity;
        delete[] array;
        array = new_stack;
    }
    array[++top] = x;
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
    return array[top];
}

// Queue templat class
template <class T>
class Queue : public Bag<T>
{
protected:
    using Bag<T>::array;
    using Bag<T>::capacity;
    int front = 0, rear = 0;

public:
    Queue(int queueCapacity = 10) : Bag<T>{queueCapacity} {}
    ~Queue() {}
    int Size();
    inline bool IsEmpty() const { return front == rear; }
    void Push(const T &item);
    void Pop();
    T &Front() const;
    T &Rear() const;
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
void Queue<T>::Pop()
{
    if (IsEmpty()) throw "Queue is empty. Cannot delete.";
    front = (front + 1) % capacity;
}

template <class T>
inline T &Queue<T>::Front() const
{
    if (IsEmpty()) throw "Queue is empty. No front element.";
    return array[(front + 1) % capacity];
}

template <class T>
inline T &Queue<T>::Rear() const
{
    if (IsEmpty()) throw "Queue is empty. No rear element.";
    return array[rear];
}

// Deque templat class
template <class T>
class Deque : public Queue<T>
{
    using Queue<T>::capacity;
    using Queue<T>::array;
    using Queue<T>::front;
    using Queue<T>::rear;

public:
    Deque(int dequeCapacity = 10) : Queue<T>{dequeCapacity} {}
    ~Deque() {}
    void PushFront(const T &x);
    void PopBack();
};

template <class T>
void Deque<T>::PushFront(const T &x)
{
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
    array[front] = x;
    front = front == 0 ? capacity - 1 : front - 1;
}

template <class T>
void Deque<T>::PopBack()
{
    if (this->IsEmpty()) throw "Deque is empty. Cannot delete.";
    rear = rear == 0 ? capacity - 1 : rear - 1;
}

#endif
