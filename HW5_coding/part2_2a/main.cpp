#include "MatrixWDigraph.h"

using AdjacencyMatrix = std::vector<std::vector<int>>;
using EDGE = std::tuple<int, int, int>;
using EDGES = std::vector<EDGE>;

int main()
{
    EDGES g1_1_edges = {{1, 0, 300},  {2, 0, 1000}, {2, 1, 800},  {3, 2, 1200},
                        {4, 3, 1500}, {4, 5, 250},  {5, 3, 1000}, {5, 6, 900},
                        {5, 7, 1400}, {6, 7, 1000}, {7, 0, 1700}};
    MatrixWDigraph G1(8, g1_1_edges);
    std::cout << G1;

    return 0;
}