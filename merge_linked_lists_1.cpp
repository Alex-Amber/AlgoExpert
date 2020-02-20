#include <bits/stdc++.h>

using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value) {
        this->value = value;
        next = NULL;
    }

    LinkedList *addMany(vector<int> values);
    vector<int> getNodesInArray();
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
    LinkedList *newHead = NULL, *destCur = NULL, *mergingCur = NULL;
    if (headOne->value < headTwo->value) {
        newHead = headOne;
        destCur = headOne;
        mergingCur = headTwo;
    } else {
        newHead = headTwo;
        destCur = headTwo;
        mergingCur = headOne;
    }
    while (mergingCur) {
        if (!destCur->next || destCur->next->value > mergingCur->value) {
            LinkedList *nodeToMerge = mergingCur;
            mergingCur = mergingCur->next;
            nodeToMerge->next = destCur->next;
            destCur->next = nodeToMerge;
        }
        destCur = destCur->next;
    }
    return newHead;
}
