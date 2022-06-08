#pragma once

#include <algorithm>
#include <iomanip>
#include <utility>

template <class T>
inline void PrintList(T* a, const int n)
{
    for (int i = 0; i < n; i++)
        std::cout << std::setw(2) << a[i] << " \n"[i == n - 1 ? 1 : 0];
}

template <class T>
inline void QSortTrace(T* a, const int n, const int l, const int r)
{
    for (int i = 0; i < n; i++) std::cout << std::setw(2) << a[i] << ' ';
    std::cout << std::setw(2) << l + 1 << ' ' << std::setw(2) << r + 1 << '\n';
}

// Similar to std::swap(T& a, T& b)
template <class T>
void Swap(T& a, T& b)
{
    if (a == b) return;
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template <class T>
void InsertionSort(T* a, const int n)
{
    for (int i = 1; i < n; i++) {
        T tmp = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > tmp; j--) a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}

template <class T>
void QuickSort(T* a, const int left, const int right)
{
    if (left + 1 >= right) return;

    T& pivot = a[left];
    int i = left + 1, j = right;

    while (i < j) {
        // TODO
        // while (a[i] <= pivot) i++;
        // while (a[j] > pivot) j--;
        while (i < j && a[j] > pivot) j--;
        while (i < j && a[i] < pivot) i++;
        if (i >= j) break;
        Swap(a[i], a[j]);
    }
    // The if condition is for the case when left + 1 == right
    if (a[j] < pivot) Swap(pivot, a[j]);

    QuickSort(a, left, j - 1);
    QuickSort(a, j + 1, right);
}

template <class T>
void Merge(T* a, const int l, const int m, const int n)
{
    int i = 0, j = l, k = m + 1, merged_size = n - l + 1;
    T* merged_list = new T[merged_size];

    // each loop merges two sublists of size
    for (; j <= m && k <= n; i++)
        if (a[j] <= a[k]) merged_list[i] = a[j++];
        else merged_list[i] = a[k++];
    if (j <= m) std::copy(a + j, a + m + 1, merged_list + i);
    else if (k <= n) std::copy(a + k, a + n + 1, merged_list + i);
    std::copy(merged_list, merged_list + merged_size, a + l);

    delete[] merged_list;
}

template <class T>
void IterativeMergeSort(T* a, const int n)
{
    // l is the size of each sublist
    // and each loop is a MERGEPASS
    for (int l = 1; l < n; l *= 2) {
        // merge from left to right
        int i = 0;

        // each loop merges two sublists of size l
        for (; i + 2 * l - 1 < n; i += 2 * l)
            Merge(a, i, i + l - 1, i + 2 * l - 1);

        // i + l - 1 < n indicates that the 2nd sublist is of size < l,
        // so merge the remaining sublists of unequal size.
        if (i + l - 1 < n) Merge(a, i, i + l - 1, n - 1);
    }
}

template <class T>
void RecursiveMergeSort(T* a, const int left, const int right)
{
    if (left >= right) return;

    // Sort the left and right parts and merge them
    int mid = (right + left) / 2;
    RecursiveMergeSort(a, left, mid);
    RecursiveMergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

template <class T>
void BubbleDown(T* heap, int r, const int n)
{
    T e = heap[r];
    for (r *= 2; r <= n; r *= 2) {
        if (r < n && heap[r] < heap[r + 1]) r++;
        if (e >= heap[r]) break;
        heap[r / 2] = heap[r];
    }
    heap[r / 2] = e;
}

template <class T>
void HeapSort(T* a, const int n)
{
    // initialize heap
    T* heap = new T[n + 1];
    std::copy(a, a + n, heap + 1);

    for (int i = n / 2; i; i--) BubbleDown(heap, i, n);

    for (int i = n - 1; i; i--) {
        Swap(heap[1], heap[i + 1]);
        BubbleDown(heap, 1, i);
    }

    std::copy(heap + 1, heap + n + 1, a);
    delete[] heap;
}
