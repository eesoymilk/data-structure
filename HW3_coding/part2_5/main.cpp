#include "SparseMatrix.h"

int main()
{
    Matrix m1, m2, m3;

    std::cout << "Enter a sparse matrix m1:\n";
    std::cin >> m1;
    std::cout << "Enter a sparse matrix m2:\n";
    std::cin >> m2;
    std::cout << "Enter a sparse matrix m3:\n";
    std::cin >> m3;

    std::cout << "\n(a) operator+(const Matrix& b):\n";
    std::cout << "m1 + m2:\n" << m1 + m2;

    std::cout << "\n(b) operator*(const Matrix& b):\n";
    std::cout << "m1 * m3:\n" << m1 * m3;

    std::cout << "\n(c) std::ostream& operator<<(ostream& os, "
              << "Matrix& x):\n";
    std::cout << "m1:\n" << m1;
    std::cout << "m2:\n" << m2;
    std::cout << "m3:\n" << m3;

    std::cout << "\n(d) Transpose():\n";
    std::cout << "m1.Transpose():\n" << m1.Transpose() << '\n';

    std::cout << "\n(e) Matrix(const Matrix& a):\n";
    std::cout << "There are two ways to initialize an object using copy "
                 "constructor:\n"
              << "1, Matrix m4 = m1\n"
              << "2, Matrix m5(m2)\n";
    Matrix m4 = m1;
    Matrix m5(m2);
    std::cout << "m4:\n" << m4;
    std::cout << "m5:\n" << m5;

    return 0;
}