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
	if (smArray.empty()) return SparseMatrix(cols, rows);

	// create an empty sparse matrix with empty terms
	// note that this implementation is resposible for filling the terms
	SparseMatrix b(cols, rows, smArray.size());
	std::vector<int> rowSize(cols), rowStart(cols);

	// calcualte row size of the transpose in advanced
	for (auto smTerm : smArray) rowSize[smTerm.col]++;
	// prefix sum to get the starting index of each row
	for (int i = 1; i < cols; i++) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	for (auto smTerm : smArray) {
		int idx = rowStart[smTerm.col];
		b.smArray[idx] = MatrixTerm(smTerm.col, smTerm.row, smTerm.value);
		rowStart[smTerm.col]++;
	}

	return b;
}

SparseMatrix SparseMatrix::Add(SparseMatrix b)
{
	if (rows != b.rows || cols != b.cols) throw "Incompatible matrices";

	SparseMatrix res(rows, cols);
	int a_idx = 0, b_idx = 0, a_size = smArray.size(), b_size = b.smArray.size();
	// while (a_idx < a_size || b_idx < b_size) {
	// 	if (smArray[a_idx].row > smArray[b_idx])
	// }

	return res;
}

SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{
	if (cols != b.rows) throw "Incompatible matrices";

	int a_idx = 0, b_idx = 0;
	SparseMatrix res(rows, b.cols), b_transpose = b.Transpose();
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < b.cols; c++) {
			int val = 0;
			while (smArray[a_idx].row <= r 
				&& b_transpose.smArray[b_idx].row <= r)
			{
				if (smArray[a_idx].row < r) {
					a_idx++;
					continue;
				}
				if (b_transpose.smArray[b_idx].row < r){
					b_idx++;
					continue;
				}
				if (smArray[a_idx].col == b_transpose.smArray[b_idx].col)
					val += smArray[a_idx].value * b_transpose.smArray[b_idx].value;
				else if (smArray[a_idx].col > b_transpose.smArray[b_idx].col)
					b_idx++;
				else
					a_idx++;
			}
			if (val != 0) res.smArray.push_back(MatrixTerm(r, c, val));
		}
	}

	return res;
}

std::istream &operator>>(std::istream &in, SparseMatrix &sm)
{
	int r, c, t, v;

	std::cout << "Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)\n";
	std::cin >> r >> c >> t;
	sm = SparseMatrix(r, c);
	std::cout << "Now, enter each term's row, col, and value: (seperating them whith a white space)\n";
	for (int i = 0; i < t; i++) {
		std::cout << '#' << i + 1 << ": ";
		std::cin >> r >> c >> v;
		sm.smArray.push_back(MatrixTerm(r, c, v));
	}
	
	return in;
}

std::ostream &operator<<(std::ostream &out, const SparseMatrix &sm)
{
	for (int i = 0; i < sm.smArray.size(); i++) {
		const auto [row, col, value] = sm.smArray[i].getTerm();
		out << '#' << i + 1 << ": (" << row << ", " << col << ", " << value << ")\n";
	}
	return out;
}
