#include <bits/stdc++.h>

using namespace std;

string longestPalindromicSubstring(string str) {
    int n = str.size();
    vector<vector<bool>> memo(n, vector<bool>(n, true));
    int start = 0, end = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            memo[i][j] = (str[i] == str[j]) && memo[i+1][j-1];
            if (memo[i][j]) {
                start = i;
                end = j;
            }
        }
    }
    return str.substr(start, end - start + 1);
}
