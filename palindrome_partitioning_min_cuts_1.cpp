#include <bits/stdc++.h>

using namespace std;

int palindromePartitioningMinCuts(string string) {
    int n = string.size();
    vector<vector<int>> palindromeSubstring(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        int left = i, right = i;
        while (left >= 0 && right < n && string[left] == string[right]) {
            palindromeSubstring[left][right] = 1;
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && string[left] == string[right]) {
            palindromeSubstring[left][right] = 1;
            left--;
            right++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (palindromeSubstring[i][j] != 1) {
                palindromeSubstring[i][j] = 0;
            }
        }
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (palindromeSubstring[i][j]) {
                dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }
    }
    return dp[0] - 1;
}
