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
    Node<T>* link = nullptr;

public:
    Node() {}
    Node(T element, Node* next = nullptr) : data(element), link(next) {}
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
    void divideMid(CircularList<T>& subList);        // stupid
    void Split(CircularList<T> L2, Node<T>* split);  // ??

    // Debug
    void Print();

private:
    Node<T>*head = new Node<T>(), *last = head;
};

template <class T>
CircularList<T>::CircularList(Node<T>* h) : head(h)
{
    Node<T>* now = head->link;
    while (now->link != head) now = now->link;
    last = now;
}

template <class T>
void CircularList<T>::InsertFront(const T& e)
{
    // Create the new node
    Node<T>* newNode = new Node<T>(e);
    // the list is empty, last needs to take in consideration
    if (head == last) {
        last = head->link = newNode;
        last->link = head;
    } else {
        // add the node to the front as instructed
        Node<T>* front = head->link;
        newNode->link = front;
        head->link = newNode;
    }
}

template <class T>
void CircularList<T>::InsertBack(const T& e)
{
    // add node after last
    last = last->link = new Node<T>(e, head);
}

template <class T>
void CircularList<T>::DeleteFront()
{
    // The list is empty, do nothing
    if (head == last) return;

    // front to store head element
    Node<T>* front = head->link;
    if (front == last) last = head;
    head->link = front->link;
    delete front;
}

template <class T>
void CircularList<T>::DeleteBack()
{
    // The list is empty, do nothing
    if (head == last) return;

    // back to store last element
    Node<T>* back = last;

    // only one element in the list, assign both head and last to nullptr(0)
    if (head->link == last) {
        last = head->link = head;
    } else {
        // traverse until the element prior to last, and then skip it
        Node<T>* now = head->link;
        while (now->link != last) now = now->link;
        now->link = head;
        last = now;
    }
    delete back;
}

template <class T>
void CircularList<T>::DeleteOdd()
{
    // No elements in the list, do nothing
    if (head == last) return;
    // Only one element in the list, delete it and adjust head and last
    if (head->link == last) {
        delete head->link;
        last = head->link = head;
    }

    // front is the first element in the list
    // even and odd are the looping pointers
    Node<T>* front = head->link;
    Node<T>* even = front->link;
    Node<T>* odd = even->link;

    // delete front since 1 is odd and readjust head
    delete front;
    head->link = even;
    // Traverse through the list with even and odd
    // with odd being ahead of even by 1 node
    while (even != last && even->link != last) {
        // delete current odd and move on
        Node<T>* del = odd;
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
    last->link = head;
}

template <class T>
const T& CircularList<T>::Front()
{
    if (head == nullptr) throw "The list is empty.";

    return head->data;
}

template <class T>
const T& CircularList<T>::Back()
{
    if (head == nullptr) throw "The list is empty.";

    return last->data;
}

template <class T>
const T& CircularList<T>::Get(int i)
{
    if (head == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";

    Node<T>* now = head;
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
    if (head == nullptr) throw "The list is empty.";
    if (i <= 0) throw "i must be a positive integer.";
    if (i == 1) {
        DeleteFront();
        return;
    }

    Node<T>*now = head, *prev;
    i--;
    while (now != last && i) {
        prev = now;
        now = now->link;
        i--;
    }

    if (now == last && i > 0) throw "out of range.";

    prev->link = now->link;
    delete now;

    // Node<T>*now = head, *prev;
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
    if (head == last)
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
    Node<T>*now = head->link, *prev;

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
    if (head == last) return 0;
    // the length to count the number of nodes
    int l;
    // initialize now as the head node
    Node<T>* now = head->link;
    // Traverse through every node and increment l until nullptr(0)
    for (l = 0; now != head; l++) now = now->link;
    return l;
}

template <class T>
void CircularList<T>::Patch(int k, const T& e)
{
    // Exception Cases
    if (head == last) throw "The list is empty.";
    if (k <= 0) throw "k must be a positive integer.";
    if (k > Length()) throw "out of range.";

    // initialize now as the first node
    Node<T>* now = head->link;

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
    if (head == nullptr) throw "The list is empty.";

    // Traverse through the CircularList with now and prev.
    Node<T>* now;
    Node<T>* prev;

    // Traverse through every node and delete all of them until nullptr(0).
    for (now = head; now != nullptr;) {
        prev = now;
        now = now->link;
        delete prev;
    }

    // Re-assignment of head and last as nullptr(0).
    head = last = nullptr;
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
    Node<T>* now = head;
    Node<T>* prev;

    // Traverse through every node until ((length / 2) + 1)-th.
    for (int i = 0; i <= length / 2; i++) {
        prev = now;
        now = now->link;
    }

    // Divide the two lists as instructed
    // Note that we need to create a new head for the sub list
    Node<T>* h2 = new Node<T>();
    h2->link = now;
    last->link = h2;
    last = prev;
    last->link = head;
    subList = CircularList<T>(h2);
}

template <class T>
void CircularList<T>::Split(CircularList<T> L2, Node<T>* split)
{
    // Traverse through the CircularList with now and prev.
    Node<T>* now = head->link;
    Node<T>* prev = head;

    // Traverse through the CircularList until split node.
    for (; now != split && now != head; now = now->link) prev = now;

    // Exception Cases
    if (now == head) throw "Cannot find the node specified.";

    // Split the two lists as instructed
    // Note that we need to create a new head for the split L2
    Node<T>* h2 = new Node<T>();
    h2->link = now;
    last->link = h2;
    last = prev;
    last->link = head;
    L2 = CircularList<T>(h2);
}

template <class T>
CircularList<T> Merge(CircularList<T> L1, CircularList<T> L2)
{
    // if one of the list is empty, just return the other
    if (L1.head == L1.last) return L2;
    if (L2.head == L2.last) return L1;

    // Traverse through L1 with now1, and L2 with now2
    Node<T>* now1 = L1.head->link;
    Node<T>* now2 = L2.head->link;

    // The merged L3 to be returned
    CircularList<T> merged;

    // If now1 or now2 is not nullptr(0),
    // insert the elements of now1 and now2, in this order, to the merged one
    while (now1 != L1.head || now2 != L2.head) {
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
    if (head == last) {
        std::cout << "The list is empty.\n";
        return;
    };

    Node<T>* now = head->link;
    std::cout << "first = " << now->data << ", last = " << last->data << '\n';
    for (; now != head; now = now->link)
        std::cout << now->data << " \n"[now == last ? 1 : 0];
}

#endif
