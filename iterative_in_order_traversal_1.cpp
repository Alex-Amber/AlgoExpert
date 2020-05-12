#include <bits/stdc++.h>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree *parent;

    BinaryTree(int value, BinaryTree *parent = NULL);
    void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree, void (*callback)(BinaryTree *tree)) {
    BinaryTree *curNode = tree, *prevNode = NULL;
    while (curNode) {
        if (prevNode == curNode->parent) {
            prevNode = curNode;
            if (curNode->left) {
                curNode = curNode->left;
            } else {
                callback(curNode);
                if (curNode->right) {
                    curNode = curNode->right;
                } else {
                    curNode = curNode->parent;
                }
            }
        } else if (prevNode == curNode->left) {
            prevNode = curNode;
            callback(curNode);
            if (curNode->right) {
                curNode = curNode->right;
            } else {
                curNode = curNode->parent;
            }
        } else {
            prevNode = curNode;
            curNode = curNode->parent;
        }
    }
    return;
}