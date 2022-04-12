#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Path(const int m, const int p) {}

int main()
{
    int m, p;

    std::ifstream maze_file("maze.txt");
    maze_file >> m >> p;

    std::vector<std::vector<int>> maze(m);
    for (size_t i = 0; i < m; i++) {
        maze[i] = std::vector<int>(p);
        for (size_t j = 0; j < p; j++) maze_file >> maze[i][j];
    }

    // for (auto row : maze) {
    //     for (int ele : row) std::cout << ele << ' ';
    //     std::cout << std::endl;
    // }

    return 0;
}