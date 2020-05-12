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

int bfs(BinaryTree *root) {
    queue<pair<BinaryTree *, int>> q;
    int depthSum = 0;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        BinaryTree *curNode = q.front().first;
        int curDepth = q.front().second;
        q.pop();
        depthSum += curDepth;
        if (curNode->left) {
            q.push(make_pair(curNode->left, curDepth + 1));
        }
        if (curNode->right) {
            q.push(make_pair(curNode->right, curDepth + 1));
        }
    }
    return depthSum;
}

int nodeDepths(BinaryTree *root) {
    return bfs(root);
}
