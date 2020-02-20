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
    LinkedList *firstNode = head, *secondNode = head;
    do {
        firstNode = firstNode->next;
        secondNode = secondNode->next->next;
    } while (firstNode != secondNode);
    firstNode = head;
    while (firstNode != secondNode) {
        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }
    return firstNode;
}
