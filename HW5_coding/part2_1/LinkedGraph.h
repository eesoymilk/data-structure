
#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "GraphABC.h"

using AdjacencyLists = std::vector<std::list<int>>;
using EDGE = std::pair<int, int>;
using EDGES = std::vector<EDGE>;

class LinkedGraph : public GraphABC
{
    friend std::ostream& operator<<(std::ostream& out, const LinkedGraph& g);

public:
    LinkedGraph(int n) : GraphABC(n), adj_lists(AdjacencyLists(n)) {}
    LinkedGraph(int n, EDGES edges) : LinkedGraph(n)
    {
        for (auto [u, v] : edges) InsertEdge(u, v);
    }

    // destructor
    ~LinkedGraph() {}

    // return the degree of vertex u
    int Degree(int u) const { return adj_lists[u].size(); }

    bool ExistsEdge(int u, int v) const;
    void InsertVertex(int v);
    void InsertEdge(int u, int v);
    void DeleteVertex(int v);
    void DeleteEdge(int u, int v);

    void BFS(int v) const;
    void DFS(int v) const;
    void RecursiveDFS(int v) const;
    void RecursiveDFS(int v, std::vector<bool>& visited) const;
    void Component() const;
    void DfnLow(const int x) const;
    void DfnLow(const int u, const int v, int& cur_dfn, std::vector<int>& dfn,
                std::vector<int>& low) const;

private:
    AdjacencyLists adj_lists;
};