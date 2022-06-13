#include "Hashing.h"

inline int h(const char* k) { return k[0] - 'a'; }

inline void Probe(int& i) { i = (i + 1) % 26; }

LinearProbing::LinearProbing() { std::fill(ht, ht + 26, nullptr); }

void LinearProbing::Insert(const char* k)
{
    int i = h(k), j = i;

    if (ht[j]) {
        for (Probe(j); i != j && ht[j]; Probe(j))
            if (!std::strcmp(k, ht[j])) return;
        if (i == j) return;
    }

    int l = std::strlen(k);
    ht[j] = new char[std::strlen(k) + 1];
    std::strncpy(ht[j], k, l);
    ht[j][l] = '\0';
}

char* LinearProbing::Search(const char* k)
{
    int i = h(k), l = std::strlen(k);

    if (!ht[i]) return nullptr;
    if (!std::strncmp(k, ht[i], l + 1)) return ht[i];

    int j = i;
    for (Probe(j); i != j; Probe(j)) {
        std::cout << j;
        if (!std::strncmp(k, ht[j], l + 1)) return ht[j];
    }
    return nullptr;
}

void LinearProbing::PrintHT() const
{
    for (int i = 0; i < 26; i++) {
        if (!ht[i]) continue;
        int l = std::strlen(ht[i]);
        std::cout << (char)(i + 'a') << ": ";
        for (int j = 0; j < l; j++) std::cout << ht[i][j];
        std::cout << '\n';
    }
}

ChainNode::ChainNode() : key(nullptr), link(nullptr) {}

ChainNode::ChainNode(const char* k) : link(nullptr)
{
    int l = std::strlen(k);
    key = new char[l + 1];
    std::strncpy(key, k, l);
    key[l] = '\0';
}

Chaining::Chaining() { std::fill(ht, ht + 26, nullptr); }

void Chaining::Insert(const char* k)
{
    int i = h(k);
    if (!ht[i]) {
        ht[i] = new ChainNode(k);
        return;
    }

    ChainNode *now = ht[i], *prev = now;
    while (now) {
        prev = now;
        now = now->link;
    }
    prev->link = new ChainNode(k);
}

char* Chaining::Search(const char* k)
{
    ChainNode *now = ht[h(k)], *prev = now;
    while (now) {
        if (!std::strcmp(k, now->key)) return now->key;
        std::cout << "help\n";
        prev = now;
        now = now->link;
    }
    return nullptr;
}

void Chaining::PrintHT() const
{
    for (int i = 0; i < 26; i++) {
        if (!ht[i]) continue;
        std::cout << (char)(i + 'a') << ": ";
        ChainNode *now = ht[i], *prev = now;
        while (now) {
            int l = std::strlen(now->key);
            for (int j = 0; j < l; j++) std::cout << (now->key)[j];

            if (now = now->link) std::cout << " -> ";
        }
        std::cout << '\n';
    }
}
