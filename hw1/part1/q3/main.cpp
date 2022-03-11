#include <iostream>
#include <iomanip>
#include <vector>

#define MAX_N 100

class Matrix
{
private:
    double mat[MAX_N][MAX_N];
    int row, col;
public:
    Matrix(): row(0), col(0) { memset(mat, 0, sizeof(mat)); }
    Matrix(int r, int c): row(r), col(c) { memset(mat, 0, sizeof(mat)); }
    const int &getrow() { return row; }
    const int &getcol() { return col; }

    double *operator[] (const int &x) { return mat[x]; }
    const double *operator[] (const int &x) const { return mat[x]; }
    Matrix operator+ (const Matrix &x) const;
    Matrix operator- (const Matrix &x) const;
    friend Matrix operator* (const Matrix &x, const Matrix &y);
    void print()
	{
        for(int i=0;i<row;i++) {
            if(i==0) std::cout << "/";
            else if(i==row-1) std::cout << "\\";
            else std::cout << "|";
            for(int j=0;j<col;j++) {
                std::cout << std::right << std::setw(8) << mat[i][j];
            }
            if(i==0) std::cout << " \\\n";
            else if(i==row-1) std::cout << " /\n";
            else std::cout << " |\n";
        }
    }
	friend class ComplexMatrix;
};

Matrix Matrix::operator+(const Matrix &x) const
{
    Matrix res(row, col);
    for (int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
        	res[i][j] = mat[i][j] + x[i][j];
    return res;
}

Matrix Matrix::operator-(const Matrix &x) const
{
    Matrix res(row, col);
    for (int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
        	res[i][j] = mat[i][j] - x[i][j];
    return res;
}

// Not Member Function but "friend"
Matrix operator* (const Matrix &x, const Matrix &y)
{
    Matrix res(x.row, y.col);
    for (int i = 0; i < x.row; i++)
		for (int j = 0; j < x.col; j++)
			for (int k = 0; k < y.col; k++)
        		res[i][k] += x[i][j] * y[j][k];
    return res;
}

class ComplexMatrix
{
private:
	Matrix A, B;
	int row, col;
public:
	ComplexMatrix() {
		A = Matrix();
		B = Matrix();
	}
	ComplexMatrix(int r, int c): row(r), col(c) {
		A = Matrix(r, c);
		B = Matrix(r, c);
	}
	ComplexMatrix operator+ (const ComplexMatrix &x) const;
    ComplexMatrix operator- (const ComplexMatrix &x) const;
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

ComplexMatrix operator*(const ComplexMatrix &x, const ComplexMatrix &y) {
	ComplexMatrix res = ComplexMatrix(x.row, y.col);
	res.A = res.A + x.A * y.A - x.B * y.B;
	res.B = res.B + x.A * y.B + x.B * y.A;
	return res;
}


int main()
{
	return 0;
}