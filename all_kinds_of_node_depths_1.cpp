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

pair<int, int> postOrderTraverse(BinaryTree *root, int& sum, int depth) {
    if (!root) {
        return make_pair(0, 0);
    }
    if (!root->left && !root->right) {
        return make_pair(depth, 1);
    }
    pair<int, int> leftResult = postOrderTraverse(root->left, sum, depth + 1);
    pair<int, int> rightResult = postOrderTraverse(root->right, sum, depth + 1);
    int depthSum = leftResult.first + rightResult.first + depth;
    int numNodes = leftResult.second + rightResult.second + 1;
    sum += depthSum - numNodes * depth;
    return make_pair(depthSum, numNodes);
}

int allKindsOfNodeDepths(BinaryTree *root) {
    int result = 0;
    postOrderTraverse(root, result, 0);
    return result;
}
