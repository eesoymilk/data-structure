#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

// forward declaration
template <class T>
class CircularList;

// Merge() needs to be forward declared since it a non-member template function.
template <class T>
void Merge(CircularList<T>& L1, CircularList<T>& L2, CircularList<T>& merged);

template <class T>
class Node
{
    friend class CircularList<T>;
    friend void Merge<T>(CircularList<T>& L1, CircularList<T>& L2,
                         CircularList<T>& merged);

private:
    T data;
    Node<T>* link;

public:
    Node(T element, Node* next = nullptr) : data(element), link(next){};
};

template <class T>
class CircularList
{
    friend void Merge<T>(CircularList<T>& L1, CircularList<T>& L2,
                         CircularList<T>& merged);

public:
    // constructor
    CircularList() {}
    CircularList(Node<T>* f);

    // CircularList manipulation
    void InsertFront(const T& e);
    void InsertBack(const T& e);
    void DeleteFront();
    void DeleteBack();
    void DeleteOdd();
    const T& Front();
    const T& Back();
    const T& Get(int i);
    void Delete(int i);
    void Insert(int i, const T& e);

    // HW
    int Length();
    void Patch(int k, const T& e);
    void Clear();
    void divideMid(CircularList<T>& subList);         // stupid
    void Split(CircularList<T>& L2, Node<T>* split);  // ??

    // Debug
    void Print();

private:
    Node<T>*first = nullptr, *last = nullptr;
};

template <class T>
CircularList<T>::CircularList(Node<T>* f) : first(f)
{
    if (first == nullptr) return;

    Node<T>* now = first;
    while (now->link != first) now = now->link;
    last = now;
}

template <class T>
void CircularList<T>::InsertFront(const T& e)
{
    // The list is empty, just assign first and last
    if (first == nullptr) {
        first = new Node<T>(e);
        last = first;
        last->link = first;
        return;
    };

    // Create a new node with link pointing to the original first
    // and assign it to first.
    last->link = first = new Node<T>(e, first);
}

template <class T>
void CircularList<T>::InsertBack(const T& e)
{
    // The list is empty, just assign first and last
    if (first == nullptr) {
        first = new Node<T>(e);
        last = first;
        last->link = first;
        return;
    };

    // Create a new node with link pointing to first and assign it to last.
    last = last->link = new Node<T>(e, first);
}

template <class T>
void CircularList<T>::DeleteFront()
{
    // The list is empty, do nothing
    if (first == nullptr) return;

    // front to store first element
    Node<T>* front = first;
    // only one element in the list, assign both first and last to nullptr(0)
    if (first == last) first = last = nullptr;
    // skip the first element and delete it
    else last->link = first = first->link;
    delete front;
}

template <class T>
void CircularList<T>::DeleteBack()
{
    // The list is empty, do nothing
    if (first == nullptr) return;

    // back to store last element
    Node<T>* back = last;

    // only one element in the list, assign both first and last to nullptr(0)
    if (first == last) {
        first = last = nullptr;
    } else {
        // traverse until the element prior to last, and then skip it
        Node<T>* now = first;
        while (now->link != last) now = now->link;
        now->link = first;
        last = now;
    }
    // delete back
    delete back;
}

template <class T>
void CircularList<T>::DeleteOdd()
{
    if (first == nullptr) return;
    if (first == last) {
        delete first;
        first = last = nullptr;
    }

    Node<T>* even = first->link;
    Node<T>* odd = even->link;

    delete first;
    first = even;
    while (even != last && even->link != last) {
        Node<T>* del = odd;
        even->link = odd->link;
        delete del;
        even = even->link;
        odd = even->link;
    }
    if (even->link == last) {
        delete even->link;
        last = even;
    }
    last->link = first;
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

template <class T>
const T& CircularList<T>::Get(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";

    Node<T>* now = first;
    i--;
    while (now != last && i) {
        now = now->link;
        i--;
    }
    if (now == last && i > 0) throw "out of range.";

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
    while (now != last && i) {
        prev = now;
        now = now->link;
        i--;
    }

    if (now == last && i > 0) throw "out of range.";

    prev->link = now->link;
    delete now;

    // Node<T>*now = first, *prev;
    // i--;
    // while (now != nullptr && i) {
    //     prev = now;
    //     now = now->link;
    //     i--;
    // }
    // if (now == nullptr) throw "out of range.";
    // prev->link = now->link;
    // delete now;
}

template <class T>
void CircularList<T>::Insert(int i, const T& e)
{
    // Exception Cases
    if (first == nullptr)
        if (i == 1) InsertFront(e);
        else throw "The list is empty.";

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
    // the list is empty, return 0
    if (last == nullptr) return 0;
    // the length to count the number of nodes
    int l;
    // initialize now as the first node
    Node<T>* now = first->link;
    // Traverse through every node and increment l until nullptr(0)
    for (l = 1; now != first; l++) now = now->link;
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
    // just assign the subList as an empty list
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
void CircularList<T>::Split(CircularList<T>& L2, Node<T>* split)
{
    // Traverse through the CircularList with now and prev.
    Node<T>* now = first->link;
    Node<T>* prev = first;

    // Traverse through the CircularList until split node.
    for (; now->data != split->data && now != first; now = now->link)
        prev = now;

    // Exception Cases
    if (now == first) throw "Cannot find the node specified.";

    // Split the two lists as instructed
    prev->link = first;
    last = prev;

    L2.first = now;
    while (now->link != first) now = now->link;
    now->link = L2.first;
    L2.last = now;
}

template <class T>
void Merge(CircularList<T>& L1, CircularList<T>& L2, CircularList<T>& merged)
{
    // Traverse through L1 with now1, and L2 with now2
    Node<T>* now1 = L1.first->link;
    Node<T>* now2 = L2.first->link;

    merged.first = merged.last = nullptr;

    // If now1 or now2 is not nullptr(0),
    // insert the elements of now1 and now2, in this order, to the merged one
    merged.InsertBack(L1.first->data);
    merged.InsertBack(L2.first->data);
    while (now1 != L1.first || now2 != L2.first) {
        if (now1) {
            merged.InsertBack(now1->data);
            now1 = now1->link;
        }
        if (now2) {
            merged.InsertBack(now2->data);
            now2 = now2->link;
        }
    }
}

template <class T>
void CircularList<T>::Print()
{
    if (first == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    };

    Node<T>* now;
    for (now = first; now != last; now = now->link)
        std::cout << now->data << ' ';
    std::cout << last->data << '\n';
}

#endif
