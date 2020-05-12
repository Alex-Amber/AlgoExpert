#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int countWaysToMakeChange(int total, vector<int>& denoms, int idx) {
    if (total < 0) {
        return 0;
    }
    if (idx < 0) {
        return total == 0;
    }
    if (memo[total][idx] >= 0) {
        return memo[total][idx];
    }
    int count = 0, rest = total;
    while (rest >= 0) {
        count += countWaysToMakeChange(rest, denoms, idx - 1);
        rest -= denoms[idx];
    }
    return memo[total][idx] = count;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    int m = denoms.size();
    memo.assign(n + 1, vector<int>(m, -1));
    for (int i = 0; i < m; i++) {
        memo[0][i] = 1;
    }
    return countWaysToMakeChange(n, denoms, m - 1);
}
