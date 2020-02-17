#include <bits/stdc++.h>

using namespace std;

int minRewards(vector<int> scores) {
    int n = scores.size();
    vector<int> min_positions;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || scores[i - 1] > scores[i]) && (i == n - 1 || scores[i + 1] > scores[i])) {
            min_positions.push_back(i);
        }
    }
    vector<int> rewards(n, 0);
    for (int min_pos : min_positions) {
        rewards[min_pos] = 1;
        int left = min_pos, right = min_pos;
        while (left > 0 && scores[left - 1] > scores[left]) {
            rewards[left - 1] = max(rewards[left - 1], rewards[left] + 1);
            left--;
        }
        while (right < n - 1 && scores[right + 1] > scores[right]) {
            rewards[right + 1] = max(rewards[right + 1], rewards[right] + 1);
            right++;
        }
    }
    return accumulate(rewards.begin(), rewards.end(), 0);
}
