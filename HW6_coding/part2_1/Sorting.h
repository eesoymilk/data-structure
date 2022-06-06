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
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template <class T>
void InsertionSort(T* a, const int n)
{
    T tmp;
    int i = 1;
    std::cout << std::setw(2) << i << ": ";
    PrintList(a, n);
    for (; i < n; i++) {
        tmp = a[i];
        int j = i - 1;
        for (; a[j] > tmp; j--) a[j + 1] = a[j];
        a[j + 1] = tmp;
        std::cout << std::setw(2) << i + 1 << ": ";
        PrintList(a, n);
    }
}

template <class T>
void QuickSort(T* a, const int n, const int left, const int right)
{
    if (left >= right) return;
    QSortTrace(a, n, left, right);

    T& pivot = a[left];
    int i = left + 1, j = right;

    while (true) {
        // TODO
        while (a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) break;
        Swap(a[i], a[j]);
    }
    Swap(pivot, a[j]);

    QuickSort(a, n, left, j - 1);
    QuickSort(a, n, j + 1, right);
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
