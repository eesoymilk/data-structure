#include <iostream>
#include "String.h"

int main()
{
    String s1, s2, s3, s4, pat;

    std::cout << "Type in the first string, s1: ";
    std::cin >> s1;
    std::cout << "Type in s2: ";
    std::cin >> s2;
    std::cout << "Adding two strings s1 + s2 to create a new string s3...\n";
    s3 = s1.Concat(s2);
    std::cout << "s3: " << s1.Concat(s2) << '\n';

    return 0;
}