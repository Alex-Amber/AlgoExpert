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
    int res = INT_MIN;
    BST *cur = tree;
    while (cur) {
        if (abs(cur->value - target) < abs(res - target)) {
            res = cur->value;
        }
        if (cur->value < target) {
            cur = cur->right;
        } else if (cur->value > target) {
            cur = cur->left;
        } else {
            break;
        }
    }
    return res;
}