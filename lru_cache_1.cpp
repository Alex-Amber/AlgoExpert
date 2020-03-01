#include <bits/stdc++.h>

using namespace std;

struct Node {
    string key;
    int value;
    Node *next;
    Node *prev;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    int maxSize;
    unordered_map<string, Node *> table;
    Node *head;
    Node *tail;

    LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
        this->head = NULL;
        this->tail = NULL;
    }

    void insertKeyValuePair(string key, int value) {
        if (table.count(key)) {
            Node *referred = table[key];
            referred->value = value;
            setTail(referred);
        } else {
            if (table.size() == maxSize) {
                remove(head);
            }
            Node *newNode = new Node(key, value);
            setTail(newNode);
        }
    }

    int *getValueFromKey(string key) {
        if (!table.count(key)) {
            return NULL;
        }
        Node *referred = table[key];
        setTail(referred);
        return &(referred->value);
    }

    string getMostRecentKey() {
        if (head == NULL) {
            return "";
        } else {
            return tail->key;
        }
    }

    void remove(Node *node) {
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        if (nodePrev) {
            nodePrev->next = node->next;
        }
        if (nodeNext) {
            nodeNext->prev = node->prev;
        }
        if (head == node) {
            head = node->next;
        }
        if (tail == node) {
            tail = node->next;
        }
        node->prev = NULL;
        node->next = NULL;
        return;
    }

    void setTail(Node *node) {
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            if (tail != node) {
                remove(node);
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        return;
    }
};
