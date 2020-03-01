#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str) {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void populateSuffixTrieFrom(string str) {

    }

    bool contains(string str) {

    }
};
