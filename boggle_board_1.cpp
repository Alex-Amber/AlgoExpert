#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

struct TrieNode {
    unordered_map<char, TrieNode *> children;
};

class Trie {
public:
    TrieNode *root;
    char endSymbol;

    Trie(char ch) {
        this->root = new TrieNode();
        endSymbol = ch;
    }

    void addStringToTrie(string& str) {
        TrieNode *cur = root;
        for (char ch: str) {
            if (!cur->children.count(ch)) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->children[endSymbol] = NULL;
    }
};

void dfs(unordered_set<string>& found, vector<vector<char>>& board, vector<vector<int>>& colors,
         TrieNode *cur, string& word, int x, int y, char endSymbol) {
    if (!cur->children.count(board[x][y])) {
        return;
    }
    int m = board.size(), n = board[0].size();
    word.push_back(board[x][y]);
    colors[x][y] = 1;
    cur = cur->children[board[x][y]];
    if (cur->children.count(endSymbol)) {
        found.insert(word);
    }
    for (int i = 0; i < 8; i++) {
        int adjX = x + dx[i], adjY = y + dy[i];
        if (adjX < 0 || adjX >= m || adjY < 0 || adjY >= n || colors[adjX][adjY] != 0) {
            continue;
        }
        dfs(found, board, colors, cur, word, adjX, adjY, endSymbol);
    }
    word.pop_back();
    colors[x][y] = 0;
    return;
}

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> colors(m, vector<int>(n, 0));
    Trie trie('*');
    for (string& word: words) {
        trie.addStringToTrie(word);
    }
    string word;
    unordered_set<string> found;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(found, board, colors, trie.root, word, i, j, '*');
        }
    }
    vector<string> res;
    for (auto iter = found.begin(); iter != found.end(); iter++) {
        res.push_back(*iter);
    }
    return res;
}
