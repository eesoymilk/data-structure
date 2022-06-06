#include "Polynomial.h"

void PrintAv()
{
    Node<Term> *now = CircularList<Term>::av;
    std::cout << "av: ";
    for (; now != nullptr; now = now->link) {
        std::cout << '(' << now->data.coef << ", " << now->data.exp << ')'
                  << " \n"[now->link == nullptr ? 1 : 0];
    }
}

int main()
{
    Polynomial p1, p2;

    std::cout << "(a) std::istream& operator>>(istream& is, Polynomial& x):\n";
    std::cout << "Enter a polynomial p1: ";
    std::cin >> p1;
    std::cout << "Enter a polynomial p2: ";
    std::cin >> p2;

    std::cout << "\n(b) std::ostream& operator<<(ostream& os, "
              << "Polynomial& x):\n";
    std::cout << "p1: " << p1;
    std::cout << "p2: " << p2;

    std::cout << "\n(c) Polynomial(const Polynomial& a):\n";
    std::cout << "There are two ways to initialize an object using copy "
                 "constructor:\n"
              << "1, Polynomial p3 = p1\n"
              << "2, Polynomial p4(p2)\n";
    Polynomial p3 = p1;
    Polynomial p4(p2);
    std::cout << "p3: " << p3;
    std::cout << "p4: " << p4;

    std::cout << "\n(d) operator=(const Polynomial& a):";
    std::cout << "We can use the assignment operator as shown,\n"
              << "Polynomial p5;\n"
              << "p5 = p1\n";
    Polynomial p5;
    p5 = p1;
    std::cout << "p5: " << p5;

    std::cout << "\n(e) ~Polynomial():";
    std::cout << "To test if the destructor is working properly,\n"
              << "we will first manually call the destructor "
              << "on one of the polynomial,\n"
              << "and then print out the av list.\n"
              << "Note that the additional node is the head.\n";
    std::cout << "p5.~Polynomial()\n";
    p5.~Polynomial();
    PrintAv();

    std::cout << "\n(f) operator+(const Polynomial& b):\n";
    std::cout << "p1 + p2: " << p1 + p2;

    std::cout << "\n(g) operator-(const Polynomial& b):\n";
    std::cout << "p1 - p2: " << p1 - p2;

    std::cout << "\n(h) operator*(const Polynomial& b):\n";
    std::cout << "p1 * p2: " << p1 * p2;

    std::cout << "\n(i) Evaluate(double x):\n";
    std::cout << "p1.Evaluate(6.9): " << p1.Evaluate(6.9) << '\n';

    return 0;
}