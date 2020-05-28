#include <bits/stdc++.h>

using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = max(1 + dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    vector<char> result;
    int x = m, y = n;
    while (x > 0 || y > 0) {
        if (x > 0 && dp[x][y] == dp[x - 1][y]) {
            x--;
        } else if (y > 0 && dp[x][y] == dp[x][y - 1]) {
            y--; 
        } else {
            result.push_back(str1[x - 1]);
            x--;
            y--;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

