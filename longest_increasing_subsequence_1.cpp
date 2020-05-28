#include <bits/stdc++.h>

using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> array) {
    int n = array.size();
    vector<int> dp(n, 1);
    vector<int> next(n, n);
    for (int i = n - 1; i >= 0; i--) {
        int maxLen = 0, maxNext = n;
        for (int j = i + 1; j < n; j++) {
            if (array[i] < array[j] && dp[j] > maxLen) {
                maxLen = dp[j];
                maxNext = j;
            }
        }
        dp[i] = 1 + maxLen;
        next[i] = maxNext;
    }
    vector<int> result;
    int cur = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    while (cur < n) {
        result.push_back(array[cur]);
        cur = next[cur];
    }
    return result;
}
