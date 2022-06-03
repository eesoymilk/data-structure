#include "MatrixWDigraph.h"

#include <iomanip>

struct Label {
    int index, length, predecessor;
    Label(int i = 0, int l = 0, int p = 0) : index(i), length(l), predecessor(p)
    {}
};

void PrintDijkstraLength(const std::vector<Label>& labels, const int v,
                         const int iteration_count)
{
    std::cout << "#" << iteration_count << " | " << v << " |";
    for (auto label : labels) {
        if (label.length == MAX) std::cout << std::setw(5) << "INF";
        else std::cout << std::setw(5) << label.length;
    }
    std::cout << '\n';
}

void PrintBellmanFordLength(const std::vector<int>& dists, const int k)
{
    std::cout << k << " |";
    for (auto d : dists) {
        if (d == MAX) std::cout << std::setw(4) << "INF";
        else std::cout << std::setw(4) << d;
    }
    std::cout << '\n';
}

void PrintPath(const std::vector<Label>& labels, const int start, const int end)
{
    std::stack<int> s;

    for (int idx = end; idx != start; idx = labels[idx].predecessor)
        s.push(idx);

    s.push(start);
    for (; !s.empty(); s.pop()) std::cout << s.top() << ' ';
    std::cout << "=> " << labels[end].length << '\n';
}

void PrintPaths(const std::vector<Label>& labels, const int& v)
{
    std::vector<Label> sorted_labels = labels;
    std::sort(
        sorted_labels.begin(), sorted_labels.end(),
        [&](const Label& a, const Label& b) { return a.length < b.length; });

    for (int i = 1; i < sorted_labels.size(); i++)
        if (sorted_labels[i].length != MAX) {
            std::cout << i << ") ";
            PrintPath(labels, v, sorted_labels[i].index);
        }
}

inline void PrintAllLengths(const Matrix& A, const int& k)
{
    int n = A.size();
    std::cout << "A^" << std::setw(2) << std::left << k << '|' << std::right;
    for (int i = 0; i < n; i++)
        std::cout << std::setw(4) << i << "\0\n"[i + 1 == n ? 1 : 0];
    std::cout << std::setfill('-') << std::setw(n * 4 + 4) << "\n";
    std::cout << std::setfill(' ');
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(3) << i << " |";
        for (int j = 0; j < n; j++) {
            if (A[i][j] >= MAX) std::cout << std::setw(4) << "INF";
            else std::cout << std::setw(4) << A[i][j];
            if (j == n - 1) std::cout << '\n';
        }
    }
    std::cout << '\n';
}

MatrixWDigraph::MatrixWDigraph(int n)
    : n(n), e(0), adj_matrix(Matrix(n, MatrixRow(n, MAX)))
{
    for (int i = 0; i < n; i++) adj_matrix[i][i] = 0;
}

MatrixWDigraph::MatrixWDigraph(int n, EDGES edges) : MatrixWDigraph(n)
{
    e = n;
    for (auto [u, v, w] : edges) adj_matrix[u][v] = w;
}

void MatrixWDigraph::ShortestPath(const int v) const
{
    std::set<int> s, all_vertices;
    std::vector<Label> labels;
    for (int i = 0; i < n; i++) {
        all_vertices.insert(i);
        labels.push_back(Label(i, adj_matrix[v][i], v));
    }
    s.insert(v);
    int iteration_count = 0, u = v;

    std::cout << "Distance (i donotes iteration, v denotes vertex):\n";
    std::cout << " i | v |";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(5) << i << "\0\n"[i + 1 == n ? 1 : 0];
    std::cout << std::setfill('-') << std::setw(n * 5 + 9) << "\n";
    std::cout << std::setfill(' ');

    while (s != all_vertices) {
        PrintDijkstraLength(labels, u, iteration_count++);
        int tmp = MAX;
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end() && labels[i].length < tmp) {
                tmp = labels[i].length;
                u = i;
            }
        }
        if (!s.insert(u).second) break;
        for (int w = 0; w < n; w++) {
            int length = labels[u].length + adj_matrix[u][w];
            if (s.find(w) == s.end() && length < labels[w].length) {
                labels[w].length = length;
                labels[w].predecessor = u;
            }
        }
    }
    std::cout << "\nPaths (path => length):\n";
    PrintPaths(labels, v);
}

void MatrixWDigraph::BellmanFord(const int v) const
{
    std::vector<int> dists(adj_matrix[v]), prev_dists;

    std::cout << "dist^k[" << n << "]:\n";
    std::cout << "k |";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(4) << i << "\0\n"[i == n - 1 ? 1 : 0];
    std::cout << std::setfill('-') << std::setw((n + 1) * 4) << "\n";
    std::cout << std::setfill(' ');

    for (int k = 1; k < n; k++) {
        PrintBellmanFordLength(dists, k);
        prev_dists = dists;
        for (int u = 0; u < n; u++) {
            if (u == v) continue;
            for (int i = 0; i < n; i++) {
                if (i == u || adj_matrix[i][u] >= MAX) continue;
                if (dists[u] > prev_dists[i] + adj_matrix[i][u])
                    dists[u] = prev_dists[i] + adj_matrix[i][u];
            }
        }
    }
}

void MatrixWDigraph::AllLengths() const
{
    Matrix A(adj_matrix);

    PrintAllLengths(A, -1);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (A[i][k] >= MAX) continue;
            for (int j = 0; j < n; j++) {
                if (A[k][j] >= MAX) continue;
                if (A[i][k] + A[k][j] < A[i][j]) A[i][j] = A[i][k] + A[k][j];
            }
        }
        PrintAllLengths(A, k);
    }
}

std::ostream& operator<<(std::ostream& out, const MatrixWDigraph& g)
{
    int n = g.adj_matrix.size();
    out << "  |";
    for (int i = 0; i < n; i++)
        out << std::setw(5) << i << "\0\n"[i + 1 == n ? 1 : 0];
    out << std::setfill('-') << std::setw(n * 5 + 4) << "\n";
    out << std::setfill(' ');
    for (int i = 0; i < n; i++) {
        out << i << " |";
        for (int j = 0; j < n; j++) {
            if (g.adj_matrix[i][j] == MAX) out << std::setw(5) << "INF";
            else out << std::setw(5) << g.adj_matrix[i][j];
            if (j == n - 1) out << '\n';
        }
    }
    return out;
}