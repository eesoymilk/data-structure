#include <iostream>

#include "Hashing.h"

void PrintKey(const char* k)
{
    if (!k) {
        std::cout << "this is a non-existing key\n";
        return;
    }

    int l = std::strlen(k);
    for (int j = 0; j < l; j++)
        std::cout << k + j << "\0\n"[j == l - 1 ? 1 : 0];
}

int main()
{
    const char* KEYS[10] = {"abc",          "abcde",   "b",    "bye",
                            "cool",         "jotaro",  "jojo", "giogio",
                            "dagakotowaru", "wakuwaku"};
    LinearProbing d1;
    Chaining d2;

    for (int i = 0; i < 10; i++) {
        d1.Insert(KEYS[i]);
        d2.Insert(KEYS[i]);
    }

    // d1.PrintHT();
    // for (int i = 0; i < 5; i++) PrintKey(d1.Search(KEYS[i]));
    PrintKey(d1.Search("girlfriend"));

    // d2.PrintHT();
    // for (int i = 0; i < 5; i++) PrintKey(d1.Search(KEYS[i]));
    // PrintKey(d2.Search("programmingskill"));

    std::cin.get();

    return 0;
}