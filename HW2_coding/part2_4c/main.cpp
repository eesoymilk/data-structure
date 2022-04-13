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

void Path()
{
    Stack<std::tuple<int, int, int>> s;
    s.Push(std::make_tuple(0, 0, E));

    while (!s.IsEmpty()) {
        std::tuple<int, int, int> tmp = s.Top();
        s.Pop();
        auto [i, j, d] = tmp;
        std::cout << "Pop (" << i << ", " << j << ", " << d << ")\n";
        while (d < 8) {
            int i_nxt = i + move[d][0], j_nxt = j + move[d][1];
            if (i_nxt == m - 1 && j_nxt == p - 1) {
                mark[i_nxt][j_nxt] = true;
                std::cout << "Push (" << i << ", " << j << ", " << d << ")\n";
                s.Push(std::make_tuple(i, j, d));
                std::cout << "Push (" << i_nxt << ", " << j_nxt << ", " << d
                          << ")\n\n";
                s.Push(std::make_tuple(i_nxt, j_nxt, d));
                std::cout << "Trace out path:\n";
                PrintStackPath(s);
                return;
            }
            if (i_nxt < 0 || i_nxt >= m || j_nxt < 0 || j_nxt >= p ||
                maze[i_nxt][j_nxt] || mark[i_nxt][j_nxt]) {
                d++;
                continue;
            }
            std::cout << "Push (" << i << ", " << j << ", " << d << ")\n";
            mark[i_nxt][j_nxt] = true;
            s.Push(std::make_tuple(i, j, d));
            i = i_nxt, j = j_nxt, d = N;
        }
    }
};

int main()
{
    std::ifstream maze_file("maze.txt");
    maze_file >> m >> p;
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

    Path();

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
