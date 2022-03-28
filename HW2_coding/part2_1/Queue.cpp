#include "Queue.h"

template<class T>
Queue<T>::Queue(int queueCapacity)
	: capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue Capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template<class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "Queue is empty. No front element.";
	return queue[(front + 1) % capacity];
}

template<class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty()) throw "Queue is empty. No rear element.";
	return queue[rear];
}

template<class T>
void Queue<T>::Push(const T& x)
{
	if ((rear + 1) % capacity == front) {
		capacity *= 2;
		T* new_queue = new T[capacity];
		memcpy(new_queue, queue, sizeof queue);
		delete[] queue;
		queue = new_queue;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template<class T>
void Queue<T>::Print()
{
	std::cout << ">>> ";
	for (auto ele : queue) std::cout << ele << ' ';
	std::cout << '\n';
}

template class Queue<int>;
