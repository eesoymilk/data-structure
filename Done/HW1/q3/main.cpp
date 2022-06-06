#include <iostream>
#define MAX_N 100

// Base class for general matrices
class Matrix
{
private:
    double mat[MAX_N][MAX_N];
    int row, col;

public:
    Matrix() : row(0), col(0) { memset(mat, 0, sizeof(mat)); }
    Matrix(int r, int c) : row(r), col(c) { memset(mat, 0, sizeof(mat)); }

    double *operator[](const int &x) { return mat[x]; }
    const double *operator[](const int &x) const { return mat[x]; }
    Matrix operator+(const Matrix &x) const;
    Matrix operator-(const Matrix &x) const;
    friend Matrix operator*(const Matrix &x, const Matrix &y);
    friend class ComplexMatrix;
};

Matrix Matrix::operator+(const Matrix &x) const
{
    Matrix res(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = mat[i][j] + x[i][j];
    return res;
}

Matrix Matrix::operator-(const Matrix &x) const
{
    Matrix res(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = mat[i][j] - x[i][j];
    return res;
}

Matrix operator*(const Matrix &x, const Matrix &y)
{
    Matrix res(x.row, y.col);
    for (int i = 0; i < x.row; i++)
        for (int j = 0; j < x.col; j++)
            for (int k = 0; k < y.col; k++)
                res[i][k] += x[i][j] * y[j][k];
    return res;
}

// Class for complex-valued matrices
class ComplexMatrix
{
private:
    Matrix A, B;
    int row, col;

public:
    ComplexMatrix()
    {
        A = Matrix();
        B = Matrix();
    }
    ComplexMatrix(int r, int c) : row(r), col(c)
    {
        A = Matrix(r, c);
        B = Matrix(r, c);
    }
    ComplexMatrix operator+(const ComplexMatrix &x) const;
    ComplexMatrix operator-(const ComplexMatrix &x) const;
    friend ComplexMatrix operator*(const ComplexMatrix &x, const ComplexMatrix &y);
};

ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix &x) const
{
    ComplexMatrix res(row, col);
    res.A = A + x.A;
    res.B = B + x.B;
    return res;
}

ComplexMatrix ComplexMatrix::operator-(const ComplexMatrix &x) const
{
    ComplexMatrix res(row, col);
    res.A = A - x.A;
    res.B = B - x.B;
    return res;
}

ComplexMatrix operator*(const ComplexMatrix &x, const ComplexMatrix &y)
{
    ComplexMatrix res = ComplexMatrix(x.row, y.col);
    res.A = res.A + x.A * y.A - x.B * y.B;
    res.B = res.B + x.A * y.B + x.B * y.A;
    return res;
}

int main()
{

    return 0;
}