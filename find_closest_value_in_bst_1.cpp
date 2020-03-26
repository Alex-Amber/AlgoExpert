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

int findClosestValueInBst(BST *tree, int target) {
    int lower = INT_MIN, upper = INT_MAX;
    BST *cur = tree;
    while (cur) {
        if (cur->value < target) {
            lower = cur->value;
            cur = cur->right;
        } else if (cur->value > target) {
            upper = cur->value;
            cur = cur->left;
        } else {
            return target;
        }
    }
    if (abs(lower - target) < abs(upper - target)) {
        return lower;
    } else {
        return upper;
    }
}