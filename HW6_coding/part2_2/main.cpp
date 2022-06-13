#include <iostream>

#include "Hashing.h"

int main()
{
    const char* KEYS[10] = {"abc",          "abcde",   "b",    "bye",
                            "cool",         "jotaro",  "jojo", "giogio",
                            "dagakotowaru", "wakuwaku"};
    LinearProbing d1;
    Chaining d2;

    for (int i = 0; i < 10; i++) d1.Insert(KEYS[i]);
    d1.PrintHT();
    for (int i = 0; i < 5; i++) PrintKey(d1.Search(KEYS[i]));
    PrintKey(d1.Search("girlfriend"));

    for (int i = 0; i < 10; i++) d2.Insert(KEYS[i]);
    d2.PrintHT();
    for (int i = 5; i < 10; i++) PrintKey(d1.Search(KEYS[i]));
    PrintKey(d2.Search("programmingskill"));

    std::cin.get();

    return 0;
}