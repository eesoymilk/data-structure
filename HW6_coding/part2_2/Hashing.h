#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

inline int h(const char*);

inline void Probe(int&);

class LinearProbing
{
public:
    LinearProbing();
    void Insert(const char*);
    char* Search(const char*);

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

class Chaining
{
public:
    Chaining();
    void Insert(const char*);
    char* Search(const char*);

    void PrintHT() const;

private:
    ChainNode* ht[26];
};
