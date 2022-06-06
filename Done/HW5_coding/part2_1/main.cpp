#include "LinkedGraph.h"

// using EDGE = std::pair<int, int>;
// using EDGES = std::vector<EDGE>;

void ShowResult(const LinkedGraph& G, const int& i)
{
    std::cout << "G" << i << '\n' << G;
    std::cout << "\n1. BFS(v)\n";
    std::cout << "G" << i << ".BFS(0): ";
    G.BFS(0);
    std::cout << "G" << i << ".BFS(3): ";
    G.BFS(3);
    std::cout << "G" << i << ".BFS(7): ";
    G.BFS(7);
    std::cout << "\n2. DFS(v)\n";
    std::cout << "G" << i << ".DFS(0): ";
    G.DFS(0);
    std::cout << "G" << i << ".DFS(3): ";
    G.DFS(3);
    std::cout << "G" << i << ".DFS(7): ";
    G.DFS(7);
    std::cout << "\n3. Component()\n";
    G.Component();
    std::cout << "\n4. DfnLow(v)\n";
    std::cout << "\nG" << i << ".DfnLow(0):\n";
    G.DfnLow(0);
    std::cout << "\nG" << i << ".DfnLow(3):\n";
    G.DfnLow(3);
    std::cout << "\nG" << i << ".DfnLow(7):\n";
    G.DfnLow(7);
    std::cout << '\n';
}

int main()
{
    EDGES g1_edges = {{0, 1}, {1, 3}, {3, 2}, {2, 0}, {4, 5}, {5, 6}, {6, 7}},
          g2_edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5},
                      {2, 6}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
          g3_edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5},
                      {5, 6}, {5, 7}, {6, 7}, {7, 8}, {7, 9}};
    LinkedGraph G1(8, g1_edges), G2(8, g2_edges), G3(10, g3_edges);

    std::cout << "For this program, "
                 "I will show the adjacency list of the graph first,\n"
                 "and then "
                 "I will show the results according to the problems.\n";

    ShowResult(G1, 1);
    ShowResult(G2, 2);
    ShowResult(G3, 3);
    return 0;
}