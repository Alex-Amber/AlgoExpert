#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    unordered_map<int, vector<pair<int, int>>> pair_sums;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rest = targetSum - array[i] - array[j];
            for (auto pair : pair_sums[rest]) {
                res.push_back({pair.first, pair.second, array[i], array[j]});
            }
        }
        for (int k = 0; k < i; k++) {
            int sum = array[k] + array[i];
            pair_sums[sum].push_back(make_pair(array[k], array[i]));
        }
    }
    return res;
}
