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
    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);
    swap(tree->left, tree->right);
    return;
}