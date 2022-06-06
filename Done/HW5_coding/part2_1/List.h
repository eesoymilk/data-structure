#pragma once

#include <iostream>

template <class T>
class List;

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

template <class T>
class Node
{
    friend class List<T>;
    friend std::ostream &operator<< <T>(std::ostream &out, const List<T> &l);

public:
    Node() {}
    Node(T element, Node *next = nullptr) : data(element), link(next) {}

private:
    T data;
    Node<T> *link = nullptr;
};

template <class T>
class List
{
    friend std::ostream &operator<< <T>(std::ostream &out, const List<T> &l);

public:
    List() {}
    ~List();
    void InsertFront(const T &e);
    void InsertBack(const T &e);
    void DeleteFront();
    void DeleteBack();
    const T &Front() const;
    const T &Back() const;
    const T &Get(int i);
    void Delete(int i);
    void Insert(int i, const T &e);
    int Length() const;
    void Concatenate(List<T> &b);
    void Reverse();
    class Iterator;
    Iterator Begin() const { return first; }
    Iterator End() const { return nullptr; }

protected:
    Node<T> *first = nullptr, *last = nullptr;
};

template <class T>
class List<T>::Iterator
{
public:
    Iterator(Node<T> *start = 0) : current{start} {}

    // dereferencing operators
    T &operator*() const { return current->data; }
    T *operator->() const { return &current->data; }

    // increment
    Iterator &operator++()  // preincrement
    {
        current = current->link;
        return *this;
    }

    Iterator &operator++(int)  // postincrement
    {
        Iterator *tmp = this;
        ++(*this);
        return *tmp;
    }

    // arithmetic
    Iterator &operator+(const int x)
    {
        for (int i = 0; i < x && current != nullptr; i++)
            current = current->link;
        return *this;
    }
    Iterator &operator+=(const int x) { return (*this) + x; }

    // equality
    bool operator!=(const Iterator right) const
    {
        return current != right.current;
    }

    bool operator==(const Iterator right) const
    {
        return current == right.current;
    }

    //
    bool IsLastElement() const { return current->link == nullptr; }

private:
    Node<T> *current;
};

template <class T>
List<T>::~List()
{
    if (first == nullptr) return;
    Node<T> *now = first, *prev;
    while (now->link != nullptr) {
        prev = now;
        now = now->link;
        delete prev;
    }
    delete now;
    first = last = nullptr;
}

template <class T>
void List<T>::InsertFront(const T &e)
{
    if (!first) {
        first = last = new Node<T>(e);
        return;
    }
    first = new Node<T>(e, first);
}

template <class T>
void List<T>::InsertBack(const T &e)
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

    Node<T> *front = first;
    if (first->link == nullptr) first = last = nullptr;
    else first = first->link;
    delete front;
}

template <class T>
void List<T>::DeleteBack()
{
    if (first == nullptr) return;

    Node<T> *back = last;

    if (first->link == nullptr) {
        first = last = nullptr;
    } else {
        Node<T> *now;
        for (now = first; now->link != last; now = now->link)
            ;
        now->link = nullptr;
        last = now;
    }

    delete back;
}

template <class T>
const T &List<T>::Front() const
{
    if (first == nullptr) throw "The list is empty.";

    return first->data;
}

template <class T>
const T &List<T>::Back() const
{
    if (first == nullptr) throw "The list is empty.";

    return last->data;
}

template <class T>
const T &List<T>::Get(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";

    Node<T> *now = first;
    i--;
    while (now != nullptr && i) {
        now = now->link;
        i--;
    }
    if (now == nullptr) throw "out of range.";

    return now->data;
}

template <class T>
void List<T>::Delete(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";
    if (i == 1) {
        DeleteFront();
        return;
    }

    Node<T> *now = first, *prev;
    i--;
    while (now != nullptr && i) {
        prev = now;
        now = now->link;
        i--;
    }
    if (now == nullptr) throw "out of range.";
    prev->link = now->link;
    delete now;
}

template <class T>
void List<T>::Insert(int i, const T &e)
{
    // Exception Cases
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";
    if (i > Length()) throw "out of range.";

    // When i = 1, InsertFront will do
    if (i == 1) {
        InsertFront(e);
        return;
    }

    // Traverse through the List with now and prev
    Node<T> *now = first, *prev;

    // i-- at the begining since we want i-th.
    // Therefore, we only need to loop from i-1 to 0
    // Traverse through every node until i-th node
    for (i--; i; i--) {
        prev = now;
        now = now->link;
    }

    // Insert the node before i-th element
    // Note that the new node's link is pointing to the original i-th element
    prev->link = new Node<T>(e, now);
}

template <class T>
int List<T>::Length() const
{
    // the length to count the number of nodes
    int l;
    // initialize now as the first node
    Node<T> *now = first;
    // Traverse through every node and increment l until nullptr(0)
    for (l = 0; now != nullptr; l++) now = now->link;
    return l;
}

template <class T>
void List<T>::Concatenate(List<T> &b)
{
    Node<T> *now;
    for (now = first; now->link != nullptr; now = now->link)
        ;
    now->link = b.first;
}

template <class T>
void List<T>::Reverse()
{
    Node<T> *now, *prev = nullptr;
    first = now = first;
    while (now != nullptr) {
        Node<int> *tmp = now->link;
        now->link = prev;
        prev = now;
        now = tmp;
    }
    first = prev;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l)
{
    if (l.Begin() == nullptr) out << "The list is empty.\n";
    for (typename List<T>::Iterator it = l.Begin(); it != l.End(); it++)
        out << *it << " \n"[it.IsLastElement() ? 1 : 0];
    return out;
}