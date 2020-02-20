#include <bits/stdc++.h>

using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    LinkedList *getNthNode(int n);
};

LinkedList *findLoop(LinkedList *head) {
    unordered_set<LinkedList *> nodesReached;
    LinkedList *curNode = head;
    while (true) {
        if (nodesReached.count(curNode)) {
            return curNode;
        } else {
            nodesReached.insert(curNode);
            curNode = curNode->next;
        }
    }
}
