#include "MatrixWDigraph.h"

#include <iomanip>

void MatrixWDigraph::InsertEdge(int u, int v, int w)
{
    e++;
    adj_matrix[u][v] = w;
}

void MatrixWDigraph::BFS(int v) const {}

void MatrixWDigraph::DFS(int v) const {}

void MatrixWDigraph::RecursiveDFS(int v) const {}

void MatrixWDigraph::RecursiveDFS(int v, std::vector<bool>& visited) const {}

void MatrixWDigraph::Component() const {}

std::ostream& operator<<(std::ostream& out, const MatrixWDigraph& g)
{
    for (auto row : g.adj_matrix) {
        for (auto w : row) out << std::setw(5) << w << ' ';
        out << '\n';
    }
    out << '\n';
    return out;
}