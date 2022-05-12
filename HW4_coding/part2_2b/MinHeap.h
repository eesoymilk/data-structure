#pragma once

#include <iostream>
#include <vector>

template <class T>
class MinHeap;

template <class T>
std::ostream& operator<<(std::ostream&, const MinHeap<T>&);

template <class T>
class MinPQ
{
public:
    virtual ~MinPQ() {}                // virtual destructor
    virtual bool IsEmpty() const = 0;  // return true iff empty
    virtual const T& Top() const = 0;  // return reference to the max
    virtual void Push(const T&) = 0;
    virtual void Pop() = 0;
};

template <class T>
class MinHeap : public MinPQ<T>
{
    friend std::ostream& operator<< <T>(std::ostream&, const MinHeap<T>&);

private:
    std::vector<T> heap = std::vector<T>(1);

public:
    MinHeap() {}
    MinHeap(const std::vector<T>&);
    bool IsEmpty() const { return heap.size() <= 1; }
    const T& Top() const;
    void Push(const T&);
    void Pop();
    void PrintHeap() const;
};

template <class T>
MinHeap<T>::MinHeap(const std::vector<T>& in)
{
    heap.insert(heap.end(), in.begin(), in.end());

    for (int cur = (heap.size() - 1) / 2; cur; cur--) {
        T cur_ele = heap[cur];
        int parent = cur;
        int child = parent * 2;
        if (child < heap.size() - 1 && heap[child] > heap[child + 1]) child++;
        while (child < heap.size() && cur_ele > heap[child]) {
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
            // pick the smaller child
            if (child < heap.size() - 1 && heap[child] > heap[child + 1])
                child++;
        }
        heap[parent] = cur_ele;
    }
}

template <class T>
const T& MinHeap<T>::Top() const
{
    if (IsEmpty()) std::__throw_range_error("the heap is empty.");
    return heap[1];
}

template <class T>
void MinHeap<T>::Push(const T& e)
{
    heap.resize(heap.size() + 1);
    int cur = heap.size() - 1;
    while (cur != 1 && heap[cur / 2] > e) {
        heap[cur] = heap[cur / 2];
        cur /= 2;
    }
    heap[cur] = e;
}

template <class T>
void MinHeap<T>::Pop()
{
    if (heap.empty()) return;
    // extract the last element and pop the heap
    T last = heap.back();
    heap.pop_back();
    // find the position to place last
    int parent = 1;
    int child = 3 < heap.size() && heap[2] > heap[3] ? 3 : 2;
    while (child < heap.size() && last > heap[child]) {
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
        // pick the larger child
        if (child < heap.size() - 1 && heap[child] > heap[child + 1]) child++;
    }
    heap[parent] = last;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const MinHeap<T>& h)
{
    for (size_t i = 1; i < h.heap.size(); i++) out << h.heap[i] << ' ';
    return out;
}
