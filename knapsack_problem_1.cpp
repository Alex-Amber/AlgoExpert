#include <bits/stdc++.h>

using namespace std;

int helper(vector<vector<int>>& dp, vector<vector<int>>& items, int numItem, int capacity) {
    if (dp[numItem][capacity] >= 0) {
        return dp[numItem][capacity];
    }
    dp[numItem][capacity] = max(dp[numItem][capacity], helper(dp, items, numItem - 1, capacity));
    if (capacity >= items[numItem - 1][1]) {
        dp[numItem][capacity] = max(dp[numItem][capacity], items[numItem - 1][0] + helper(dp, items, numItem - 1, capacity - items[numItem - 1][1]));
    }
    return dp[numItem][capacity];
}

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
    int m = items.size();
    vector<vector<int>> dp(m + 1, vector<int>(capacity + 1, -1));
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= capacity; j++) {
        dp[0][j] = 0;
    }
    helper(dp, items, m, capacity);
    vector<vector<int>> result(2, vector<int>());
    result[0].push_back(dp[m][capacity]);
    int numItem = m;
    while (numItem > 0) {
        if (dp[numItem][capacity] != dp[numItem - 1][capacity]) {
            result[1].push_back(numItem - 1);
            capacity -= items[numItem - 1][1];
        }
        numItem--;
    }
    reverse(result[1].begin(), result[1].end());
    return result;
}
