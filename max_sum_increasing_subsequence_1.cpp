#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
    int n = array.size();
    vector<int> dp(n, 0), prev(n, -1);
    dp[0] = array[0];
    prev[0] = -1;
    for (int i = 1; i < n; i++) {
        int maxSum = 0, maxPrev = -1;
        for (int j = 0; j < i; j++) {
            if (array[j] < array[i] && dp[j] > maxSum) {
                maxSum = dp[j];
                maxPrev = j;
            }
        }
        dp[i] = array[i] + maxSum;
        prev[i] = maxPrev;
    }
    vector<vector<int>> result(2, vector<int>());
    result[0].push_back(*max_element(dp.begin(), dp.end()));
    int elemIdx = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    while (elemIdx >= 0) {
        result[1].push_back(array[elemIdx]);
        elemIdx = prev[elemIdx];
    }
    reverse(result[1].begin(), result[1].end());
    return result;
}
