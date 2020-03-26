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

bool validateBstHelper(BST *tree, vector<int>& minmax) {
    minmax.assign(2, tree->value);
    vector<int> leftMinMax, rightMinMax;
    bool leftValidity = true, rightValidity = true;
    if (tree->left) {
        leftValidity = validateBstHelper(tree->left, leftMinMax);
        minmax[0] = min(minmax[0], leftMinMax[0]);
    }
    if (tree->right) {
        rightValidity = validateBstHelper(tree->right, rightMinMax);
        minmax[1] = max(minmax[1], rightMinMax[1]);
    }
    int leftMax = leftMinMax.empty() ? INT_MIN : leftMinMax[1];
    int rightMin = rightMinMax.empty() ? INT_MAX : rightMinMax[0];
    return leftValidity && rightValidity && tree->value > leftMax && tree->value <= rightMin;
}

bool validateBst(BST *tree) {
    vector<int> minmax;
    return validateBstHelper(tree, minmax);
}