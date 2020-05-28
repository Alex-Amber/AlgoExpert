#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
    int n = disks.size();
    sort(disks.begin(), disks.end());
    vector<int> dp(n + 1, 0);
    vector<int> next(n + 1, n);
    disks.push_back({INT_MAX, INT_MAX, INT_MAX});
    for (int i = n - 1; i >= 0; i--) {
        int maxHeight = 0, maxNext = n;
        for (int j = i + 1; j < n; j++) {
            if (disks[i][0] < disks[j][0] && disks[i][1] < disks[j][1] && disks[i][2] < disks[j][2] && dp[j] > maxHeight) {
                maxHeight = dp[j];
                maxNext = j;
            }
        }
        dp[i] = disks[i][2] + maxHeight;
        next[i] = maxNext;
    }
    vector<vector<int>> result;
    int diskIdx = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    while (diskIdx < n) {
        result.push_back(disks[diskIdx]);
        diskIdx = next[diskIdx];
    }
    return result;
}
