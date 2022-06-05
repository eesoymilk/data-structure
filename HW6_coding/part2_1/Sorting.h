#include <vector>

template <class T>
void InsertionSort(T* a, const int n)
{}

template <class T>
void Swap(T* a, T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class T>
void QuickSort(T* a, const int left, const int right)
{
    if (left >= right) return;

    T& pivot = a[left];
    int i = left + 1, j = right;

    while (true) {
        // TODO
        while (a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) break;
        Swap(&a[i], &a[j]);
    }
    Swap(&pivot, &a[j]);

    QuickSort(a, left, j - 1);
    QuickSort(a, j + 1, right);
}

template <class T>
void IterativeMergeSort()
{}

template <class T>
void RecursiveMergeSort()
{}

template <class T>
void HeapSort(std::vector<T> a)
{}
