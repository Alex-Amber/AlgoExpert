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

int depthSum(BinaryTree *root, int depth) {
    if (!root) {
        return 0;
    }
    int leftDepthSum = depthSum(root->left, depth + 1);
    int rightDepthSum = depthSum(root->right, depth + 1);
    return leftDepthSum + rightDepthSum + depth;
}

int nodeDepths(BinaryTree *root) {
    return depthSum(root, 0);
}
