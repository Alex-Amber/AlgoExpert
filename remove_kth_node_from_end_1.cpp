#include <bits/stdc++.h>

using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

int getSizeOfLinkedList(LinkedList *head) {
    int size = 0;
    LinkedList *cur = head;
    while (cur) {
        size++;
        cur = cur->next;
    }
    return size;
}

void removeKthNodeFromEnd(LinkedList *head, int k) {
    int n = getSizeOfLinkedList(head);
    int j = n + 1 - k;
    if (j == 1) {
        head->value = head->next->value;
        LinkedList *curNode = head;
        for (int i = 1; i < n - 1; i++) {
            curNode = curNode->next;
            curNode->value = curNode->next->value;
        }
        curNode->next = NULL;
    } else {
        int nextPosition = 2;
        LinkedList *nodePrev = head;
        while (nextPosition < j) {
            nodePrev = nodePrev->next;
            nextPosition++;
        }
        LinkedList *nodeToRemove = nodePrev->next;
        nodePrev->next = nodeToRemove->next;
        nodeToRemove->next = NULL;
    }
    return;
}
