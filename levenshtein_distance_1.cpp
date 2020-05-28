#include <bits/stdc++.h>

using namespace std;

int levenshteinDistance(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = min(dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
            } else {
                dp[i][j] = min(1 + dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
            }
        }
    }
    return dp[m][n];
}
