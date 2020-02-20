#include <bits/stdc++.h>

using namespace std;

struct Node {
    string key;
    Node *next;

    Node(string key, int value) {
        this->key = key;
        this->next = NULL;
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
        
    }

    int *getValueFromKey(string key) {
         
    }

    string getMostRecentKey() {

    }

    void remove(Node *node) {
        
    }

    void setTail(Node *node) {

    }
};
