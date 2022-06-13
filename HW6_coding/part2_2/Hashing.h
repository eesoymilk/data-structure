#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

inline int h(const char*);

inline void Probe(int&);

void PrintKey(const char*, const int idx = -1);

class LinearProbing
{
public:
    LinearProbing();
    void Insert(const char*);
    const char* Search(const char*) const;

    void PrintHT() const;

private:
    char* ht[26];
};

struct ChainNode {
    char* key;
    ChainNode* link;

    ChainNode();
    ChainNode(const char*);
};

void PrintKeyList(const ChainNode*, const int);

class Chaining
{
public:
    Chaining();
    void Insert(const char*);
    const char* Search(const char*) const;

    void PrintHT() const;

private:
    ChainNode* ht[26];
};
