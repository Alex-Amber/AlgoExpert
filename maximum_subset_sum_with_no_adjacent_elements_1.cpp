#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int maxSubsetSumNoAdjacentHelper(vector<int>& array, int idx) {
    if (idx < 0) {
        return 0;
    }
    if (dp[idx] > 0) {
        return dp[idx];
    }
    dp[idx] = max(maxSubsetSumNoAdjacentHelper(array, idx - 2) + array[idx],
                  maxSubsetSumNoAdjacentHelper(array, idx - 1));
    return dp[idx];
}

int maxSubsetSumNoAdjacent(vector<int> array) {
    dp.assign(array.size(), 0);
    return maxSubsetSumNoAdjacentHelper(array, array.size() - 1); 
}
