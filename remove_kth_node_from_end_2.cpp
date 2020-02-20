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

void removeKthNodeFromEnd(LinkedList *head, int k) {
    LinkedList *first = head, *second = head;
    for (int i = 0; i < k; i++) {
        second = second->next;
    }
    if (!second) {
        head->value = head->next->value;
        LinkedList *temp = head->next;
        head->next = head->next->next;
        temp->next = NULL;
        return;
    }
    while (second->next) {
        first = first->next;
        second = second->next;
    }
    LinkedList *temp = first->next;
    first->next = first->next->next;
    temp->next = NULL;
    return;
}
