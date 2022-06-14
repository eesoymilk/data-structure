#include <iostream>

#include "Hashing.h"

int main()
{
    const char* KEYS[10] = {"abc",          "abcde",   "b",    "bye",
                            "cool",         "jotaro",  "jojo", "giogio",
                            "dagakotowaru", "wakuwaku"};
    LinearProbing d1;
    Chaining d2;

    std::cout << "I will use the following 10 keys for this progarm.\n"
                 "KEYS[10] = {\"abc\", \"abcde\", \"b\", \"bye\", \"cool\", "
                 "\"jotaro\",\"jojo\", \"giogio\", \"dagakotowaru\", "
                 "\"wakuwaku\"}\n\n";

    std::cout << "For both classes, I wrote PrintHT() function to print out "
                 "the hash table.\n\n";

    std::cout << "Linear Probing:\n";
    std::cout << "\nInsert(const char* k):\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "d1.Insert(\"" << KEYS[i] << "\")\n";
        d1.Insert(KEYS[i]);
    }
    std::cout << "\nPrintHT():\n";
    std::cout << "d1.PrintHT():\n";
    d1.PrintHT();
    std::cout << "\nSearch(const char* k):\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "d1.Search(\"" << KEYS[i] << "\"): ";
        PrintKey(d1.Search(KEYS[i]));
    }
    std::cout << "d1.Search(\"girlfriend\"): ";
    PrintKey(d1.Search("girlfriend"));

    std::cout << "\n\nChaining:\n";

    std::cout << "\nInsert(const char* k):\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "d2.Insert(\"" << KEYS[i] << "\")\n";
        d2.Insert(KEYS[i]);
    }
    std::cout << "\nPrintHT():\n";
    std::cout << "d2.PrintHT():\n";
    d2.PrintHT();
    std::cout << "\nSearch(const char* k):\n";
    for (int i = 5; i < 10; i++) {
        std::cout << "d2.Search(\"" << KEYS[i] << "\"): ";
        PrintKey(d2.Search(KEYS[i]));
    }
    std::cout << "d2.Search(\"girlfriend\"): ";
    PrintKey(d2.Search("girlfriend"));

    return 0;
}