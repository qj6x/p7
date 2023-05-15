#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Trie
{
public:
    bool isWord;
    Trie *children[26];
};

#endif