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

void inOrderTraverse(BinaryTree *root, vector<BinaryTree *>& flatArray) {
    if (!root) {
        return;
    }
    inOrderTraverse(root->left, flatArray);
    flatArray.push_back(root);
    inOrderTraverse(root->right, flatArray);
    return;
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
    vector<BinaryTree *> flatArray;
    inOrderTraverse(root, flatArray);
    int n = flatArray.size();
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            flatArray[i]->left = flatArray[i - 1];
        }
        if (i < n - 1) {
            flatArray[i]->right = flatArray[i + 1];
        }
    }
    return flatArray[0];
}
