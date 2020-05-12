#include <bits/stdc++.h>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

pair<int, int> maxPathSumHelper(BinaryTree *tree) {
    if (!tree) {
        return make_pair(0, 0);
    }
    pair<int, int> leftResult = maxPathSumHelper(tree->left);
    pair<int, int> rightResult = maxPathSumHelper(tree->right);
    int leftMaxPathSum = leftResult.first, leftMaxBranchSum = leftResult.second;
    int rightMaxPathSum = rightResult.first, rightMaxBranchSum = rightResult.second;
    int maxPathSum = max(tree->value + (leftMaxBranchSum > 0 ? leftMaxBranchSum : 0) + (rightMaxBranchSum > 0 ? rightMaxBranchSum : 0), 
                         max(leftMaxPathSum, rightMaxPathSum));
    int maxBranchSum = max(tree->value + max(leftMaxBranchSum, rightMaxBranchSum),
                           tree->value);
    return make_pair(maxPathSum, maxBranchSum);
}

int maxPathSum(BinaryTree tree) {
    return maxPathSumHelper(&tree).first;
}