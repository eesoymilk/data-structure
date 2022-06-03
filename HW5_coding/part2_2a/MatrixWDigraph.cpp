#include "MatrixWDigraph.h"

#include <iomanip>

void PrintLength(const std::vector<std::pair<int, int>>& labels, const int v,
                 const int iteration_count)
{
    if (iteration_count == 0) std::cout << "Initial ";
    else std::cout << "     #" << iteration_count << ' ';
    std::cout << std::setw(6) << v;
    for (auto label : labels) {
        auto [l, pre] = label;
        if (l == MAX) std::cout << std::setw(5) << "INF" << ' ';
        else std::cout << std::setw(5) << l << ' ';
    }
    std::cout << '\n';
}

// void PrintPath(const std::vector<std::pair<int, int>>& labels, const int
// start,
//                const int end)
// {
//     std::stack<int> s;
//     int idx = end;
//     while (idx != start) {
//         s.push(idx);
//         idx = labels[idx].second;
//     }
//     s.push(start);
//     for (; !s.empty(); s.pop()) std::cout << s.top() << ' ';
//     std::cout << ": " << labels[end].first << '\n';
// }

void PrintPath(const std::vector<std::pair<int, int>>& labels, const int start,
               const int end)
{
    std::stack<int> s;
    int idx = end;
    while (idx != start) {
        s.push(idx);
        idx = labels[idx].second;
    }
    s.push(start);
    for (; !s.empty(); s.pop()) std::cout << s.top() << ' ';
    std::cout << ": " << labels[end].first << '\n';
}

MatrixWDigraph::MatrixWDigraph(int n)
    : n(n), e(0), adj_matrix(AdjacencyMatrix(n, MatrixRow(n, MAX)))
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
    std::vector<std::pair<int, int>> labels(n);
    for (int i = 0; i < n; i++) {
        all_vertices.insert(i);
        labels[i] = std::make_pair(adj_matrix[v][i], v);
    }
    s.insert(v);
    int iteration_count = 0, u = v;

    std::cout << std::setw(14) << "Vertex";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(5) << i << " \n"[i + 1 == n ? 1 : 0];

    while (s != all_vertices) {
        PrintLength(labels, u, iteration_count++);
        int tmp = MAX;
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end() && labels[i].first < tmp) {
                tmp = labels[i].first;
                u = i;
            }
        }
        if (!s.insert(u).second) break;
        for (int w = 0; w < n; w++) {
            int length = labels[u].first + adj_matrix[u][w];
            if (s.find(w) == s.end() && length < labels[w].first)
                labels[w] = std::make_pair(length, u);
        }
    }
    // for (int i = 0; i < n; i++)
    //     if (i != v && labels[i].first != MAX) PrintPath(labels, v, i);
}

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
        for (auto w : row) {
            if (w == MAX) std::cout << std::setw(5) << "INF" << ' ';
            else std::cout << std::setw(5) << w << ' ';
        }
        out << '\n';
    }
    out << '\n';
    return out;
}