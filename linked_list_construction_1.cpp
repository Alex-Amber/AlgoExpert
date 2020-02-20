#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node *node) {
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            insertBefore(head, node);
        }
        return;
    }

    void setTail(Node *node) {
        if (tail == NULL) {
            head = node;
            tail = node;
        } else {
            insertAfter(tail, node);
        }
        return;
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        if (node == nodeToInsert) {
            return;
        }
        remove(nodeToInsert);
        Node *nodePrev = node->prev;
        if (nodePrev) {
            nodePrev->next = nodeToInsert;
            nodeToInsert->prev = nodePrev;
        } else {
            head = nodeToInsert;
        }
        nodeToInsert->next = node;
        node->prev = nodeToInsert;
        return;
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        if (node == nodeToInsert) {
            return;
        }
        remove(nodeToInsert);
        Node *nodeNext = node->next;
        if (nodeNext) {
            nodeToInsert->next = nodeNext;
            nodeNext->prev = nodeToInsert;
        } else {
            tail = nodeToInsert;
        }
        node->next = nodeToInsert;
        nodeToInsert->prev = node;
        return;
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        int curPosition = 1;
        Node *curNode = head;
        while (curPosition < position) {
            if (!curNode) {
                break;
            }
            curNode = curNode->next;
            curPosition++;
        }
        if (curNode) {
            insertBefore(curNode, nodeToInsert);
        } else {
            setTail(nodeToInsert);
        }
        return;
    }

    void removeNodesWithValue(int value) {
        Node *cur = head;
        while (cur) {
            if (cur->value == value) {
                Node *nodeToRemove = cur;
                cur = cur->next;
                remove(nodeToRemove);
            } else {
                cur = cur->next;
            }
        }
        return;
    }

    void remove(Node *node) {
        Node *nodePrev = node->prev, *nodeNext = node->next;
        if (nodePrev) {
            nodePrev->next = nodeNext;
        }
        if (nodeNext) {
            nodeNext->prev = nodePrev;
        }
        if (node == head) {
            head = nodeNext;
        }
        if (node == tail) {
            tail = nodePrev;
        }
        node->prev = NULL;
        node->next = NULL;
        return;
    }

    bool containsNodeWithValue(int value) {
        Node *cur = head;
        while (cur) {
            if (cur->value == value) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};
