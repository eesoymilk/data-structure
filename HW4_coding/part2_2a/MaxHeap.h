#pragma once

#include <vector>

template <class T>
class MaxPQ
{
public:
    virtual ~MaxPQ() {}                // virtual destructor
    virtual bool IsEmpty() const = 0;  // return true iff empty
    virtual const T& Top() const = 0;  // return reference to the max
    virtual void Push(const T&) = 0;
    virtual void Pop() = 0;
};

template <class T>
class MaxHeap : public MaxPQ<T>
{
private:
    std::vector<T> heap;

public:
    MaxHeap();
    bool IsEmpty() const;
    const T& Top() const;
    void Push(const T&);
    void Pop();
};
