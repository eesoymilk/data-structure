#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
class List;

template <class T>
class Stack;

template <class T>
class Node
{
    friend class List<T>;
    friend class Stack<T>;

public:
    Node() {}
    Node(T element, Node* next = nullptr) : data(element), link(next) {}

private:
    T data;
    Node<T>* link = nullptr;
};

template <class T>
class List
{
public:
    List() {}
    void InsertFront(const T& e);
    void InsertBack(const T& e);
    void DeleteFront();
    void DeleteBack();
    const T& Front() const;
    const T& Back() const;
    int Length() const;
    void Concatenate(List<T>& b);  // TODO
    void Reverse();                // TODO
    class Iterator
    {
    public:
        Iterator(Node<T>* start = 0) : current{start} {}

        // dereferencing operators
        T& operator*() const { return current->data; }
        T* operator->() const { return &current; }

        // increment
        Iterator& operator++()  // preincrement
        {
            current = current->link;
            return *this;
        }

        Iterator& operator++(int)  // postincrement
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        // equality
        bool operator!=(const Iterator right) const
        {
            return current != right.current;
        }

        bool operator==(const Iterator right) const
        {
            return current == right.current;
        }

    private:
        Node<T>* current;
    };
    Iterator Begin() { return first; }
    Iterator End() { return nullptr; }

protected:
    Node<T>*first = nullptr, *last = nullptr;
};

template <class T>
void List<T>::InsertFront(const T& e)
{
    if (!first) {
        first = last = new Node<T>(e);
        return;
    }
    first = new Node<T>(e, first);
}

template <class T>
void List<T>::InsertBack(const T& e)
{
    if (!first) {
        first = last = new Node<T>(e);
        return;
    }
    last = last->link = new Node<T>(e);
}

template <class T>
void List<T>::DeleteFront()
{
    if (first == nullptr) return;

    Node<T>* front = first;
    if (first->link == nullptr) first = last = nullptr;
    else first = first->link;
    delete front;
}

template <class T>
void List<T>::DeleteBack()
{
    if (first == nullptr) return;

    Node<T>* back = last;

    if (first->link == nullptr) {
        first = last = nullptr;
    } else {
        Node<T>* now;
        for (now = first; now->link != last; now = now->link)
            ;
        now->link = nullptr;
        last = now;
    }

    delete back;
}

template <class T>
const T& List<T>::Front() const
{
    if (first == nullptr) throw "The list is empty.";

    return first->data;
}

template <class T>
const T& List<T>::Back() const
{
    if (first == nullptr) throw "The list is empty.";

    return last->data;
}

template <class T>
int List<T>::Length() const
{
    // the length to count the number of nodes
    int l;
    // initialize now as the first node
    Node<T>* now = first;
    // Traverse through every node and increment l until nullptr(0)
    for (l = 0; now != nullptr; l++) now = now->link;
    return l;
}

// Stack
template <class T>
class Stack : public List<T>
{
    using List<T>::first;
    using List<T>::last;

public:
    Stack() : List<T>{} {}
    ~Stack() {}

    int Size() { return this->Length(); }
    inline bool IsEmpty() const { return this->first == nullptr; }
    void Push(const T& e) { this->InsertBack(e); }
    void Pop() { this->DeleteBack(); }
    const T& Top() const { return this->Back(); }
};

// Queue
template <class T>
class Queue : public List<T>
{
    using List<T>::first;
    using List<T>::last;

public:
    Queue() : List<T>{} {}
    ~Queue() {}
    int Size() { return this->Length(); }
    inline bool IsEmpty() const { return this->first == nullptr; }
    void Push(const T& e) { this->InsertBack(e); }
    void Pop() { this->DeleteFront(); }
    const T& Front() const { return this->Front(); }
    const T& Rear() const { return this->Back(); }
};

#endif
