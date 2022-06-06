#pragma once

class GraphABC
{
public:
    GraphABC(int n) : n(n), e(0) {}
    // destructor
    virtual ~GraphABC() {}

    // return the degree of vertex u
    virtual int Degree(int u) const = 0;

    virtual bool ExistsEdge(int u, int v) const = 0;
    virtual void InsertVertex(int v) = 0;
    virtual void InsertEdge(int u, int v) = 0;
    virtual void DeleteVertex(int v) = 0;
    virtual void DeleteEdge(int u, int v) = 0;

    virtual void BFS(int v) const = 0;
    virtual void DFS(int v) const = 0;
    virtual void Component() const = 0;
    virtual void DfnLow(const int x) const = 0;

protected:
    int n, e;
};