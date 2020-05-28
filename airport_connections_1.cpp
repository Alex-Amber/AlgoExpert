#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> ids;

void dfs(vector<vector<int>>& graph, int cur, vector<int>& color) {
    color[cur] = 1;
    for (int adj : graph[cur]) {
        if (color[adj] == 0) {
            dfs(graph, adj, color);
        }
    }
    color[cur] = 2;
    return;
}

int airportConnections(vector<string> airports, vector<vector<string>> routes,
                       string startingAirport) {
    int m = routes.size(), n = airports.size();
    for (int i = 0; i < n; i++) {
        ids[airports[i]] = i;
    }
    vector<vector<int>> graph(n, vector<int>());
    for (vector<string>& route : routes) {
        graph[ids[route[0]]].push_back(ids[route[1]]);
    }
    vector<int> color(n, 0);
    dfs(graph, ids[startingAirport], color);
    unordered_set<int> unreachableNodes;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            unreachableNodes.insert(i);
        }
    }
    unordered_map<int, vector<int>> reachableNodes;
    priority_queue<pair<int, int>> heap;
    for (auto iter = unreachableNodes.begin(); iter != unreachableNodes.end(); iter++) {
        color.assign(n, 0);
        dfs(graph, *iter, color);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == 2) {
                num++;
                reachableNodes[*iter].push_back(i);
            }
        }
        heap.push(make_pair(num, *iter));
    }
    int result = 0;
    while (!unreachableNodes.empty()) {
        int node = heap.top().second;
        heap.pop();
        if (unreachableNodes.count(node)) {
            result++;
            for (int adj : reachableNodes[node]) {
                if (unreachableNodes.count(adj)) {
                    unreachableNodes.erase(adj);
                }
            }
        }
    }
    return result;
}
