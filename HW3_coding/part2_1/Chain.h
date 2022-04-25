#ifndef CHAIN_H
#define CHAIN_H

// forward declaration
template <class T>
class Chain;

// Merge() needs to be forward declared since it a non-member template function.
template <class T>
Chain<T> Merge(Chain<T> L1, Chain<T> L2);

template <class T>
class ChainNode
{
    friend class Chain<T>;
    friend Chain<T> Merge<T>(Chain<T> L1, Chain<T> L2);

private:
    T data;
    ChainNode<T>* link;

public:
    ChainNode(T element, ChainNode* next = nullptr)
        : data(element), link(next){};
};

template <class T>
class Chain
{
    friend Chain Merge<T>(Chain<T> L1, Chain<T> L2);

public:
    // constructor
    Chain() {}
    Chain(ChainNode<T>* f);

    // Chain manipulation
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
    void divideMid(Chain<T>& subList);             // stupid
    void Split(Chain<T> L2, ChainNode<T>* split);  // ??

    // Debug
    void Print();

private:
    ChainNode<T>*first = nullptr, *last = nullptr;
};

template <class T>
Chain<T>::Chain(ChainNode<T>* f) : first(f)
{
    if (first == nullptr) return;

    ChainNode<T>* now = first;
    while (now->link != nullptr) now = now->link;
    last = now;
}

template <class T>
void Chain<T>::InsertFront(const T& e)
{
    // The chain is empty, just assign first and last
    if (first == nullptr) {
        first = new ChainNode<T>(e);
        last = first;
        return;
    };

    // Create a new node with link pointing to the original first
    // and assign it to first.
    ChainNode<T>* newNode = new ChainNode<T>(e, first);
    first = newNode;
}

template <class T>
void Chain<T>::InsertBack(const T& e)
{
    // The chain is empty, just assign first and last
    if (first == nullptr) {
        first = new ChainNode<T>(e);
        last = first;
        return;
    };

    // Create a new node and assign it to last.
    last = last->link = new ChainNode<T>(e);
}

template <class T>
void Chain<T>::DeleteFront()
{
    if (first == nullptr) return;

    ChainNode<T>* front = first;
    if (first->link == nullptr) first = last = nullptr;
    else first = first->link;
    delete front;
}

template <class T>
void Chain<T>::DeleteBack()
{
    if (first == nullptr) return;

    ChainNode<T>* back = last;

    if (first->link == nullptr) {
        first = last = nullptr;
    } else {
        ChainNode<T>* now;
        for (now = first; now->link != last; now = now->link)
            ;
        now->link = nullptr;
        last = now;
    }

    delete back;
}

template <class T>
const T& Chain<T>::Front()
{
    if (first == nullptr) throw "The list is empty.";

    return first->data;
}

template <class T>
void Chain<T>::DeleteOdd()
{
    // No elements in the list, do nothing
    if (first == nullptr) return;
    // Only one element in the list, delete it and adjust first and last
    if (first == last) {
        delete first;
        first = last = nullptr;
        return;
    }

    // even and odd are the looping pointers
    ChainNode<T>* even = first->link;
    ChainNode<T>* odd = even->link;

    // delete front since 1 is odd and re-adjust first
    delete first;
    first = even;
    // Traverse through the list with even and odd
    // with odd being ahead of even by 1 node
    while (even != last && even->link != last) {
        // delete current odd and move on
        ChainNode<T>* del = odd;
        even->link = odd->link;
        delete del;
        even = even->link;
        odd = even->link;
    }

    // Cases when the original length is odd
    if (even->link == last) {
        delete even->link;
        last = even;
    }
    // adjust last
    last->link = nullptr;
}

template <class T>
const T& Chain<T>::Back()
{
    if (first == nullptr) throw "The list is empty.";

    return last->data;
}

template <class T>
const T& Chain<T>::Get(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";

    ChainNode<T>* now = first;
    i--;
    while (now != nullptr && i) {
        now = now->link;
        i--;
    }
    if (now == nullptr) throw "out of range.";

    return now->data;
}

template <class T>
void Chain<T>::Delete(int i)
{
    if (first == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";
    if (i == 1) {
        DeleteFront();
        return;
    }

    ChainNode<T>*now = first, *prev;
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
void Chain<T>::Insert(int i, const T& e)
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

    // Traverse through the Chain with now and prev
    ChainNode<T>*now = first, *prev;

    // i-- at the begining since we want i-th.
    // Therefore, we only need to loop from i-1 to 0
    // Traverse through every node until i-th node
    for (i--; i; i--) {
        prev = now;
        now = now->link;
    }

    // Insert the node before i-th element
    // Note that the new node's link is pointing to the original i-th element
    prev->link = new ChainNode<T>(e, now);
}

template <class T>
int Chain<T>::Length()
{
    // the length to count the number of nodes
    int l;
    // initialize now as the first node
    ChainNode<T>* now = first;
    // Traverse through every node and increment l until nullptr(0)
    for (l = 0; now != nullptr; l++) now = now->link;
    return l;
}

template <class T>
void Chain<T>::Patch(int k, const T& e)
{
    // Exception Cases
    if (first == nullptr) throw "The list is empty.";
    if (k <= 0) throw "k must be a positive integer.";
    if (k > Length()) throw "out of range.";

    // initialize now as the first node
    ChainNode<T>* now = first;

    // k-- at the begining since we want k-th.
    // Therefore, we only need to loop from k-1 to 0.
    // Traverse through every node until k-th node.
    for (k--; k; k--) now = now->link;
    // the data field we want to change
    now->data = e;
}

template <class T>
void Chain<T>::Clear()
{
    // Exception Case
    if (first == nullptr) throw "The list is empty.";

    // Traverse through the Chain with now and prev.
    ChainNode<T>* now;
    ChainNode<T>* prev;

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
void Chain<T>::divideMid(Chain<T>& subList)
{
    // Get the length of the original Chain
    int length = Length();

    // No need to divide when length is less then 2,
    // just assign the subList as an empty chain
    if (length <= 1) {
        subList = Chain<T>();
        return;
    }

    // Traverse through the Chain with now and prev.
    ChainNode<T>* now = first;
    ChainNode<T>* prev;
    int mid_point = length / 2 + length % 2;

    // Traverse through every node until ((length / 2) + 1)-th.
    for (int i = 0; i < mid_point; i++) {
        prev = now;
        now = now->link;
    }

    // Divide the two lists as instructed
    prev->link = nullptr;
    last = prev;
    subList = Chain<T>(now);
}

template <class T>
void Chain<T>::Split(Chain<T> L2, ChainNode<T>* split)
{
    // Traverse through the Chain with now and prev.
    ChainNode<T>* now;
    ChainNode<T>* prev;

    // Traverse through the Chain until split node.
    for (now = first; now != split && now != nullptr; now = now->link)
        prev = now;

    // Exception Cases
    if (now == nullptr) throw "Cannot find the node specified.";

    // Split the two lists as instructed
    prev->link = nullptr;
    last = prev;
    L2 = Chain<T>(now);
}

template <class T>
Chain<T> Merge(Chain<T> L1, Chain<T> L2)
{
    // Traverse through L1 with now1, and L2 with now2
    ChainNode<T>* now1 = L1.first;
    ChainNode<T>* now2 = L2.first;

    // The merged L3 to be returned
    Chain<T> merged;

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
void Chain<T>::Print()
{
    if (first == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    };

    ChainNode<T>* now;
    for (now = first; now != nullptr; now = now->link)
        std::cout << now->data << " \n"[now->link ? 0 : 1];
}

#endif
