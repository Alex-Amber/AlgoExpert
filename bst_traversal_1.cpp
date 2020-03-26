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

void inOrderTraverseHelper(BST *tree, vector<int>& array) {
    if (!tree) {
        return;
    }
    inOrderTraverseHelper(tree->left, array);
    array.push_back(tree->value);
    inOrderTraverseHelper(tree->right, array);
    return;
}

vector<int> inOrderTraverse(BST *tree, vector<int> array) {
    inOrderTraverseHelper(tree, array);
    return array;
}

void preOrderTraverseHelper(BST *tree, vector<int>& array) {
    if (!tree) {
        return;
    }
    array.push_back(tree->value);
    preOrderTraverseHelper(tree->left, array);
    preOrderTraverseHelper(tree->right, array);
    return;
}

vector<int> preOrderTraverse(BST *tree, vector<int> array) {
    preOrderTraverseHelper(tree, array);
    return array;
}

void postOrderTraverseHelper(BST *tree, vector<int>& array) {
    if (!tree) {
        return;
    }
    postOrderTraverseHelper(tree->left, array);
    postOrderTraverseHelper(tree->right, array);
    array.push_back(tree->value);
    return;
}

vector<int> postOrderTraverse(BST *tree, vector<int> array) {
    postOrderTraverseHelper(tree, array);
    return array;
}