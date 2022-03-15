#include "SparseMatrix.h"

// class MatrixTerm
// 	   int row, col, value;
// class SparseMatrix
// 	   int rows, cols;
// 	   std::vector<MatrixTerm> smArray = std::vector<MatrixTerm>(0);

void SparseMatrix::StoreSum(const int sum, const int r, const int c)
{
	if (sum == 0) return;
	smArray.push_back(MatrixTerm(r, c, sum));
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix b(cols, rows);
	if (smArray.empty()) return b;
	// b.smArray = std::vector<MatrixTerm>();

	std::vector<int> rowSize(cols), rowStart(cols);

	for (auto smTerm : smArray) rowSize[smTerm.col]++;
	for (int i = 1; i < cols; i++) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	for (auto smTerm : smArray) {
		int idx = rowStart[smTerm.col];
		b.smArray.push_back(MatrixTerm(smTerm.row, smTerm.col, smTerm.value));
		rowStart[smTerm.col]++;
	}

	return b;
}

SparseMatrix SparseMatrix::Add(SparseMatrix b)
{

}

SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{

}

std::istream &operator>>(std::istream &in, SparseMatrix &sm)
{
	return in;
}

std::ostream &operator<<(std::ostream &out, SparseMatrix &sm)
{
	for (auto smTerm : sm.smArray) {
		const auto [row, col, value] = smTerm.getTerm();
		out << '(' << row << ',' << col << ',' << value << ')';
	}
	return out;
}