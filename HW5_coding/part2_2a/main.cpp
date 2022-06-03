#include "MatrixWDigraph.h"

using AdjacencyMatrix = std::vector<std::vector<int>>;
using EDGE = std::tuple<int, int, int>;
using EDGES = std::vector<EDGE>;

int main()
{
    EDGES g1_1_edges = {{1, 0, 300},  {2, 0, 1000}, {2, 1, 800},  {3, 2, 1200},
                        {4, 3, 1500}, {4, 5, 250},  {5, 3, 1000}, {5, 6, 900},
                        {5, 7, 1400}, {6, 7, 1000}, {7, 0, 1700}},
          g1_2_edges = {{0, 1, 50}, {0, 2, 45}, {0, 3, 10}, {1, 2, 10},
                        {1, 3, 15}, {2, 4, 30}, {3, 0, 20}, {3, 4, 15},
                        {4, 1, 20}, {4, 2, 35}, {5, 4, 3}},
          g1_3_edges = {{0, 1, 20}, {0, 2, 15}, {1, 0, 2},  {1, 4, 10},
                        {1, 5, 30}, {2, 3, 4},  {2, 5, 10}, {4, 3, 15},
                        {5, 3, 5},  {5, 4, 10}};
    MatrixWDigraph G1_1(8, g1_1_edges), G1_2(6, g1_2_edges),
        G1_3(6, g1_3_edges);
    // std::cout << G1_1;
    G1_1.ShortestPath(4);
    // std::cout << G1_2;
    G1_2.ShortestPath(0);
    // std::cout << G1_3;
    G1_3.ShortestPath(0);

    std::cin.get();
    return 0;
}