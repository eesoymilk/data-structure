#include "SparseMatrix.h"

MatrixNode::MatrixNode(bool b,
                       std::tuple<int, int, int> t = std::make_tuple(0, 0, 0))
{
    is_head = b;
    if (b) right = down = this;
    else triple = t;
}

Matrix::Matrix() {}

Matrix::Matrix(const Matrix &a)
{
    auto [rows, cols, n] = a.head->triple;
    head = new MatrixNode(false, a.head->triple);

    int p = std::max(rows, cols);
    std::vector<MatrixNode *> heads;
    for (int i = 0; i < p; i++) heads.push_back(new MatrixNode(true));
    for (int i = 0; i < p; i++) heads[i]->next = heads[i];

    int cur_row = 0;
    MatrixNode *last = heads[cur_row];
    MatrixNode *cur_head = a.head->right;
    for (; cur_head != a.head; cur_head = cur_head->next) {
        MatrixNode *cur_col = cur_head->right;
        for (; cur_col != cur_head; cur_col = cur_col->right) {
            auto [r, c, v] = cur_col->triple;
            if (r > cur_row) {
                last->right = heads[cur_row];
                cur_row = r;
                last = heads[cur_row];
            }
            last = last->right =
                new MatrixNode(false, std::make_tuple(r, c, v));
            heads[c]->next = heads[c]->next->down = last;
        }
    }

    last->right = heads[cur_row];
    for (int i = 0; i < cols; i++) heads[i]->next->down = heads[i];
    for (int i = 0; i < p - 1; i++) heads[i]->next = heads[i + 1];
    heads[p - 1]->next = head;
    head->right = heads[0];
}

Matrix::~Matrix() {}

const Matrix Matrix::Transpose() const
{
    Matrix T, m = *this;

    auto [cols, rows, n] = m.head->triple;
    T.head = new MatrixNode(false, m.head->triple);

    int p = std::max(rows, cols);
    std::vector<MatrixNode *> heads;
    for (int i = 0; i < p; i++) heads.push_back(new MatrixNode(true));
    for (int i = 0; i < p; i++) heads[i]->next = heads[i];

    int cur_col = 0;
    MatrixNode *last = heads[cur_col];
    MatrixNode *cur_head = m.head->right;
    for (; cur_head != m.head; cur_head = cur_head->next) {
        MatrixNode *cur_row = cur_head->down;
        for (; cur_row != cur_head; cur_row = cur_row->down) {
            auto [c, r, v] = cur_row->triple;
            if (c > cur_col) {
                last->down = heads[cur_col];
                cur_col = c;
                last = heads[cur_col];
            }
            last = last->down = new MatrixNode(false, std::make_tuple(r, c, v));
            heads[r]->next = heads[r]->next->right = last;
        }
    }
    last->down = heads[cur_col];

    for (int i = 0; i < rows; i++) heads[i]->next->right = heads[i];
    for (int i = 0; i < p - 1; i++) heads[i]->next = heads[i + 1];
    heads[p - 1]->next = T.head;
    T.head->right = heads[0];

    return T;
}

Matrix &Matrix::operator+(const Matrix &b) const
{
    auto [rows, cols, n] = head->triple;
    auto [b_rows, b_cols, b_n] = b.head->triple;
    if (!(rows == b_rows && cols == b_cols)) return;

    Matrix res;

    res.head = new MatrixNode(false, std::make_tuple(rows, cols, n));

    return res;
}

Matrix &Matrix::operator*(const Matrix &b) const {}

std::istream &operator>>(std::istream &in, Matrix &m)
{
    int rows, cols, n;
    in >> rows >> cols >> n;
    int p = std::max(rows, cols);
    m.head = new MatrixNode(false, std::make_tuple(rows, cols, n));
    if (p == 0) {
        m.head->right = m.head;
        return in;
    }
    std::vector<MatrixNode *> heads;
    for (int i = 0; i < p; i++) heads.push_back(new MatrixNode(true));
    for (int i = 0; i < p; i++) heads[i]->next = heads[i];
    int cur_row = 0;
    MatrixNode *last = heads[0];
    for (int i = 0; i < n; i++) {
        int r, c, v;
        in >> r >> c >> v;
        if (r > cur_row) {
            last->right = heads[cur_row];
            cur_row = r;
            last = heads[cur_row];
        }
        last = last->right = new MatrixNode(false, std::make_tuple(r, c, v));
        heads[c]->next = heads[c]->next->down = last;  // fuck this
    }
    last->right = heads[cur_row];
    for (int i = 0; i < cols; i++) heads[i]->next->down = heads[i];
    for (int i = 0; i < p - 1; i++) heads[i]->next = heads[i + 1];
    heads[p - 1]->next = m.head;
    m.head->right = heads[0];

    return in;
}

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    MatrixNode *cur_head = m.head->right;
    for (; cur_head != m.head; cur_head = cur_head->next) {
        MatrixNode *cur_col = cur_head->right;
        for (; cur_col != cur_head; cur_col = cur_col->right) {
            auto [r, c, v] = cur_col->triple;
            out << '(' << r << ", " << c << ", " << v << ")\n";
        }
    }
    return out;
}
