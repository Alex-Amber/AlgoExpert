#include <bits/stdc++.h>

using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

bool validateBstHelper(BST *tree, vector<int>& range) {
    if (!tree) {
        return true;
    }
    if (tree->value < range[0] || tree->value > range[1]) {
        return false;
    }
    bool res = true;
    vector<int> leftRange({range[0], tree->value - 1}), rightRange({tree->value, range[1]});
    res = res && validateBstHelper(tree->left, leftRange);
    res = res && validateBstHelper(tree->right, rightRange);
    return res;
}

bool validateBst(BST *tree) {
    vector<int> range({INT_MIN, INT_MAX});
    return validateBstHelper(tree, range);
}