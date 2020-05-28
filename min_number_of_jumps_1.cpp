#include <bits/stdc++.h>

using namespace std;

int minNumberOfJumps(vector<int> array) {
    int n = array.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int maxStep = array[i];
        for (int dest = i + 1; dest <= min(n - 1, i + maxStep); dest++) {
            dp[dest] = min(dp[dest], 1 + dp[i]);
        }
    }
    return dp[n - 1];
}
