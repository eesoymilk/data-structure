#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T>
class Queue;

template <class T>
Queue<T> Merge(Queue<T> q1, Queue<T> q2);

template <class T>
std::ostream &operator<<(std::ostream &out, const Queue<T> &q);

// A finite ordered list with 0 or more elements
template <class T>
class Queue
{
private:
    T *queue;
    int front, rear, capacity;

public:
    // Create an empty queue whose initial capacity is queueCapacity.
    Queue(int queueCapacity = 1);

    // If the number of elements in the queue is 0, return true,
    // else return false.
    inline bool IsEmpty() const { return front == rear; }

    // Return the element at the front of the queue.
    T &Front() const;

    // Return the element at the rear of the queue.
    T &Rear() const;

    // Insert item at the rear of the queue.
    void Push(const T &item);

    // Delete the front element of the queue
    T Pop();

    //
    int Size();

    //
    inline int Capacity() { return capacity; }

    //
    void PrintRaw();

    friend Queue Merge<T>(Queue<T> q1, Queue<T> q2);

    friend std::ostream &operator<<<T>(std::ostream &out, const Queue<T> &q);
    // friend Queue Merge<T>(Queue<T> q1, Queue<T> q2)
    // {
    //     std::cout << "Merging...\n";
    // };
    // friend Queue Merge<>(Queue q1, Queue q2);
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
    if (capacity < 1) throw "Queue Capacity must be > 0";
    queue = new T[capacity];
    std::fill(queue, queue + capacity, 0);
    front = rear = 0;
}

template <class T>
inline T &Queue<T>::Front() const
{
    if (IsEmpty()) throw "Queue is empty. No front element.";
    return queue[(front + 1) % capacity];
}

template <class T>
inline T &Queue<T>::Rear() const
{
    if (IsEmpty()) throw "Queue is empty. No rear element.";
    return queue[rear];
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
            std::copy(queue + start, queue + start + capacity - 1, new_queue);
        else {
            std::copy(queue + start, queue + capacity, new_queue);
            std::copy(queue, queue + rear + 1, new_queue + capacity - start);
        }
        front = new_capacity - 1;
        rear = capacity - 2;
        capacity = new_capacity;
        delete[] queue;
        queue = new_queue;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = x;
}

template <class T>
T Queue<T>::Pop()
{
    if (IsEmpty()) throw "Queue is empty. Cannot delete.";
    front = (front + 1) % capacity;
    return queue[front];
}

template <class T>
int Queue<T>::Size()
{
    int size = rear - front;
    return size > 0 ? size : size + capacity;
}

template <class T>
void Queue<T>::PrintRaw()
{
    std::cout << ">>> ";
    for (size_t i = 0; i < capacity; i++) std::cout << queue[i] << ' ';
    std::cout << '\n';
}

template <class T>
Queue<T> Merge(Queue<T> q1, Queue<T> q2)
{
    std::cout << "Merging In...\n";

    Queue<T> merged_queue;
    int q1_front = q1.front, q2_front = q2.front;
    while (true) {
        if (!q1.IsEmpty()) merged_queue.Push(q1.Pop());
        if (!q2.IsEmpty()) merged_queue.Push(q2.Pop());
        if (q1.IsEmpty() && q2.IsEmpty()) break;
    }
    q1.front = q1_front;
    q2.front = q2_front;
    return merged_queue;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const Queue<T> &q)
{
    if (q.IsEmpty()) throw "The queue is empty, nothing to print.";

    size_t start = (q.front + 1) % q.capacity;
    size_t end = start < q.rear ? q.rear : q.capacity - 1;

    for (size_t i = start; i <= end; i++)
        out << q.queue[i] << " \0"[i == end && start < q.rear ? 1 : 0];

    if (start > q.rear)
        for (size_t i = 0; i <= q.rear; i++)
            out << q.queue[i] << " \0"[i == end ? 1 : 0];

    return out;
}

#endif
