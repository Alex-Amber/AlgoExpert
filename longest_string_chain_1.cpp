#include <bits/stdc++.h>

using namespace std;

bool compare(const string& str1, const string& str2) {
    return str1.size() >= str2.size();
}

vector<string> longestStringChain(vector<string> strings) {
    int n = strings.size();
    sort(strings.begin(), strings.end(), compare);
    unordered_map<string, int> idxes;
    for (int i = 0; i < n; i++) {
        idxes[strings[i]] = i;
    }
    vector<int> dp(n, 1);
    vector<int> next(n, n);
    for (int i = n - 1; i >= 0; i--) {
        int len = strings[i].size();
        int maxLen = 0, maxNext = n;
        for (int j = 0; j < len; j++) {
            string next = (j > 0 ? strings[i].substr(0, j) : "") + (j < n - 1 ? strings[i].substr(j + 1, n - j - 1) : "");
            if (idxes.count(next) && dp[idxes[next]] > maxLen) {
                maxLen = dp[idxes[next]];
                maxNext = idxes[next];
            }
        }
        dp[i] = 1 + maxLen;
        next[i] = maxNext;
    }
    vector<string> result;
    int cur = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    while (cur < n) {
        result.push_back(strings[cur]);
        cur = next[cur];
    }
    return result.size() > 1 ? result : vector<string>();
}
