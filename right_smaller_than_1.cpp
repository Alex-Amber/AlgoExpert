#include <bits/stdc++.h>

using namespace std;

class BST {
public:
    int value;
    int numLeftChildren;
    BST *left;
    BST *right;

    BST(int value) {
        this->value = value;
        numLeftChildren = 0;
        left = NULL;
        right = NULL;
    }

    int insert(int value) {
        if (this->value > value) {
            numLeftChildren++;
            if (left) {
                return left->insert(value); 
            } else {
                left = new BST(value);
                return 0;
            }
        } else {
            if (right) {
                return (int)(this->value < value) + numLeftChildren + right->insert(value);
            } else {
                right = new BST(value);
                return (int)(this->value < value) + numLeftChildren;
            }
        }
    }
};

vector<int> rightSmallerThan(vector<int> array) {
    if (array.empty()) {
        return {};
    }
    int n = array.size();
    vector<int> result(n, 0);
    BST *root = new BST(array[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        result[i] = root->insert(array[i]);
    }
    return result;
}
