#include <bits/stdc++.h>

using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, INT_MIN)));
    for (int j = 0; j <= k; j++) {
        dp[n][j][0] = 0;
        dp[n][j][1] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = max(-prices[i] + dp[i + 1][j][1], dp[i + 1][j][0]);
            dp[i][j][1] = max(prices[i] + dp[i + 1][j - 1][0], dp[i + 1][j][1]);
        }
    }
    return dp[0][k][0];
}
