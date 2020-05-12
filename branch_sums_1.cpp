#include <bits/stdc++.h>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

void preOrderTraverse(vector<int>& res, BinaryTree *root, int sum) {
    sum += root->value;
    if (!root->left && !root->right) {
        res.push_back(sum);
        return;
    }
    if (root->left) {
        preOrderTraverse(res, root->left, sum);
    }
    if (root->right) {
        preOrderTraverse(res, root->right, sum);
    }
    return;
}

vector<int> branchSums(BinaryTree *root) {
    vector<int> res;
    if (root) {
        preOrderTraverse(res, root, 0);
    }
    return res;
}