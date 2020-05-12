#include <bits/stdc++.h>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left = NULL;
    BinaryTree *right = NULL;

    BinaryTree(int value);
};

pair<BinaryTree *, BinaryTree *> helper(BinaryTree *root) {
    BinaryTree *leftEnd = root, *rightEnd = root;
    if (root->left) {
        pair<BinaryTree *, BinaryTree *> leftRange = helper(root->left);
        leftRange.second->right = leftEnd;
        leftEnd->left = leftRange.second;
        leftEnd = leftRange.first;
    }
    if (root->right) {
        pair<BinaryTree *, BinaryTree *> rightRange = helper(root->right);
        rightRange.first->left = rightEnd;
        rightEnd->right = rightRange.first;
        rightEnd = rightRange.second;
    }
    return make_pair(leftEnd, rightEnd);
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
    return helper(root).first;
}
