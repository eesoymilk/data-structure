#include "SparseMatrix.h"

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

std::ostream &operator>>(std::ostream &out, Matrix &m)
{
    ;
    return out;
}
