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

void bfs(BinaryTree *root) {
    queue<pair<BinaryTree *, int>> q;
    q.push(make_pair(root, 0));
    BinaryTree *lastNode = NULL;
    int lastDepth = -1;
    while (!q.empty()) {
        BinaryTree *curNode = q.front().first;
        int curDepth = q.front().second;
        q.pop();
        if (!curNode) {
            lastNode = curNode;
            lastDepth = curDepth;
            continue;
        }
        q.push(make_pair(curNode->left, curDepth + 1));
        q.push(make_pair(curNode->right, curDepth + 1));
        curNode->right = NULL;
        if (lastDepth == curDepth && lastNode) {
            lastNode->right = curNode;
        }
        lastNode = curNode;
        lastDepth = curDepth;
    }
    return;
}

BinaryTree *rightSiblingTree(BinaryTree *root) {
    bfs(root);
    return root;
}
