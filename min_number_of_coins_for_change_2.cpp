#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int denom : denoms) {
            if (i >= denom) {
                dp[i] = min(dp[i], 1 + dp[i - denom]);
            }
        }
    }
    return dp[n] == INF ? -1 : dp[n];
}
