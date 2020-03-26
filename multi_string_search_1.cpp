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
        int n = str.size();
        for (int i = 0; i < n; i++) {
            TrieNode *cur = root;
            for (int j = i; j < n; j++) {
                if (!cur->children.count(str[j])) {
                    cur->children[str[j]] = new TrieNode();
                }
                cur = cur->children[str[j]];
            }
            cur->children[endSymbol] = NULL;
        }
        return;
    }

    bool contains(string str) {
        TrieNode *cur = root;
        for (char ch: str) {
            if (!cur->children.count(ch)) {
                return false;
            }
            cur = cur->children[ch];
        }
        return true;
    }
};

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
    SuffixTrie trie(bigString);
    vector<bool> res;
    for (auto& str: smallStrings) {
        res.push_back(trie.contains(str));
    }
    return res;
}
