#include <bits/stdc++.h>

using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST &insert(int val) {
        BST *cur = this, *parent = NULL;
        while (cur) {
            if (cur->value <= val) {
                parent = cur;
                cur = cur->right;
            } else {
                parent = cur;
                cur = cur->left;
            }
        }
        if (parent->value <= val) {
            parent->right = new BST(val);
        } else {
            parent->left = new BST(val);
        }
        return *this;
    }

    bool contains(int val) {
        BST *cur = this;
        while (cur) {
            if (cur->value < val) {
                cur = cur->right;
            } else if (cur->value > val) {
                cur = cur->left;
            } else {
                return true;
            }
        }
        return false;
    }

    BST &remove(int val) {
        BST *cur = this, *parent = NULL, *toRemove = NULL, *toRemoveParent = NULL;
        while (cur) {
            if (cur->value < val) {
                parent = cur;
                cur = cur->right;
            } else if (cur->value > val) {
                parent = cur;
                cur = cur->left;
            } else {
                toRemove = cur;
                toRemoveParent = parent;
                if (toRemove->left && toRemove->right) {
                    parent = cur;
                    cur = cur->right;
                    while (cur->left) {
                        parent = cur;
                        cur = cur->left;
                    }
                    int newValue = cur->value;
                    this->remove(cur->value);
                    toRemove->value = newValue;
                } else if (toRemove->left || toRemove->right) {
                    BST *toRemoveChild = toRemove->left ? toRemove->left : toRemove->right;
                    if (toRemoveParent) {
                        if (toRemoveParent->left == toRemove) {
                            toRemoveParent->left = toRemoveChild;
                        } else {
                            toRemoveParent->right = toRemoveChild;
                        }
                    } else {
                        toRemove->value = toRemoveChild->value;
                        BST *toRemoveLeftGrandChild = toRemoveChild->left, *toRemoveRightGrandChild = toRemoveChild->right;
                        toRemove->left = toRemoveLeftGrandChild;
                        toRemove->right = toRemoveRightGrandChild;
                    }
                } else {
                    if (toRemoveParent) {
                        if (toRemoveParent->left == toRemove) {
                            toRemoveParent->left = NULL;
                        } else {
                            toRemoveParent->right = NULL;
                        }
                    }
                }
                break;
            }
        }
        return *this;
    }
};