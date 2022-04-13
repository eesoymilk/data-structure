#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

// forward declaration
template <class T>
class CircularList;

// Merge() needs to be forward declared since it a non-member template function.
template <class T>
CircularList<T> Merge(CircularList<T> L1, CircularList<T> L2);

template <class T>
class Node
{
    friend class CircularList<T>;
    friend CircularList<T> Merge<T>(CircularList<T> L1, CircularList<T> L2);

private:
    T data;
    Node<T>* link;

public:
    Node(T element, Node* next = nullptr) : data(element), link(next){};
};

template <class T>
class CircularList
{
    friend CircularList Merge<T>(CircularList<T> L1, CircularList<T> L2);

public:
    // constructor
    CircularList() {}
    CircularList(Node<T>* f);

    // CircularList manipulation
    void InsertFront(const T& e);
    void InsertBack(const T& e);
    void DeleteFront();
    void DeleteBack();
    const T& Front();
    const T& Back();
    const T& Get(int i);
    void Delete(int i);
    void Insert(int i, const T& e);

    // HW
    int Length();
    void Patch(int k, const T& e);
    void Clear();
    void divideMid(CircularList<T>& subList);        // stupid
    void Split(CircularList<T> L2, Node<T>* split);  // ??

    // Debug
    void Print();

private:
    Node<T>*first = nullptr, *last = nullptr;
};

template <class T>
CircularList<T>::CircularList(Node<T>* f) : first(f)
{
    // if (first == nullptr) return;

    // Node<T>* now = first;
    // while (now->link != nullptr) now = now->link;
    // last = now;
}

template <class T>
void CircularList<T>::InsertFront(const T& e)
{
    // The chain is empty, just assign first and last
    if (first == nullptr) {
        first = new Node<T>(e);
        last = first;
        last->link = first;
        return;
    };

    // Create a new node with link pointing to the original first
    // and assign it to first.
    Node<T>* newNode = new Node<T>(e, first);
    last->link = first = newNode;
}

template <class T>
void CircularList<T>::InsertBack(const T& e)
{
    // The chain is empty, just assign first and last
    if (first == nullptr) {
        first = new Node<T>(e);
        last = first;
        return;
    };

    // Create a new node with link pointing to first and assign it to last.
    last = last->link = new Node<T>(e, first);
}

template <class T>
void CircularList<T>::DeleteFront()
{
    if (first == nullptr) return;

    Node<T>* front = first;
    if (first->link == first)
        first = last = nullptr;
    else
        last->link = first = first->link;
    delete front;
}

template <class T>
void CircularList<T>::DeleteBack()
{
    if (first == nullptr) return;

    Node<T>* back = last;

    if (first->link == first) {
        first = last = nullptr;
    } else {
        Node<T>* now;
        for (now = first; now->link != last; now = now->link)
            ;
        now->link = first;
        last = now;
    }

    delete back;
}

template <class T>
const T& CircularList<T>::Front()
{
    if (first == nullptr) throw "The list is empty.";

    return first->data;
}

template <class T>
const T& CircularList<T>::Back()
{
    if (first == nullptr) throw "The list is empty.";

    return last->data;
}

// TODO
template <class T>
const T& CircularList<T>::Get(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";

    Node<T>* now = first;
    i--;
    while (now->link != nullptr && i) {
        now = now->link;
        i--;
    }
    if (now == nullptr) throw "out of range.";

    return now->data;
}

template <class T>
void CircularList<T>::Delete(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";
    if (i == 1) {
        DeleteFront();
        return;
    }

    Node<T>*now = first, *prev;
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
void CircularList<T>::Insert(int i, const T& e)
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

    // Traverse through the CircularList with now and prev
    Node<T>*now = first, *prev;

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
int CircularList<T>::Length()
{
    // the length to count the number of nodes
    int l;
    // initialize now as the first node
    Node<T>* now = first;
    // Traverse through every node and increment l until nullptr(0)
    for (l = 0; now != nullptr; l++) now = now->link;
    return l;
}

template <class T>
void CircularList<T>::Patch(int k, const T& e)
{
    // Exception Cases
    if (first == nullptr) throw "The list is empty.";
    if (k <= 0) throw "k must be a positive integer.";
    if (k > Length()) throw "out of range.";

    // initialize now as the first node
    Node<T>* now = first;

    // k-- at the begining since we want k-th.
    // Therefore, we only need to loop from k-1 to 0.
    // Traverse through every node until k-th node.
    for (k--; k; k--) now = now->link;
    // the data field we want to change
    now->data = e;
}

template <class T>
void CircularList<T>::Clear()
{
    // Exception Case
    if (first == nullptr) throw "The list is empty.";

    // Traverse through the CircularList with now and prev.
    Node<T>* now;
    Node<T>* prev;

    // Traverse through every node and delete all of them until nullptr(0).
    for (now = first; now != nullptr;) {
        prev = now;
        now = now->link;
        delete prev;
    }

    // Re-assignment of first and last as nullptr(0).
    first = last = nullptr;
}

template <class T>
void CircularList<T>::divideMid(CircularList<T>& subList)
{
    // Get the length of the original CircularList
    int length = Length();

    // No need to divide when length is less then 2,
    // just assign the subList as an empty chain
    if (length <= 1) {
        subList = CircularList<T>();
        return;
    }

    // Traverse through the CircularList with now and prev.
    Node<T>* now = first;
    Node<T>* prev;

    // Traverse through every node until ((length / 2) + 1)-th.
    for (int i = 0; i <= length / 2; i++) {
        prev = now;
        now = now->link;
    }

    // Divide the two lists as instructed
    prev->link = nullptr;
    last = prev;
    subList = CircularList<T>(now);
}

template <class T>
void CircularList<T>::Split(CircularList<T> L2, Node<T>* split)
{
    // Traverse through the CircularList with now and prev.
    Node<T>* now;
    Node<T>* prev;

    // Traverse through the CircularList until split node.
    for (now = first; now != split && now != nullptr; now = now->link)
        prev = now;

    // Exception Cases
    if (now == nullptr) throw "Cannot find the node specified.";

    // Split the two lists as instructed
    prev->link = nullptr;
    last = prev;
    L2 = CircularList<T>(now);
}

template <class T>
CircularList<T> Merge(CircularList<T> L1, CircularList<T> L2)
{
    // Traverse through L1 with now1, and L2 with now2
    Node<T>* now1 = L1.first;
    Node<T>* now2 = L2.first;

    // The merged L3 to be returned
    CircularList<T> merged;

    // If now1 or now2 is not nullptr(0),
    // insert the elements of now1 and now2, in this order, to the merged one
    while (now1 || now2) {
        if (now1) {
            merged.InsertBack(now1->data);
            now1 = now1->link;
        }
        if (now2) {
            merged.InsertBack(now2->data);
            now2 = now2->link;
        }
    }
    return merged;
}

template <class T>
void CircularList<T>::Print()
{
    if (first == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    };

    Node<T>* now;
    for (now = first; now != nullptr; now = now->link)
        std::cout << now->data << " \n"[now->link ? 0 : 1];
}

#endif