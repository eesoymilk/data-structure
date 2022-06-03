#include "MatrixWDigraph.h"

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
                        {5, 3, 5},  {5, 4, 10}},
          g2_1_edges = {{0, 1, 6},  {0, 2, 5}, {0, 3, 5},  {1, 4, -1},
                        {2, 1, -2}, {2, 4, 1}, {3, 2, -2}, {3, 5, -1},
                        {4, 6, 3},  {5, 6, 3}},
          g2_2_edges = {{0, 1, 7}, {0, 2, 5}, {1, 2, -5}},
          g3_edges = {{0, 1, 4}, {0, 2, 11}, {1, 0, 6}, {1, 2, 2}, {2, 0, 3}};

    MatrixWDigraph G1_1(8, g1_1_edges), G1_2(6, g1_2_edges),
        G1_3(6, g1_3_edges), G2_1(7, g2_1_edges), G2_2(3, g2_2_edges),
        G3(3, g3_edges);

    std::cout << "For this program, "
                 "I will show the adjacency matrix of the graph first,\n"
                 "and then "
                 "I will show the results according to the problems.\n"
                 "Note that I denote infinity as INF.\n";

    std::cout << "\n(a) Dijkstra\n";
    std::cout << "\nG1_1:\n" << G1_1 << '\n';
    G1_1.ShortestPath(4);
    std::cout << "\nG1_2:\n" << G1_2 << '\n';
    G1_2.ShortestPath(0);
    std::cout << "\nG1_3:\n" << G1_3 << '\n';
    G1_3.ShortestPath(0);

    std::cout << "\n(b) Bellman-Ford\n";
    std::cout << "\nG2_1:\n" << G2_1 << '\n';
    G2_1.BellmanFord(0);
    std::cout << "\nG2_2:\n" << G2_2 << '\n';
    G2_2.BellmanFord(0);

    std::cout << "\n(c) Floyd\n";
    std::cout << "Note that the adjacency matrix is not shown since\n"
                 "A_{-1} is the adjacency matrix.\n";
    std::cout << "\nG3:\n";
    G3.AllLengths();
    std::cout << "\nG2_1:\n";
    G2_1.AllLengths();

    return 0;
}