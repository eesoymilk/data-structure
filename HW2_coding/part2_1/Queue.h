#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>

// A finite ordered list with 0 or more elements
template<class T>
class Queue
{
private:
	T* queue;
	int front, rear, capacity;
public:
	// Create an empty queue whose initial capacity is queueCapacity.
    Queue(int queueCapacity = 0);

	// If the number of elements in the queue is 0, return true,
	// else return false.
	bool IsEmpty() const { return front == rear; }

	// Return the element at the front of the queue.
	T& Front() const;

	// Return the element at the rear of the queue.
	T& Rear() const;

	// Insert item at the rear of the queue.
    void Push(const T& item);

	// Delete the front element of the queue
    void Pop();

	//
	int Size();

	//
	int Capacity();

	//
	void Print();
};

#endif
