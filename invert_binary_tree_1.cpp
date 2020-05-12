#include <bits/stdc++.h>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
    if (!tree) {
        return;
    }
    queue<BinaryTree *> q;
    q.push(tree);
    while (!q.empty()) {
        BinaryTree *root = q.front();
        q.pop();
        swap(root->left, root->right);
        if (root->left) {
            q.push(root->left);
        }
        if (root->right) {
            q.push(root->right);
        }
    }
    return;
}