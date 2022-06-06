#include "LinkedGraph.h"

bool LinkedGraph::ExistsEdge(int u, int v) const
{
    for (int i : adj_lists[u])
        if (i == v) return true;
    return false;
}

void LinkedGraph::InsertVertex(int v)
{
    n++;
    adj_lists.insert(adj_lists.begin() + v, std::list<int>(0));
}

void LinkedGraph::InsertEdge(int u, int v)
{
    e++;
    adj_lists[u].push_back(v);
    adj_lists[v].push_back(u);
}

void LinkedGraph::DeleteVertex(int v)
{
    n--;
    for (int del : adj_lists[v])
        adj_lists[del].remove_if([=](const int& ele) { return ele == v; });
    adj_lists.erase(adj_lists.begin() + v);
}

void LinkedGraph::DeleteEdge(int u, int v)
{
    e--;
    adj_lists[u].remove_if([=](const int& ele) { return ele == v; });
    adj_lists[v].remove_if([=](const int& ele) { return ele == u; });
}

void LinkedGraph::BFS(int v) const
{
    std::queue<int> q;
    std::vector<bool> visited(n, false);
    q.push(v);
    visited[v] = true;
    std::cout << v << ' ';
    while (!q.empty()) {
        v = q.front();
        q.pop();
        std::for_each(adj_lists[v].begin(), adj_lists[v].end(),
                      [&](const int& ele) {
                          if (!visited[ele]) {
                              q.push(ele);
                              visited[ele] = true;
                              std::cout << ele << ' ';
                          }
                      });
    }
    std::cout << '\n';
}

void LinkedGraph::DFS(int v) const
{
    std::stack<int> s;
    std::vector<bool> visited(n, false);
    s.push(v);
    while (!s.empty()) {
        v = s.top();
        s.pop();
        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << ' ';
        }
        std::for_each(adj_lists[v].begin(), adj_lists[v].end(),
                      [&](const int& ele) {
                          if (!visited[ele]) s.push(ele);
                      });
    }
    std::cout << '\n';
}

void LinkedGraph::RecursiveDFS(int v) const
{
    std::vector<bool> visited(n, false);
    RecursiveDFS(v, visited);
    std::cout << '\n';
}

void LinkedGraph::RecursiveDFS(int v, std::vector<bool>& visited) const
{
    visited[v] = true;
    std::cout << v << ' ';
    std::for_each(adj_lists[v].begin(), adj_lists[v].end(),
                  [&](const int& nxt) {
                      if (!visited[nxt]) RecursiveDFS(nxt, visited);
                  });
}

void LinkedGraph::Component() const
{
    std::vector<bool> visited(n, false);
    int compont_count = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        std::cout << "Component #" << ++compont_count << ": ";
        std::stack<int> s;
        s.push(i);
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            if (!visited[v]) {
                visited[v] = true;
                std::cout << v << ' ';
            }
            std::for_each(adj_lists[v].begin(), adj_lists[v].end(),
                          [&](const int& ele) {
                              if (!visited[ele]) s.push(ele);
                          });
        }
        std::cout << '\n';
    }
}

void LinkedGraph::DfnLow(const int x) const
{
    std::vector<int> dfn(n, 0), low(n, 0);
    int cur_dfn = 1;
    DfnLow(x, -1, cur_dfn, dfn, low);
    std::cout << "  v |";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(3) << i << "\0\n"[i + 1 == n ? 1 : 0];
    std::cout << std::setfill('-') << std::setw(3 * n + 6) << "\n"
              << std::setfill(' ');
    std::cout << "dfn |";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(3) << dfn[i] << "\0\n"[i + 1 == n ? 1 : 0];
    std::cout << "low |";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(3) << low[i] << "\0\n"[i + 1 == n ? 1 : 0];
}

void LinkedGraph::DfnLow(const int u, const int v, int& cur_dfn,
                         std::vector<int>& dfn, std::vector<int>& low) const
{
    dfn[u] = low[u] = cur_dfn++;
    std::for_each(adj_lists[u].begin(), adj_lists[u].end(), [&](const int& w) {
        if (dfn[w] == 0) {
            DfnLow(w, u, cur_dfn, dfn, low);
            low[u] = std::min(low[u], low[w]);
        } else if (w != v) {
            low[u] = std::min(low[u], dfn[w]);
        }
    });
}

// void LinkedGraph::DfnLow(const int x) const
// {
//     std::vector<int> dfn(n, 0), low(n, 0);
//     std::stack<int> s;
//     int cur_dfn = 0, parent = -1;
//     s.push(x);
//     while (!s.empty()) {
//         int now = s.top();
//         s.pop();
//         if (dfn[now] == 0) {
//             dfn[now] = low[now] = ++cur_dfn;
//             // low[parent] = std::min(low[parent], low[now]);
//             parent = now;
//         }
//         std::for_each(adj_lists[now].begin(), adj_lists[now].end(),
//                       [&](const int& nxt) {
//                           if (dfn[nxt] == 0) {
//                               s.push(nxt);
//                           } else if (nxt != parent) {
//                               low[now] = std::min(low[now], dfn[nxt]);
//                           } else {
//                               //   low[now] = std::min(low[now], low[nxt]);
//                           }
//                       });
//     }
//     std::cout << "vertex: ";
//     for (int i = 0; i < n; i++) std::cout << i << " \n"[i + 1 == n ? 1 : 0];
//     std::cout << "dfn:    ";
//     for (int i = 0; i < n; i++)
//         std::cout << dfn[i] << " \n"[i + 1 == n ? 1 : 0];
//     std::cout << "low:    ";
//     for (int i = 0; i < n; i++)
//         std::cout << low[i] << " \n"[i + 1 == n ? 1 : 0];
// }

std::ostream& operator<<(std::ostream& out, const std::list<int>& l)
{
    for (auto v : l) out << v << ' ';
    return out;
}

std::ostream& operator<<(std::ostream& out, const LinkedGraph& g)
{
    for (int i = 0; i < g.adj_lists.size(); i++)
        if (!g.adj_lists[i].empty())
            out << '#' << i << ": " << g.adj_lists[i] << '\n';
    return out;
}