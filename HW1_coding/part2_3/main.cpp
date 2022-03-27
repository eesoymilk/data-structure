#include <iostream>
#include "String.h"

int main()
{
    String s1, s2, s3, s4, pat;
    int start, l;
    char c;

    std::cout << "Enter 4 arbitrary strings\n";
    std::cout << "s1: ";
    std::cin >> s1;
    std::cout << "s2: ";
    std::cin >> s2;
    std::cout << "s3: ";
    std::cin >> s3;
    std::cout << "s4: ";
    std::cin >> s4;

    std::cout << "String::operator==\n";
    std::cout << "s1 == s3: " << (s1 == s3) << '\n';
    std::cout << "String::operator!\n";
    std::cout << "!s1: " << !s1 << '\n';
    std::cout << "String::Length():\n";
    std::cout << "s1.Length() = " << s1.Length() << '\n';
    std::cout << "s2.Length() = " << s2.Length() << '\n';
    std::cout << "String::Concat():\n";
    std::cout << "s1.Concat(s2) = " << s1.Concat(s2) << '\n';
    std::cout << "s3.Concat(s4) = " << s3.Concat(s4) << '\n';

    std::cout << "\nEnter a string pat to test FastFind\n";
    std::cout << "pat: ";
    std::cin >> pat;
    std::cout << "s3.FastFind(pat) = " << s3.FastFind(pat) << '\n';
    std::cout << "s4.FastFind(pat) = " << s4.FastFind(pat) << '\n';

    std::cout << "\nEnter a 2 integer start and l to test Delete\n";
    std::cout << "start: ";
    std::cin >> start;
    std::cout << "l: ";
    std::cin >> l;
    std::cout << "s1.Delete(start, l) = " << s1.Delete(start, l) << '\n';
    std::cout << "s2.Delete(start, l) = " << s2.Delete(start, l) << '\n';

    std::cout << "\nEnter a char c and test CharDelete\n";
    std::cout << "c: ";
    std::cin >> c;
    std::cout << "s3.CharDelete(c) = " << s3.CharDelete(c) << '\n';
    std::cout << "s4.CharDelete(c) = " << s4.CharDelete(c) << '\n';

    return 0;
}