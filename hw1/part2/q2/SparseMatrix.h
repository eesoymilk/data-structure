#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include <iostream>
#include <vector>

class MatrixTerm
{
friend class SparseMatrix;
private:
	int row, col, value;
public:
	MatrixTerm() {}
	MatrixTerm(int r, int c, int val): row(r), col(c), value(val) {}
};

// A set of triples, <row, column, value>, where row and column are non-
// negative integers and form a unique combination; value is also an integer.
class SparseMatrix
{
private:
	int rows, cols;
	std::vector<MatrixTerm> smArray = std::vector<MatrixTerm>(0);
public:
	// The constructor function creates a SparseMatrix with r rows, c columns.
    SparseMatrix(int r, int c): rows(r), cols(c) {};

	// If sum != 0, then it along with its row and colum postition are stored
	// as last term in *this.
	void StoreSum(const int sum, const int r, const int c);

	// Returns the SparseMatrix obtained by interchanging the row and column
	// value of every triple in *this.
	// This function is implemented by FastTranspose.
    SparseMatrix Transpose();

	// If the dimensions of *this and b are the same, then the matrix produced
	// by adding corresponding items, namely those with identical row and
	// column values is returned; otherwise, an exception is thrown.
    SparseMatrix Add(SparseMatrix b);

	// If the number of columns in *this equals the number of rows in b then
	// the matrix d produced by multiplying *this and b according to the
	// formula d[i][j] = Σ(a[i][k]．b[k][j]), where d[i][j] is the (i, j)th
	// element, is returned. k ranges form 0 to one less than the number of
	// columns of *this; otherwise, an exception is thrown.
    SparseMatrix Multiply(SparseMatrix b);

	// input function
	friend std::istream &operator>>(std::istream &in, SparseMatrix &sm);

	// output function
	friend std::ostream &operator<<(std::ostream &out, SparseMatrix &sm);
};

#endif
