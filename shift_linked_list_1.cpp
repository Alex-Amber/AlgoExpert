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

LinkedList *shiftLinkedList(LinkedList *head, int k) {
    int length = 1;
    LinkedList *cur = head;
    while (cur->next) {
        cur = cur->next;
        length++;
    }
    if (length == 1) {
        return head;
    }
    LinkedList *tail = cur;
    cur = head;
    k %= length;
    if (k == 0) {
        return head;
    } else if (k > 0) {
        k -= length;
    }
    int newHeadIdx = -k, curIdx = 0;
    LinkedList *prev = nullptr;
    while (curIdx < newHeadIdx) {
        prev = cur;
        cur = cur->next;
        curIdx++;
    }
    prev->next = nullptr;
    tail->next = head;
    return cur;
}
