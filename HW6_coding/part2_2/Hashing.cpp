#include "Hashing.h"

inline int h(const char* k) { return k[0] - 'a'; }

inline void Probe(int& i) { i = (i + 1) % 26; }

void PrintKey(const char* k, const int idx)
{
    if (idx != -1) std::cout << (char)(idx + 'a') << ": ";
    if (!k) {
        std::cout << "this is a non-existing key\n";
        return;
    }

    int l = std::strlen(k);
    for (int j = 0; j < l; j++) std::cout << k[j] << "\0\n"[j == l - 1 ? 1 : 0];
}

LinearProbing::LinearProbing() { std::fill(ht, ht + 26, nullptr); }

void LinearProbing::Insert(const char* k)
{
    int i = h(k), j = i, l = std::strlen(k);

    if (ht[j]) {
        for (Probe(j); i != j && ht[j]; Probe(j))
            if (!std::strncmp(k, ht[j], l + 1)) return;
        if (i == j) return;
    }

    ht[j] = new char[l + 1];
    std::strncpy(ht[j], k, l);
    ht[j][l] = '\0';
}

const char* LinearProbing::Search(const char* k) const
{
    int i = h(k), l = std::strlen(k);
    if (!ht[i]) return nullptr;
    if (!std::strncmp(k, ht[i], l + 1)) return ht[i];

    int j = i;
    for (Probe(j); i != j; Probe(j))
        if (ht[j] && !std::strncmp(k, ht[j], l + 1)) return ht[j];
    return nullptr;
}

void LinearProbing::PrintHT() const
{
    for (int i = 0; i < 26; i++) {
        if (!ht[i]) continue;
        PrintKey(ht[i], i);
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

const char* Chaining::Search(const char* k) const
{
    ChainNode *now = ht[h(k)], *prev = now;
    int l = std::strlen(k);
    while (now) {
        if (!std::strncmp(k, now->key, l + 1)) return now->key;
        prev = now;
        now = now->link;
    }
    return nullptr;
}

void PrintKeyList(const ChainNode* now, const int idx)
{
    if (!now) return;
    std::cout << (char)(idx + 'a') << ": ";
    while (now) {
        int l = std::strlen(now->key);
        for (int i = 0; i < l; i++) std::cout << now->key[i];
        if (now = now->link) std::cout << " -> ";
    }
    std::cout << '\n';
}

void Chaining::PrintHT() const
{
    for (int i = 0; i < 26; i++) PrintKeyList(ht[i], i);
}
