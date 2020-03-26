#include <bits/stdc++.h>

using namespace std;

class AncestralTree {
public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name) {
        this->name = name;
        this->ancestor = NULL;
    }

    void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
    int depthOne = 0, depthTwo = 0;
    AncestralTree *curOne = descendantOne, *curTwo = descendantTwo;
    while (curOne != topAncestor) {
        curOne = curOne->ancestor;
        depthOne++;
    }
    while (curTwo != topAncestor) {
        curTwo = curTwo->ancestor;
        depthTwo++;
    }
    int difference = abs(depthOne - depthTwo);
    curOne = depthOne <= depthTwo ? descendantOne : descendantTwo;
    curTwo = depthOne <= depthTwo ? descendantTwo : descendantOne;
    while (difference) {
        curTwo = curTwo->ancestor;
        difference--;
    }
    while (curOne != curTwo) {
        curOne = curOne->ancestor;
        curTwo = curTwo->ancestor;
    }
    return curOne;
}
