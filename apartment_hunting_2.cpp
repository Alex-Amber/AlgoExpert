#include <bits/stdc++.h>

using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks, vector<string> reqs) {
    int m = blocks.size(), n = reqs.size();
    vector<vector<int>> nearest_dist(m, vector<int>(n, INT_MAX));
    for (int j = 0; j < n; j++) {
        string req = reqs[j];
        vector<int> left_dists(m, INT_MAX);
        vector<int> right_dists(m, INT_MAX);
        for (int i = 0; i < m; i++) {
            if (blocks[i][req]) {
                left_dists[i] = 0;
            }
            else if (i > 0 && left_dists[i - 1] != INT_MAX) {
                left_dists[i] = left_dists[i - 1] + 1;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            if (blocks[i][req]) {
                right_dists[i] = 0;
            }
            else if (i < m - 1 && right_dists[i + 1] != INT_MAX) {
                right_dists[i] = right_dists[i + 1] + 1;
            }
        }
        for (int i = 0; i < m; i++) {
            nearest_dist[i][j] = min(left_dists[i], right_dists[i]);
        }
    }
    int best_idx = -1, best_dist = INT_MAX;
    for (int i = 0; i < m; i++) {
        int dist = 0;
        for (int j = 0; j < n; j++) {
            dist = max(dist, nearest_dist[i][j]);
        }
        if (dist < best_dist) {
            best_dist = dist;
            best_idx = i;
        }
    }
    return best_idx;
}
