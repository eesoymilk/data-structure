#include "LinkedGraph.h"

// using EDGE = std::pair<int, int>;
// using EDGES = std::vector<EDGE>;

int main()
{
    // EDGES g1_edges = {{0, 1}, {1, 3}, {3, 2}, {2, 0}, {4, 5}, {5, 6}, {6,
    // 7}},
    //       g2_edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5},
    //                   {2, 6}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
    //       g3_edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5},
    //                   {5, 6}, {5, 7}, {6, 7}, {7, 8}, {7, 9}};
    // LinkedGraph G1(8, g1_edges), G2(8, g2_edges), G3(10, g3_edges);

    // std::cout << "G1\n" << G1;
    // G1.Component();

    // std::cout << "\nG2\n" << G2;
    // G2.Component();

    // std::cout << "\nG3\n" << G3;
    // // G3.Component();
    // std::cout << "DFS:    ";
    // G3.RecursiveDFS(3);
    // G3.DfnLow(3);
    EDGES g1_edges = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
                      {4, 6}, {5, 6}, {5, 7}, {5, 8}, {6, 7}, {7, 8}};
    LinkedGraph G(9, g1_edges);
    std::cout << "G:\n" << G;
    std::cout << "\nDFS: ";
    G.DFS(1);
    std::cout << "BFS: ";
    G.BFS(1);
    return 0;
}