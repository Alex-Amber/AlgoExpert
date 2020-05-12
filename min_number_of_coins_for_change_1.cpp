#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> dp, visited;

int countCoinsForChange(vector<int>& denoms, int amount) {
    if (visited[amount]) {
        return dp[amount];
    }
    visited[amount] = 1;
    int& answer = dp[amount];
    for (int denom : denoms) {
        if (amount >= denom) {
            answer = min(answer, 1 + countCoinsForChange(denoms, amount - denom));
        }
    }
    return answer;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    dp.assign(n + 1, INF);
    visited.assign(n + 1, 0);
    dp[0] = 0;
    visited[0] = 1;
    countCoinsForChange(denoms, n);
    return dp[n] == INF ? -1 : dp[n];
}
