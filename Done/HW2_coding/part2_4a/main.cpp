#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "Stack.h"

using MAZE = std::vector<std::vector<bool>>;

int m, p;
MAZE maze, mark;
enum directions { N, NE, E, SE, S, SW, W, NW };
const int move[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                        {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

void PrintStackPath(Stack<std::tuple<int, int, int>>);

// This Path function is implemented using recursion.
void PathRecursive(const int& i, const int& j, const int& d = E,
                   Stack<std::tuple<int, int, int>> s = {})
{
    // EXIT REACHED
    if (i == m - 1 && j == p - 1) {
        s.Push(std::make_tuple(i, j, d));
        mark[i][j] = true;
        PrintStackPath(s);
        return;
    }

    // INVALID MOVE
    if (i < 0 || i >= m || j < 0 || j >= p || maze[i][j] || mark[i][j]) return;

    // VALID MOVE
    s.Push(std::make_tuple(i, j, d));
    mark[i][j] = true;

    // NEXT MOVE
    for (int d = 0; d < 8; d++)
        PathRecursive(i + move[d][0], j + move[d][1], d, s);
};

int main()
{
    std::ifstream maze_file("maze.txt");
    maze_file >> m >> p;
    std::cout << m << ' ' << p << '\n';
    maze = MAZE(m);
    mark = MAZE(m);
    for (int i = 0; i < m; i++) {
        maze[i] = std::vector<bool>(p);
        mark[i] = std::vector<bool>(p);
        for (int j = 0; j < p; j++) {
            int tmp;
            maze_file >> tmp;
            maze[i][j] = tmp;
        }
    }

    // std::cout << "MAZE:\n";
    // for (auto row : maze) {
    //     for (int ele : row) std::cout << ele << ' ';
    //     std::cout << std::endl;
    // }

    PathRecursive(0, 0);

    // std::cout << "MARK:\n";
    // for (auto row : mark) {
    //     for (int ele : row) std::cout << ele << ' ';
    //     std::cout << std::endl;
    // }

    return 0;
}

void PrintStackPath(Stack<std::tuple<int, int, int>> s)
{
    Stack<std::tuple<int, int, int>> path;
    for (; !s.IsEmpty(); s.Pop()) path.Push(s.Top());

    std::cout << "Start!\n";
    for (; !path.IsEmpty(); path.Pop()) {
        auto [i, j, d] = path.Top();
        std::string direction;
        switch (d) {
            case 0: direction = "N"; break;
            case 1: direction = "NE"; break;
            case 2: direction = "E"; break;
            case 3: direction = "SE"; break;
            case 4: direction = "S"; break;
            case 5: direction = "SW"; break;
            case 6: direction = "W"; break;
            case 7: direction = "NW"; break;
        }
        std::cout << "(" << i << ", " << j << ", " << direction << ")\n";
    }
    std::cout << "Maze Exit Reached!\n";
};
