#include <iostream>
#include <random>
#include <string>

#include "Sorting.h"

enum MODE { INITIAL, INSERTION, QUICK, I_MERGE, R_MERGE, HEAP };
int n = 20;
std::random_device rd;
std::mt19937_64 mt(rd());

char* RandomCharList(const int n)
{
    std::uniform_int_distribution<int> dist(0, 51);
    char* l = new char[n];
    for (int i = 0; i < n; i++) {
        int rng = dist(mt);
        if (rng < 26) rng += 'A';
        else rng += 'a' - 26;
        l[i] = (char)rng;
    }
    return l;
}

int* RandomIntList(const int n, const int lb, const int ub)
{
    std::uniform_int_distribution<int> dist(lb, ub);
    int* l = new int[n];
    for (int i = 0; i < n; i++) l[i] = dist(mt);
    return l;
}

float* RandomFloatList(const int n, const float lb, const float ub)
{
    std::uniform_real_distribution<float> dist(lb, ub);
    float* l = new float[n];
    for (int i = 0; i < n; i++) l[i] = dist(mt);
    return l;
}

std::string* RandomStringList(const int n)
{
    std::uniform_int_distribution<int> dist1(2, 10);
    std::uniform_int_distribution<int> dist2(0, 51);
    std::string* l = new std::string[n];
    for (int i = 0; i < n; i++) {
        std::string s;
        int random_size = dist1(mt);
        while (random_size--) {
            int rng = dist2(mt);
            if (rng < 26) rng += 'A';
            else rng += 'a' - 26;
            s += (char)rng;
        }
        l[i] = s;
    }
    return l;
}

void ShowResults(const int& mode, char* random_char_list, int* random_int_list,
                 float* random_float_list, std::string* random_string_list)
{
    // make copies of the input lists
    char* sorted_char_list = new char[n];
    int* sorted_int_list = new int[n];
    float* sorted_float_list = new float[n];
    std::string* sorted_string_list = new std::string[n];
    std::copy(random_char_list, random_char_list + n, sorted_char_list);
    std::copy(random_int_list, random_int_list + n, sorted_int_list);
    std::copy(random_float_list, random_float_list + n, sorted_float_list);
    for (int i = 0; i < n; i++) sorted_string_list[i] = random_string_list[i];

    // sort the lists
    switch (mode) {
        case INITIAL:
            std::cout << "\"\"\"All input lists are generated using a 64-bit "
                         "Mersenne Twister.\"\"\"\n\n";
            std::cout << "Input lists:\n";
            break;

        case INSERTION:
            std::cout << "\nInsertion sort:\n";
            InsertionSort(sorted_char_list, n);
            InsertionSort(sorted_int_list, n);
            InsertionSort(sorted_float_list, n);
            InsertionSort(sorted_string_list, n);
            break;
        case QUICK:
            std::cout << "\nMedian-of-three quick sort:\n";
            QuickSort(sorted_char_list, 0, n - 1);
            QuickSort(sorted_int_list, 0, n - 1);
            QuickSort(sorted_float_list, 0, n - 1);
            QuickSort(sorted_string_list, 0, n - 1);
            break;
        case I_MERGE:
            std::cout << "\nIterative merge sort:\n";
            IterativeMergeSort(sorted_char_list, n);
            IterativeMergeSort(sorted_int_list, n);
            IterativeMergeSort(sorted_float_list, n);
            IterativeMergeSort(sorted_string_list, n);
            break;
        case R_MERGE:
            std::cout << "\nRecursive merge sort:\n";
            RecursiveMergeSort(sorted_char_list, 0, n - 1);
            RecursiveMergeSort(sorted_int_list, 0, n - 1);
            RecursiveMergeSort(sorted_float_list, 0, n - 1);
            RecursiveMergeSort(sorted_string_list, 0, n - 1);
            break;
        case HEAP:
            std::cout << "\nHeap sort:\n";
            HeapSort(sorted_char_list, n);
            HeapSort(sorted_int_list, n);
            HeapSort(sorted_float_list, n);
            HeapSort(sorted_string_list, n);
    }

    // output results
    std::cout << "  Character list: ";
    PrintList(sorted_char_list, n);
    std::cout << "  Integer list: ";
    PrintList(sorted_int_list, n);
    std::cout << "  Float list: ";
    PrintList(sorted_float_list, n);
    std::cout << "  String list: ";
    PrintList(sorted_string_list, n);
}

int main()
{
    char* random_char_list = RandomCharList(n);
    int* random_int_list = RandomIntList(n, 1, 100);
    float* random_float_list = RandomFloatList(n, 1.0, 10.0);
    std::string* random_string_list = RandomStringList(n);

    for (int mode = INITIAL; mode <= HEAP; mode++)
        ShowResults(mode, random_char_list, random_int_list, random_float_list,
                    random_string_list);

    return 0;
}