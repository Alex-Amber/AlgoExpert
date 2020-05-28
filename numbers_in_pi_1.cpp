#include <bits/stdc++.h>

using namespace std;

int numbersInPi(string pi, vector<string> numbers) {
    unordered_set<string> nums;
    for (string& number : numbers) {
        nums.insert(number);
    }
    int n = pi.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        int count = nums.count(pi.substr(0, i + 1)) ? 1 : INT_MAX;
        for (int j = 0; j < i; j++) {
            if (dp[j] > 0 && nums.count(pi.substr(j + 1, i - j))) {
                count = min(count, 1 + dp[j]);
            }
        }
        if (count < INT_MAX) {
            dp[i] = count;
        }
    }
    return dp[n - 1] - 1;
}
