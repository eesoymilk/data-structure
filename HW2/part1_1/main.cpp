#include <iostream>
#include <stack>

int main()
{
    std::stack<int> vertical_track, left_track, right_track;

    right_track = std::stack<int>({4, 3, 2, 1});
    while (!right_track.empty() || !vertical_track.empty()) {
        if (!right_track.empty()) {
            int right_top = right_track.top();
            vertical_track.push(right_top);
            right_track.pop();
        }
        if (!vertical_track.empty()) {
            int vertical_top = vertical_track.top();
            left_track.push(vertical_top);
            vertical_track.pop();
        }
    }

    return 0;
}