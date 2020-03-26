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
    vector<AncestralTree *> ancestorsOne, ancestorsTwo;
    while (descendantOne) {
        ancestorsOne.push_back(descendantOne);
        descendantOne = descendantOne->ancestor;
    }
    while (descendantTwo) {
        ancestorsTwo.push_back(descendantTwo);
        descendantTwo = descendantTwo->ancestor;
    }
    int idxOne = ancestorsOne.size() - 1, idxTwo = ancestorsTwo.size() - 1;
    while (idxOne > 0 && idxTwo > 0 && ancestorsOne[idxOne - 1] == ancestorsTwo[idxTwo - 1]) {
        idxOne--;
        idxTwo--;
    }
    return ancestorsOne[idxOne];
}
