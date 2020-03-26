#include <bits/stdc++.h>

using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> inDegrees;
    for (int job: jobs) {
        adjList[job] = vector<int>();
        inDegrees[job] = 0;
    }
    for (auto& dep: deps) {
        adjList[dep[0]].push_back(dep[1]);
        inDegrees[dep[1]]++;
    }
    queue<int> q;
    for (auto iter = inDegrees.begin(); iter != inDegrees.end(); iter++) {
        if (iter->second == 0) {
            q.push(iter->first);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (int adj: adjList[cur]) {
            inDegrees[adj]--;
            if (inDegrees[adj] == 0) {
                q.push(adj);
            }
        }
    }
    if (res.size() == jobs.size()) {
        return res;
    } else {
        return vector<int>();
    }
}
