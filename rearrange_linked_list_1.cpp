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
};

LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
    LinkedList *smallerAnchor = new LinkedList(0);
    LinkedList *equalAnchor = new LinkedList(0);
    LinkedList *greaterAnchor = new LinkedList(0);
    LinkedList *smallerCur = smallerAnchor, *equalCur = equalAnchor, *greaterCur = greaterAnchor;
    LinkedList *cur = head;
    while (cur) {
        LinkedList *temp = cur;
        cur = cur->next;
        temp->next = nullptr;
        if (temp->value < k) {
            smallerCur->next = temp;
            smallerCur = smallerCur->next;
        } else if (temp->value > k) {
            greaterCur->next = temp;
            greaterCur = greaterCur->next;
        } else {
            equalCur->next = temp;
            equalCur = equalCur->next;
        }
    }
    LinkedList *anchor = new LinkedList(0);
    cur = anchor;
    if (smallerAnchor->next) {
        cur->next = smallerAnchor->next;
        cur = smallerCur;
    }
    if (equalAnchor->next) {
        cur->next = equalAnchor->next;
        cur = equalCur;
    }
    if (greaterAnchor->next) {
        cur->next = greaterAnchor->next;
        cur = greaterCur;
    }
    LinkedList *result = anchor->next;
    delete(smallerAnchor);
    delete(equalAnchor);
    delete(greaterAnchor);
    delete(anchor);
    return result;
}
