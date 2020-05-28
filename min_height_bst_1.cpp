#include <bits/stdc++.h>

using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }

    void insert(int value) {
        if (value < this->value) {
            if (left == NULL) {
                left = new BST(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == NULL) {
                right = new BST(value);
            } else {
                right->insert(value);
            }
        }
        return;
    }
};

BST *helper(const vector<int>& array, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int rootPos = start + (end - start) / 2;
    BST *root = new BST(array[rootPos]);
    root->left = helper(array, start, rootPos - 1);
    root->right = helper(array, rootPos + 1, end);
    return root;
}

BST *minHeightBst(vector<int> array) {
    return helper(array, 0, array.size() - 1);
}
