
#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using MatrixRow = std::vector<int>;
using AdjacencyMatrix = std::vector<MatrixRow>;
using EDGE = std::tuple<int, int, int>;
using EDGES = std::vector<EDGE>;

class MatrixWDigraph
{
    friend std::ostream& operator<<(std::ostream& out, const MatrixWDigraph& g);

public:
    MatrixWDigraph(int n)
        : n(n), e(0), adj_matrix(AdjacencyMatrix(n, MatrixRow(n, 0)))
    {}
    MatrixWDigraph(int n, EDGES edges) : MatrixWDigraph(n)
    {
        for (auto [u, v, w] : edges) InsertEdge(u, v, w);
    }

    // destructor
    ~MatrixWDigraph() {}

    bool isEmpty() const { return n == 0; }
    int NumberOfVertices() const { return n; }
    int NumberOfEdges() const { return e; }

    // return the degree of vertex u
    int Degree(int u) const;

    bool ExistsEdge(int u, int v) const;
    void InsertVertex(int v);
    void InsertEdge(int u, int v, int w);
    void DeleteVertex(int v);
    void DeleteEdge(int u, int v);

    void BFS(int v) const;
    void DFS(int v) const;
    void RecursiveDFS(int v) const;
    void RecursiveDFS(int v, std::vector<bool>& visited) const;
    void Component() const;

private:
    AdjacencyMatrix adj_matrix;
    int n, e;
};