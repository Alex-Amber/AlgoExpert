#include <bits/stdc++.h>

using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks, vector<string> reqs) {
    int m = blocks.size(), n = reqs.size();
    int best_idx = -1, best_dist = INT_MAX;
    for (int i = 0; i < m; i++) {
        int dist = 0;
        for (int j = 0; j < n; j++) {
            string req = reqs[j];
            int left_dist = INT_MAX, right_dist = INT_MAX, req_dist = INT_MAX;
            for (int k = 0; k <= i; k++) {
                if (blocks[k][req]) {
                    left_dist = min(left_dist, abs(k - i));
                }
            }
            for (int k = m - 1; k >= i; k--) {
                if (blocks[k][req]) {
                    right_dist = min(right_dist, abs(k - i));
                }
            }
            req_dist = min(left_dist, right_dist);
            dist = max(dist, req_dist);
        }
        if (dist < best_dist) {
            best_dist = dist;
            best_idx = i;
        }
    }
    return best_idx;
}
