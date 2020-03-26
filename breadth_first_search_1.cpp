#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector<string> breadthFirstSearch(vector<string> *array) {
        queue<Node *> q;
        q.push(this);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            array->push_back(cur->name);
            for (Node *child: cur->children) {
                q.push(child);
            }
        }
        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
