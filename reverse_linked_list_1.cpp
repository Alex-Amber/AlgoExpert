#include <bits/stdc++.h>

using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value) { this->value = value; }
};

LinkedList *reverseLinkedList(LinkedList *head) {
    LinkedList *firstNode = NULL, *secondNode = head;
    while (secondNode) {
        LinkedList *nextNode = secondNode->next;
        secondNode->next = firstNode;
        firstNode = secondNode;
        secondNode = nextNode;
    }
    return firstNode;
}
