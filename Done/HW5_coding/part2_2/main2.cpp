#include "MatrixWDigraph.h"

int main()
{
    EDGES G_edges = {{0, 1, 15}, {0, 2, 16}, {1, 0, 2},  {1, 4, 10},
                     {1, 5, 10}, {2, 3, 4},  {2, 5, 10}, {4, 3, 15},
                     {5, 3, 4},  {5, 4, 10}};

    MatrixWDigraph G(6, G_edges);

    std::cout << "\nG:\n" << G << '\n';
    G.ShortestPath(0);

    return 0;
}