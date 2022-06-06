#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define MAX (int)1e6

using MatrixRow = std::vector<int>;
using Matrix = std::vector<MatrixRow>;
using EDGE = std::tuple<int, int, int>;
using EDGES = std::vector<EDGE>;

class MatrixWDigraph
{
    friend std::ostream& operator<<(std::ostream& out, const MatrixWDigraph& g);

public:
    // constructor
    MatrixWDigraph(int);
    MatrixWDigraph(int, EDGES);

    // destructor
    ~MatrixWDigraph() {}

    void ShortestPath(const int v) const;
    void BellmanFord(const int v) const;
    void AllLengths() const;

private:
    Matrix adj_matrix;
    int n, e;
};